/*
=============================================================
  PROBLEM : Maximum Consecutive Ones
  Platform : TUF+ / LeetCode #485
  Sheet    : Striver A2Z DSA (Arrays - Easy)

  Given a binary array (only 0s and 1s),
  return the maximum number of consecutive 1s.

  Example:
    nums = [1, 1, 0, 0, 1, 1, 1, 0]  →  Output: 3
    nums = [0, 0, 0, 0, 0]           →  Output: 0

  NOTE: Using raw array here since input is fixed size binary
        array — no dynamic sizing needed.

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ maximum_consecutive_ones.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;


// =============================================================
// METHOD 1 — BRUTE FORCE
// Idea : For every index i, count consecutive 1s from i
//        Update max each time
// Time : O(N^2)   Space: O(1)
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

int maxConsecutiveBrute(int nums[], int n) {
    int maxCnt = 0;                       // stores final answer

    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {               // only start counting from a 1
            int cnt = 0;
            int j = i;

            while (j < n && nums[j] == 1) { // count streak from index i
                cnt++;
                j++;
            }

            maxCnt = max(maxCnt, cnt);    // update max if this streak is bigger
        }
    }
    return maxCnt;
}

int main() {
    int nums[] = {1, 1, 0, 0, 1, 1, 1, 0};
    int n = sizeof(nums) / sizeof(nums[0]);  // calculate array size

    cout << "===== BRUTE FORCE =====" << endl;
    cout << "Input : [1, 1, 0, 0, 1, 1, 1, 0]" << endl;
    cout << "Max Consecutive Ones : " << maxConsecutiveBrute(nums, n) << endl;

    return 0;
}


// =============================================================
// METHOD 2 — OPTIMAL (Single Pass Counter)  <- SUBMIT THIS
// Idea : Walk once, keep live counter cnt
//        nums[i]==1 → cnt++
//        nums[i]==0 → reset cnt=0
//        At every step → maxCnt = max(maxCnt, cnt)
// Time : O(N)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
int maxConsecutiveOptimal(int nums[], int n) {
    int cnt = 0;                          // current streak of 1s
    int maxCnt = 0;                       // best streak seen so far

    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {
            cnt++;                        // extend current streak
        } else {
            cnt = 0;                      // 0 breaks the streak, reset
        }
        maxCnt = max(maxCnt, cnt);        // update max at every step
    }
    return maxCnt;
}

int main() {
    int nums[] = {1, 1, 0, 0, 1, 1, 1, 0};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "===== OPTIMAL (Single Pass) =====" << endl;
    cout << "Input : [1, 1, 0, 0, 1, 1, 1, 0]" << endl;
    cout << "Max Consecutive Ones : " << maxConsecutiveOptimal(nums, n) << endl;

    // extra test cases
    int e1[] = {0, 0, 0, 0};
    cout << "All zeros  → " << maxConsecutiveOptimal(e1, 4) << endl;  // 0

    int e2[] = {1, 1, 1, 1};
    cout << "All ones   → " << maxConsecutiveOptimal(e2, 4) << endl;  // 4

    int e3[] = {1};
    cout << "Single one → " << maxConsecutiveOptimal(e3, 1) << endl;  // 1

    return 0;
}
*/


// =============================================================
// JUDGE CODE — LeetCode #485 / TUF+
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, maxCnt = 0;

        for (int x : nums) {
            if (x == 1)
                cnt++;               // keep growing streak
            else
                cnt = 0;             // reset on 0

            maxCnt = max(maxCnt, cnt);  // track best
        }
        return maxCnt;
    }
};
*/