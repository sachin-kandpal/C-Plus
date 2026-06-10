/*
=============================================================
  PROBLEM : Single Number I
  Platform : TUF+ / LeetCode #136
  Sheet    : Striver A2Z DSA (Arrays - Easy)

  Every number appears twice except one. Find that one.

  Example:
    nums = [1, 2, 2, 4, 3, 1, 4]  →  Output: 3
    nums = [5]                     →  Output: 5

  NOTE: Using raw array for VS Code (fixed size input).
        Judge uses vector<int>& as per platform signature.

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ single_number.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;


// =============================================================
// METHOD 1 — BRUTE FORCE
// Time : O(N*N)   Space: O(1)
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

int singleNumberBrute(int nums[], int n) {
    for(int i = 0;i<n;i++){
        int num = nums[i];
        int count = 0;
        for(int j = 0;j<n;j++){
            if(nums[j]==num){
                count++;
            }
            

        }
        if(count == 1){
            return num;
        }
    }
    return -1;
}

int main() {
    int nums[] = {1, 2, 2, 4, 3, 1, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "===== BRUTE FORCE =====" << endl;
    cout << "Input : [1, 2, 2, 4, 3, 1, 4]" << endl;
    cout << "Single Number : " << singleNumberBrute(nums, n) << endl;

    return 0;
}


// =============================================================
// METHOD 2 — BETTER (HashMap)
// Idea : Count frequency of each element using unordered_map
//        Return the element whose count == 1
// Time : O(N)   Space: O(N)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
int singleNumberBetter(int nums[], int n) {
    unordered_map<int, int> freq;      // freq[x] = how many times x appears

    for (int i = 0; i < n; i++)
        freq[nums[i]]++;               // count each element

    for (auto& p : freq)
        if (p.second == 1)             // found the element with count 1
            return p.first;

    return -1;
}

int main() {
    int nums[] = {1, 2, 2, 4, 3, 1, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "===== BETTER (HashMap) =====" << endl;
    cout << "Input : [1, 2, 2, 4, 3, 1, 4]" << endl;
    cout << "Single Number : " << singleNumberBetter(nums, n) << endl;

    return 0;
}
*/


// =============================================================
// METHOD 3 — OPTIMAL (XOR)  <- SUBMIT THIS
// Idea : a ^ a = 0  (pairs cancel out)
//        a ^ 0 = a  (single survives)
//        XOR all elements → answer is what remains
// Time : O(N)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
int singleNumberOptimal(int nums[], int n) {
    int xorAll = 0;                    // start with 0 (identity for XOR)

    for (int i = 0; i < n; i++)
        xorAll ^= nums[i];             // every pair cancels, single survives

    return xorAll;                     // what's left is the single number
}

int main() {
    int nums[] = {1, 2, 2, 4, 3, 1, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "===== OPTIMAL (XOR) =====" << endl;
    cout << "Input : [1, 2, 2, 4, 3, 1, 4]" << endl;
    cout << "Single Number : " << singleNumberOptimal(nums, n) << endl;

    // edge cases
    int e1[] = {5};
    cout << "Single element → " << singleNumberOptimal(e1, 1) << endl;  // 5

    int e2[] = {7, 3, 3};
    cout << "First is single → " << singleNumberOptimal(e2, 3) << endl; // 7

    int e3[] = {2, 2, 9};
    cout << "Last is single  → " << singleNumberOptimal(e3, 3) << endl; // 9

    return 0;
}
*/


// =============================================================
// JUDGE CODE — LeetCode #136 / TUF+
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorAll = 0;

        for (int x : nums)
            xorAll ^= x;      // pairs cancel, single survives

        return xorAll;
    }
};
*/