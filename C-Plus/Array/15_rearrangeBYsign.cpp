/*
=============================================================
  PROBLEM : Rearrange Array Elements by Sign
  Platform : TUF+ / LeetCode #2149 (Medium)
  Sheet    : Striver A2Z DSA (Arrays - Medium)

  Equal positives and negatives. Interleave alternately.
  Start with positive. Preserve relative order of each sign.

  Example:
    nums = [2, 4, 5, -1, -3, -4]  →  [2, -1, 4, -3, 5, -4]
    nums = [1, -1, -3, -4, 2, 3]  →  [1, -1, 2, -3, 3, -4]

  NOTE: Output is a new array → vector used for result.
        Input uses vector<int>& as per judge signature.

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ rearrange_by_sign.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++)
        cout << v[i] << (i < (int)v.size()-1 ? ", " : "");
    cout << "]" << endl;
}


// =============================================================
// METHOD 1 — BRUTE FORCE
// Idea : Separate into pos[] and neg[] arrays
//        Then interleave them into result
// Time : O(N)   Space: O(N)
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

vector<int> rearrangeBrute(vector<int>& nums) {
    int n = nums.size();
    vector<int> pos, neg;

    // Pass 1: separate positives and negatives
    for (int x : nums) {
        if (x > 0) pos.push_back(x);   // collect positives in order
        else        neg.push_back(x);   // collect negatives in order
    }

    // Pass 2: interleave into result
    vector<int> result(n);
    for (int i = 0; i < n / 2; i++) {
        result[2 * i]     = pos[i];     // even index → positive
        result[2 * i + 1] = neg[i];     // odd index  → negative
    }
    return result;
}

int main() {
    vector<int> nums = {2, 4, 5, -1, -3, -4};

    cout << "===== BRUTE FORCE =====" << endl;
    cout << "Input  : "; printVec(nums);

    vector<int> result = rearrangeBrute(nums);
    cout << "Output : "; printVec(result);

    vector<int> nums2 = {1, -1, -3, -4, 2, 3};
    cout << "Input  : "; printVec(nums2);
    vector<int> r2 = rearrangeBrute(nums2);
    cout << "Output : "; printVec(r2);

    return 0;
}


// =============================================================
// METHOD 2 — OPTIMAL (Two Pointer into Result)  <- SUBMIT THIS
//
// Idea : posIdx=0 (even slots), negIdx=1 (odd slots)
//        Single pass through nums:
//          positive → place at posIdx, posIdx += 2
//          negative → place at negIdx, negIdx += 2
//
// Why this works:
//   Even indices 0,2,4,... hold positives (starts with pos ✅)
//   Odd  indices 1,3,5,... hold negatives (alternates ✅)
//   We scan left to right → relative order preserved ✅
//
// Time : O(N)   Space: O(N) — result array
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
vector<int> rearrangeOptimal(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);          // output array

    int posIdx = 0;                 // next available even index (for +ve)
    int negIdx = 1;                 // next available odd  index (for -ve)

    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            result[posIdx] = nums[i];   // place positive at even slot
            posIdx += 2;                // jump to next even slot
        } else {
            result[negIdx] = nums[i];   // place negative at odd slot
            negIdx += 2;                // jump to next odd slot
        }
    }
    return result;
}

int main() {
    vector<int> nums = {2, 4, 5, -1, -3, -4};

    cout << "===== OPTIMAL (Two Pointer) =====" << endl;
    cout << "Input  : "; printVec(nums);

    vector<int> result = rearrangeOptimal(nums);
    cout << "Output : "; printVec(result);

    vector<int> nums2 = {1, -1, -3, -4, 2, 3};
    cout << "Input  : "; printVec(nums2);
    vector<int> r2 = rearrangeOptimal(nums2);
    cout << "Output : "; printVec(r2);

    // single pair
    vector<int> nums3 = {-1, 1};
    cout << "[-1, 1]: "; 
    vector<int> r3 = rearrangeOptimal(nums3);
    printVec(r3);                       // [1, -1]

    return 0;
}
*/


// =============================================================
// JUDGE CODE — LeetCode #2149 / TUF+
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int posIdx = 0;   // next even slot
        int negIdx = 1;   // next odd slot

        for (int x : nums) {
            if (x > 0) {
                result[posIdx] = x;
                posIdx += 2;
            } else {
                result[negIdx] = x;
                negIdx += 2;
            }
        }
        return result;
    }
};
*/