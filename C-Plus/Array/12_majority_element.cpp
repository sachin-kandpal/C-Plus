/*
=============================================================
  PROBLEM : Majority Element I
  Platform : TUF+ / LeetCode #169 (Easy)
  Sheet    : Striver A2Z DSA (Arrays - Easy)

  Find element appearing more than n/2 times.
  Guaranteed to always exist.

  Example:
    nums = [7,0,0,1,7,7,2,7,7]  →  Output: 7
    nums = [1,1,1,2,1]          →  Output: 1
    nums = [-1,-1,-1,-1]        →  Output: -1

  NOTE: Raw array in VS Code (fixed input).
        Judge uses vector<int>& per platform signature.

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ majority_element.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;


// =============================================================
// METHOD 1 — BRUTE FORCE
// Idea : For every element, count its frequency in full array
//        If count > n/2 → return it
// Time : O(N^2)   Space: O(1)
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

int majorityBrute(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {     // count frequency of nums[i]
            if (nums[j] == nums[i])
                count++;
        }

        if (count > n / 2)                 // majority condition
            return nums[i];
    }
    return -1;   // never reached (problem guarantees majority exists)
}

int main() {
    int nums[] = {7, 0, 0, 1, 7, 7, 2, 7, 7};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "===== BRUTE FORCE =====" << endl;
    cout << "Input  : [7, 0, 0, 1, 7, 7, 2, 7, 7]" << endl;
    cout << "Majority Element : " << majorityBrute(nums, n) << endl;

    return 0;
}


// =============================================================
// METHOD 2 — BETTER (HashMap)
// Idea : Count frequency of each element using map
//        Return element whose frequency > n/2
// Time : O(N)   Space: O(N)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
int majorityBetter(int nums[], int n) {
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;               // count frequency

        if (freq[nums[i]] > n / 2)     // check immediately (early exit)
            return nums[i];
    }
    return -1;
}

int main() {
    int nums[] = {7, 0, 0, 1, 7, 7, 2, 7, 7};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "===== BETTER (HashMap) =====" << endl;
    cout << "Input  : [7, 0, 0, 1, 7, 7, 2, 7, 7]" << endl;
    cout << "Majority Element : " << majorityBetter(nums, n) << endl;

    return 0;
}
*/


// =============================================================
// METHOD 3 — OPTIMAL (Boyer-Moore Voting)  <- SUBMIT THIS
//
// Two variables:
//   candidate → current potential majority element
//   count     → net "votes" for candidate
//
// Rules:
//   count == 0       → pick new candidate (nums[i])
//   nums[i]==candidate → count++  (support)
//   nums[i]!=candidate → count--  (cancel)
//
// Why it works:
//   Majority has > n/2 votes
//   Even after all non-majority elements cancel majority votes,
//   majority still has remaining votes → survives as final candidate
//
// Time : O(N)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
int majorityOptimal(int nums[], int n) {
    int candidate = 0;   // current leader
    int count = 0;       // net votes for leader

    for (int i = 0; i < n; i++) {
        if (count == 0)
            candidate = nums[i];       // dethrone old, pick new candidate

        if (nums[i] == candidate)
            count++;                   // vote for current leader
        else
            count--;                   // cancel one vote
    }

    return candidate;   // guaranteed to be majority (problem states it exists)
}

int main() {
    int nums[] = {7, 0, 0, 1, 7, 7, 2, 7, 7};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "===== OPTIMAL (Boyer-Moore Voting) =====" << endl;
    cout << "Input  : [7, 0, 0, 1, 7, 7, 2, 7, 7]" << endl;
    cout << "Majority Element : " << majorityOptimal(nums, n) << endl;

    // edge cases
    int e1[] = {1};
    cout << "Single element [1]     → " << majorityOptimal(e1, 1) << endl; // 1

    int e2[] = {-1, -1, -1, -1};
    cout << "All same [-1,-1,-1,-1] → " << majorityOptimal(e2, 4) << endl; // -1

    int e3[] = {1, 1, 2, 1, 2, 1, 1};
    cout << "[1,1,2,1,2,1,1]        → " << majorityOptimal(e3, 7) << endl; // 1

    return 0;
}
*/


// =============================================================
// JUDGE CODE — LeetCode #169 / TUF+
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;

        for (int x : nums) {
            if (count == 0)
                candidate = x;         // pick new candidate

            if (x == candidate)
                count++;               // support
            else
                count--;               // cancel
        }
        return candidate;
    }
};
*/