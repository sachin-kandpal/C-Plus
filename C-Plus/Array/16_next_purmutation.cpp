/*
=============================================================
  PROBLEM : Next Permutation
  Platform : TUF+ / LeetCode #31 (Medium)
  Sheet    : Striver A2Z DSA (Arrays - Medium)

  Find the next lexicographically greater permutation.
  If already the largest → return the smallest (sorted asc).
  Must be done IN-PLACE with O(1) extra space.

  Example:
    [1,2,3] → [1,3,2]
    [3,2,1] → [1,2,3]   (last perm → wrap to first)
    [2,3,1] → [3,1,2]
    [1,1,5] → [1,5,1]

  NOTE: Raw array in VS Code (fixed known input).
        Judge uses vector<int>& per platform signature.

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ next_permutation.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++)
        cout << arr[i] << (i < n-1 ? ", " : "");
    cout << "]" << endl;
}


// =============================================================
// METHOD 1 — BRUTE FORCE (STL next_permutation)
// Idea : Use C++ built-in next_permutation()
//        Good to know it exists but NOT the expected answer
// Time : O(N)   Space: O(1)
// NOTE : STL handles it internally using the same 4-step logic
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

void nextPermBrute(int nums[], int n) {
    // STL next_permutation does everything for us
    // Returns false if it was the last permutation (wraps to first)
    next_permutation(nums, nums + n);
}

int main() {
    cout << "===== BRUTE (STL next_permutation) =====" << endl;

    int a1[] = {1, 2, 3};
    cout << "Input  : "; printArr(a1, 3);
    nextPermBrute(a1, 3);
    cout << "Output : "; printArr(a1, 3);   // [1, 3, 2]
    cout << endl;

    int a2[] = {3, 2, 1};
    cout << "Input  : "; printArr(a2, 3);
    nextPermBrute(a2, 3);
    cout << "Output : "; printArr(a2, 3);   // [1, 2, 3]
    cout << endl;

    int a3[] = {2, 3, 1};
    cout << "Input  : "; printArr(a3, 3);
    nextPermBrute(a3, 3);
    cout << "Output : "; printArr(a3, 3);   // [3, 1, 2]

    return 0;
}


// =============================================================
// METHOD 2 — OPTIMAL (4-Step Algorithm)  <- SUBMIT THIS
//
// THE 4 STEPS:
//
// Step 1 — Find BREAK POINT:
//   Scan right to left, find 'ind' where nums[ind] < nums[ind+1]
//   (rightmost position where sequence goes UP from left to right)
//
// Step 2 — If NO break point:
//   Array is fully descending = LAST permutation
//   Reverse entire array to get smallest permutation → done
//
// Step 3 — Find SWAP ELEMENT:
//   Scan right to left from end
//   Find first element > nums[ind] → swap with nums[ind]
//   (smallest element to the right of ind that's still > nums[ind])
//
// Step 4 — Reverse SUFFIX:
//   Reverse everything after index 'ind'
//   Suffix was descending → reversing makes it ascending
//   Ascending = smallest arrangement = closest next permutation
//
// Time : O(N)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
void nextPermOptimal(int nums[], int n) {

    // ── Step 1: Find break point ──────────────────────────────
    int ind = -1;
    for (int i = n - 2; i >= 0; i--) {   // scan right to left
        if (nums[i] < nums[i + 1]) {      // found the dip!
            ind = i;
            break;
        }
    }

    // ── Step 2: No break point → last permutation ────────────
    if (ind == -1) {
        reverse(nums, nums + n);           // reverse all → get smallest
        return;
    }

    // ── Step 3: Find element just greater than nums[ind] ─────
    for (int i = n - 1; i > ind; i--) {   // scan from right
        if (nums[i] > nums[ind]) {         // first element > nums[ind]
            swap(nums[i], nums[ind]);      // swap it with break point
            break;
        }
    }

    // ── Step 4: Reverse suffix after ind ─────────────────────
    reverse(nums + ind + 1, nums + n);    // sort suffix ascending
}

int main() {
    cout << "===== OPTIMAL (4-Step Algorithm) =====" << endl;

    int a1[] = {1, 2, 3};
    cout << "Input  : "; printArr(a1, 3);
    nextPermOptimal(a1, 3);
    cout << "Output : "; printArr(a1, 3);   // [1, 3, 2]
    cout << endl;

    int a2[] = {3, 2, 1};
    cout << "Input  : "; printArr(a2, 3);
    nextPermOptimal(a2, 3);
    cout << "Output : "; printArr(a2, 3);   // [1, 2, 3]
    cout << endl;

    int a3[] = {2, 3, 1};
    cout << "Input  : "; printArr(a3, 3);
    nextPermOptimal(a3, 3);
    cout << "Output : "; printArr(a3, 3);   // [3, 1, 2]
    cout << endl;

    int a4[] = {1, 1, 5};
    cout << "Input  : "; printArr(a4, 3);
    nextPermOptimal(a4, 3);
    cout << "Output : "; printArr(a4, 3);   // [1, 5, 1]
    cout << endl;

    int a5[] = {1, 3, 2};
    cout << "Input  : "; printArr(a5, 3);
    nextPermOptimal(a5, 3);
    cout << "Output : "; printArr(a5, 3);   // [2, 1, 3]

    return 0;
}
*/


// =============================================================
// JUDGE CODE — LeetCode #31 / TUF+
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;

        // Step 1: find break point
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // Step 2: last permutation → reverse all
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: swap with just-greater element from right
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Step 4: reverse suffix to get smallest arrangement
        reverse(nums.begin() + ind + 1, nums.end());
    }
};
*/