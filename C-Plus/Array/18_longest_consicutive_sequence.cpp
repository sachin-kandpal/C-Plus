/*
=============================================================
  PROBLEM : Longest Consecutive Sequence
  Platform : TUF+ / LeetCode #128 (Medium)
  Sheet    : Striver A2Z DSA (Arrays - Medium)

  Find length of longest sequence of consecutive integers.
  Elements can be in any order. Duplicates may exist.

  Example:
    nums = [100, 4, 200, 1, 3, 2]  →  4  (sequence: 1,2,3,4)
    nums = [0,3,7,2,5,8,4,6,0,1]  →  9  (sequence: 0,1,2,3,4,5,6,7,8)
    nums = [1,9,3,10,4,20,2]      →  4  (sequence: 1,2,3,4)
    nums = []                      →  0

  NOTE: Raw array in VS Code (fixed known input).
        Judge uses vector<int>& per platform signature.

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ longest_consecutive_sequence.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;


// =============================================================
// METHOD 1 — BRUTE FORCE
// Idea : For each element x, search for x+1, x+2... in array
//        Track max streak length
// Time : O(N^3)   Space: O(1)
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

// helper: check if 'val' exists in array
bool linearSearch(int nums[], int n, int val) {
    for (int i = 0; i < n; i++)
        if (nums[i] == val) return true;
    return false;
}

int longestBrute(int nums[], int n) {
    if (n == 0) return 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        int x = nums[i];
        int streak = 1;

        // keep searching for x+1, x+2, x+3 ...
        while (linearSearch(nums, n, x + 1)) {
            x++;                       // found x+1, now look for x+2
            streak++;
        }
        maxLen = max(maxLen, streak);
    }
    return maxLen;
}

int main() {
    int nums[] = {100, 4, 200, 1, 3, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "===== BRUTE FORCE =====" << endl;
    cout << "Input  : [100, 4, 200, 1, 3, 2]" << endl;
    cout << "Longest Consecutive : " << longestBrute(nums, n) << endl; // 4

    int e1[] = {1, 9, 3, 10, 4, 20, 2};
    cout << "Now your turn       : "
         << longestBrute(e1, 7) << endl;   // 4

    return 0;
}


// =============================================================
// METHOD 2 — BETTER (Sorting)
// Idea : Sort array → consecutive elements become adjacent
//        Walk through, count streaks, reset on gap
//        Skip duplicates (nums[i] == nums[i-1])
// Time : O(N log N)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
int longestBetter(int nums[], int n) {
    if (n == 0) return 0;

    sort(nums, nums + n);              // sort: [1,2,3,4,100,200]

    int maxLen = 1;
    int streak = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1])
            continue;                  // duplicate → skip (don't reset)

        if (nums[i] == nums[i - 1] + 1)
            streak++;                  // consecutive → extend streak
        else
            streak = 1;                // gap → reset streak

        maxLen = max(maxLen, streak);
    }
    return maxLen;
}

int main() {
    int nums[] = {100, 4, 200, 1, 3, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "===== BETTER (Sorting) =====" << endl;
    cout << "Input  : [100, 4, 200, 1, 3, 2]" << endl;
    cout << "Longest Consecutive : " << longestBetter(nums, n) << endl; // 4

    int e1[] = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "With duplicates     : "
         << longestBetter(e1, 10) << endl;  // 9

    return 0;
}
*/


// =============================================================
// METHOD 3 — OPTIMAL (HashSet)  <- SUBMIT THIS
//
// Key insight:
//   Only start counting from the BEGINNING of a sequence
//   Start of sequence = element x where (x-1) is NOT in set
//
//   If x-1 exists → x is middle of some sequence → skip
//   If x-1 absent → x is the start → count x, x+1, x+2 ...
//
// Why O(N)?
//   Each element is touched at most TWICE:
//     Once as a potential start (O(1) check via set)
//     Once when counted inside a sequence
//   Total = O(2N) = O(N)
//
// Time : O(N)   Space: O(N)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
int longestOptimal(int nums[], int n) {
    if (n == 0) return 0;

    unordered_set<int> st(nums, nums + n);  // insert all elements into set
    int maxLen = 0;

    for (int x : st) {                      // iterate over set (no duplicates)

        // only process if x is the START of a sequence
        if (st.find(x - 1) == st.end()) {   // x-1 not in set → x is a start

            int curNum = x;
            int streak = 1;

            // count consecutive elements from x
            while (st.count(curNum + 1)) {   // is next element in set?
                curNum++;
                streak++;
            }

            maxLen = max(maxLen, streak);
        }
        // if x-1 exists in set → x is NOT a start → skip entirely
    }
    return maxLen;
}

int main() {
    int nums[] = {100, 4, 200, 1, 3, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "===== OPTIMAL (HashSet) =====" << endl;
    cout << "Input  : [100, 4, 200, 1, 3, 2]" << endl;
    cout << "Longest : " << longestOptimal(nums, n) << endl;  // 4

    int e1[] = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "With duplicates [0,3,7,2,5,8,4,6,0,1] : "
         << longestOptimal(e1, 10) << endl;  // 9

    int e2[] = {1, 9, 3, 10, 4, 20, 2};
    cout << "Now your turn [1,9,3,10,4,20,2]       : "
         << longestOptimal(e2, 7) << endl;   // 4

    int e3[] = {1};
    cout << "Single element [1]                    : "
         << longestOptimal(e3, 1) << endl;   // 1

    return 0;
}
*/


// =============================================================
// JUDGE CODE — LeetCode #128 / TUF+
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> st(nums.begin(), nums.end());
        int maxLen = 0;

        for (int x : st) {
            if (st.find(x - 1) == st.end()) {  // x is a sequence start

                int curNum = x, streak = 1;

                while (st.count(curNum + 1)) {  // count the full sequence
                    curNum++;
                    streak++;
                }
                maxLen = max(maxLen, streak);
            }
        }
        return maxLen;
    }
};
*/