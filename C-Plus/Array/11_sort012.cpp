/*
=============================================================
  PROBLEM : Sort an Array of 0s, 1s and 2s
  Platform : TUF+ / LeetCode #75
  Sheet    : Striver A2Z DSA (Arrays - Easy)

  Sort array containing only 0s, 1s, 2s in-place.
  No extra array. Classic Dutch National Flag problem.

  Example:
    nums = [1, 0, 2, 1, 0]  →  [0, 0, 1, 1, 2]
    nums = [0, 0, 1, 1, 1]  →  [0, 0, 1, 1, 1]

  NOTE: Raw array in VS Code (fixed known input).
        Judge uses vector<int>& per platform signature.

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ sort_0s_1s_2s.cpp -o out && ./out
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
// METHOD 1 — BRUTE FORCE (built-in sort)
// Idea : Just use sort() — ignores the 3-value constraint
// Time : O(N log N)   Space: O(1)
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

void sortBrute(int nums[], int n) {
    sort(nums, nums + n);   // STL sort, works on any array
}

int main() {
    int nums[] = {1, 0, 2, 1, 0};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "===== BRUTE FORCE (sort) =====" << endl;
    cout << "Input  : "; printArr(nums, n);
    sortBrute(nums, n);
    cout << "Output : "; printArr(nums, n);

    return 0;
}


// =============================================================
// METHOD 2 — BETTER (Counting)
// Idea : Count 0s, 1s, 2s → overwrite array in two passes
// Time : O(2N)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
void sortBetter(int nums[], int n) {
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    // Pass 1: count each value
    for (int i = 0; i < n; i++) {
        if      (nums[i] == 0) cnt0++;
        else if (nums[i] == 1) cnt1++;
        else                   cnt2++;
    }

    // Pass 2: overwrite array with counts
    int i = 0;
    while (cnt0--) nums[i++] = 0;   // fill 0s first
    while (cnt1--) nums[i++] = 1;   // then 1s
    while (cnt2--) nums[i++] = 2;   // then 2s
}

int main() {
    int nums[] = {1, 0, 2, 1, 0};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "===== BETTER (Counting) =====" << endl;
    cout << "Input  : "; printArr(nums, n);
    sortBetter(nums, n);
    cout << "Output : "; printArr(nums, n);

    return 0;
}
*/


// =============================================================
// METHOD 3 — OPTIMAL (Dutch National Flag)  <- SUBMIT THIS
//
// 3 Pointers: low, mid, high
//
//   [0..low-1]   → all 0s (sorted zone)
//   [low..mid-1] → all 1s (sorted zone)
//   [mid..high]  → unknown (work zone)
//   [high+1..n]  → all 2s (sorted zone)
//
// At each step look at nums[mid]:
//   == 0 → swap(mid, low), low++, mid++
//   == 1 → mid++  (already correct position)
//   == 2 → swap(mid, high), high--  (mid stays! element from high is unknown)
//
// Stop when mid > high (no unknown zone left)
//
// Time : O(N)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
void sortOptimal(int nums[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {           // process until unknown zone is empty

        if (nums[mid] == 0) {
            swap(nums[mid], nums[low]);  // 0 belongs at low end
            low++;                       // expand 0s zone
            mid++;                       // this element is now placed
        }
        else if (nums[mid] == 1) {
            mid++;                       // 1 is already in right place
        }
        else {                           // nums[mid] == 2
            swap(nums[mid], nums[high]); // 2 belongs at high end
            high--;                      // expand 2s zone
            // DO NOT mid++ → swapped element from high is still unknown!
        }
    }
}

int main() {
    int nums[] = {1, 0, 2, 1, 0};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "===== OPTIMAL (Dutch National Flag) =====" << endl;
    cout << "Input  : "; printArr(nums, n);
    sortOptimal(nums, n);
    cout << "Output : "; printArr(nums, n);

    // edge cases
    int e1[] = {0, 0, 0};
    sortOptimal(e1, 3);
    cout << "All 0s : "; printArr(e1, 3);

    int e2[] = {2, 2, 2};
    sortOptimal(e2, 3);
    cout << "All 2s : "; printArr(e2, 3);

    int e3[] = {2, 0, 1};
    sortOptimal(e3, 3);
    cout << "[2,0,1]: "; printArr(e3, 3);

    return 0;
}
*/


// =============================================================
// JUDGE CODE — LeetCode #75 / TUF+
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++; mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;          // mid NOT incremented here
            }
        }
    }
};
*/