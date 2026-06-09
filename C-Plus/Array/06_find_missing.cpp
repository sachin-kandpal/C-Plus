/*
=============================================================
  PROBLEM : Find Missing Number
  Platform : TUF+ / LeetCode #268
  Sheet    : Striver A2Z DSA (Arrays - Easy)

  Given array of size n with distinct values in range [0,n]
  Find the one missing number.

  Example:
    nums = [0, 2, 3, 1, 4]  n=5  →  Output: 5
    nums = [0, 1, 2, 4, 5, 6] n=6 → Output: 3

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ find_missing_number.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;


// =============================================================
// METHOD 1 — BRUTE FORCE
// Idea : For every number 0 to n, search if it's in array
//        If not found → that's the missing number
// Time : O(N^2)   Space: O(1)
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

int missingBrute(vector<int>& nums, int n) {
    for (int i = 0; i <= n; i++) {          // check each number 0 to n
        bool found = false;
        for (int j = 0; j < n; j++) {       // search i in array
            if (nums[j] == i) {
                found = true;
                break;                      // found it, no need to search more
            }
        }
        if (!found) return i;               // not found = missing number
    }
    return -1;
}

int main() {
    vector<int> nums = {0, 2, 3, 1, 4};
    int n = nums.size();                    // n = 5, range is [0,5]

    cout << "===== BRUTE FORCE =====" << endl;
    cout << "Input : [0, 2, 3, 1, 4]" << endl;
    cout << "Missing Number : " << missingBrute(nums, n) << endl;

    return 0;
}


// =============================================================
// METHOD 2 — BETTER (Hashing)
// Idea : Mark which numbers exist in a hash array
//        The index that stays 0 is the missing number
// Time : O(N)   Space: O(N)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
int missingBetter(vector<int>& nums, int n) {
    vector<int> hash(n + 1, 0);    // hash[i] = 1 means i is present

    for (int i = 0; i < n; i++)
        hash[nums[i]] = 1;         // mark this number as present

    for (int i = 0; i <= n; i++)
        if (hash[i] == 0)          // this index was never marked
            return i;              // so i is the missing number

    return -1;
}

int main() {
    vector<int> nums = {0, 2, 3, 1, 4};
    int n = nums.size();

    cout << "===== BETTER (Hashing) =====" << endl;
    cout << "Input : [0, 2, 3, 1, 4]" << endl;
    cout << "Missing Number : " << missingBetter(nums, n) << endl;

    return 0;
}
*/


// =============================================================
// METHOD 3 — OPTIMAL 1 (Sum Formula)  <- SUBMIT THIS
// Idea : Expected sum of 0..n = n*(n+1)/2
//        Missing = Expected sum - Actual sum
// Time : O(N)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
int missingSum(vector<int>& nums, int n) {
    int expectedSum = n * (n + 1) / 2;  // sum of 0 to n

    int actualSum = 0;
    for (int x : nums)
        actualSum += x;                 // sum of given array

    return expectedSum - actualSum;     // the difference is missing number
}

int main() {
    vector<int> nums = {0, 2, 3, 1, 4};
    int n = nums.size();

    cout << "===== OPTIMAL 1 (Sum Formula) =====" << endl;
    cout << "Input : [0, 2, 3, 1, 4]" << endl;
    cout << "Missing Number : " << missingSum(nums, n) << endl;

    return 0;
}
*/


// =============================================================
// METHOD 4 — OPTIMAL 2 (XOR)  <- ALSO GREAT FOR INTERVIEWS
// Idea : XOR of same numbers cancel out (a^a = 0)
//        XOR all indices 0..n with all values
//        Only the missing number has no pair → survives
// Time : O(N)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
int missingXOR(vector<int>& nums, int n) {
    int xorAll = 0;

    // XOR all numbers from 0 to n (expected full range)
    for (int i = 0; i <= n; i++)
        xorAll ^= i;

    // XOR all values in the array (actual present numbers)
    for (int x : nums)
        xorAll ^= x;

    // All present numbers cancel (a^a=0), only missing survives
    return xorAll;
}

int main() {
    vector<int> nums = {0, 2, 3, 1, 4};
    int n = nums.size();

    cout << "===== OPTIMAL 2 (XOR) =====" << endl;
    cout << "Input : [0, 2, 3, 1, 4]" << endl;
    cout << "Missing Number : " << missingXOR(nums, n) << endl;

    return 0;
}
*/


// =============================================================
// JUDGE CODE — LeetCode #268 / TUF+
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;  // sum formula

        int actualSum = 0;
        for (int x : nums) actualSum += x;

        return expectedSum - actualSum;      // missing = difference
    }
};
*/