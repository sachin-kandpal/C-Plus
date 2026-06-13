/*
=============================================================
  PROBLEM : Kadane's Algorithm (Maximum Subarray Sum)
  Platform : TUF+ / LeetCode #53 (Medium)
  Sheet    : Striver A2Z DSA (Arrays - Medium)

  Find the contiguous subarray with the largest sum.
  Return that sum. Array can have negatives.

  Example:
    nums = [2, 3, 5, -2, 7, -4]    →  Output: 15
    nums = [-2,-3,-7,-2,-10,-4]    →  Output: -2
    nums = [-1, 2, 3, -1, 2,-6, 5] →  Output: 6

  NOTE: Raw array in VS Code (fixed input).
        Judge uses vector<int>& per platform signature.

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ kadanes_algorithm.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;


// =============================================================
// METHOD 1 — BRUTE FORCE
// Idea : Check every subarray [i..j]
//        Keep running sum, update maxSum
// Time : O(N^2)   Space: O(1)
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

int maxSubarrayBrute(int nums[], int n) {
    int maxSum = INT_MIN;               // handles all-negative arrays

    for (int i = 0; i < n; i++) {      // start of subarray
        int curSum = 0;

        for (int j = i; j < n; j++) {  // end of subarray
            curSum += nums[j];          // extend subarray to j

            maxSum = max(maxSum, curSum); // update max if better
        }
    }
    return maxSum;
}

int main() {
    int nums[] = {2, 3, 5, -2, 7, -4};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "===== BRUTE FORCE =====" << endl;
    cout << "Input  : [2, 3, 5, -2, 7, -4]" << endl;
    cout << "Max Subarray Sum : " << maxSubarrayBrute(nums, n) << endl;

    // all negatives
    int e1[] = {-2, -3, -7, -2, -10, -4};
    cout << "All negatives    : " << maxSubarrayBrute(e1, 6) << endl; // -2

    return 0;
}


// =============================================================
// METHOD 2 — OPTIMAL (Kadane's Algorithm)  <- SUBMIT THIS
//
// Key rule:
//   If currentSum goes negative → it is a BURDEN
//   Reset currentSum = 0 and start fresh
//   (negative prefix only drags down future sums)
//
// At every index:
//   currentSum += nums[i]
//   maxSum = max(maxSum, currentSum)
//   if currentSum < 0 → reset to 0
//
// Works for all-negative arrays too because:
//   maxSum is updated BEFORE reset → catches least negative element
//
// Time : O(N)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
int maxSubarrayKadane(int nums[], int n) {
    int curSum = 0;
    int maxSum = INT_MIN;              // INT_MIN handles all-negative case

    for (int i = 0; i < n; i++) {
        curSum += nums[i];             // extend current subarray

        maxSum = max(maxSum, curSum);  // update max BEFORE potential reset

        if (curSum < 0)
            curSum = 0;                // negative prefix is a burden → reset
    }
    return maxSum;
}

int main() {
    int nums[] = {2, 3, 5, -2, 7, -4};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "===== OPTIMAL (Kadane's Algorithm) =====" << endl;
    cout << "Input  : [2, 3, 5, -2, 7, -4]" << endl;
    cout << "Max Subarray Sum : " << maxSubarrayKadane(nums, n) << endl;

    // all negatives
    int e1[] = {-2, -3, -7, -2, -10, -4};
    cout << "All negatives        : " << maxSubarrayKadane(e1, 6) << endl; // -2

    // single element
    int e2[] = {5};
    cout << "Single element [5]   : " << maxSubarrayKadane(e2, 1) << endl; // 5

    // now your turn test
    int e3[] = {-1, 2, 3, -1, 2, -6, 5};
    cout << "[-1,2,3,-1,2,-6,5]  : " << maxSubarrayKadane(e3, 7) << endl; // 6

    return 0;
}
*/


// =============================================================
// BONUS — OPTIMAL WITH SUBARRAY INDICES
// Same Kadane's but also tracks START and END index
// Useful when interviewer asks "return the subarray itself"
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
int maxSubarrayWithIndices(int nums[], int n) {
    int curSum = 0, maxSum = INT_MIN;
    int start = 0, ansStart = 0, ansEnd = 0;  // track indices

    for (int i = 0; i < n; i++) {
        curSum += nums[i];

        if (curSum > maxSum) {
            maxSum   = curSum;
            ansStart = start;   // subarray starts at 'start'
            ansEnd   = i;       // ends at current index
        }

        if (curSum < 0) {
            curSum = 0;
            start  = i + 1;     // new subarray starts from next index
        }
    }

    cout << "Subarray: [";
    for (int i = ansStart; i <= ansEnd; i++)
        cout << nums[i] << (i < ansEnd ? ", " : "");
    cout << "]" << endl;

    return maxSum;
}

int main() {
    int nums[] = {2, 3, 5, -2, 7, -4};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "===== OPTIMAL WITH INDICES =====" << endl;
    cout << "Input  : [2, 3, 5, -2, 7, -4]" << endl;
    cout << "Max Subarray Sum : " << maxSubarrayWithIndices(nums, n) << endl;

    return 0;
}
*/


// =============================================================
// JUDGE CODE — LeetCode #53 / TUF+
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int maxSum = INT_MIN;

        for (int x : nums) {
            curSum += x;                   // extend subarray

            maxSum = max(maxSum, curSum);  // update max before reset

            if (curSum < 0)
                curSum = 0;               // discard negative prefix
        }
        return maxSum;
    }
};
*/