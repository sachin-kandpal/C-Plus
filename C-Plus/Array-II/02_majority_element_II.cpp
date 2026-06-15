/*
=============================================================
  PROBLEM : Majority Element II
  Platform : LeetCode #229 (Medium)
  Sheet    : Striver A2Z DSA (Arrays - Medium)

  Find ALL elements appearing MORE THAN n/3 times.
  At most 2 such elements can exist (mathematical fact).

  Example:
    [3,2,3]           →  [3]
    [1]               →  [1]
    [1,2]             →  [1,2]
    [1,2,3]           →  []
    [1,1,1,3,3,2,2,2] →  [1,2]

  NOTE: Raw array in VS Code. Judge uses vector<int>&.

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ majority_element_2.cpp -o out && ./out
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
// Idea : For every element, count its frequency
//        If freq > n/3 and not already added → add to result
// Time : O(N^2)   Space: O(1) excluding output
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

vector<int> majorityBrute(int nums[], int n) {
    vector<int> result;

    for (int i = 0; i < n; i++) {
        // only check if not already in result (avoid duplicates)
        bool alreadyAdded = false;
        for (int x : result)
            if (x == nums[i]) { alreadyAdded = true; break; }

        if (alreadyAdded) continue;

        int count = 0;
        for (int j = 0; j < n; j++)       // count frequency
            if (nums[j] == nums[i]) count++;

        if (count > n / 3)                 // majority II condition
            result.push_back(nums[i]);
    }
    return result;
}

int main() {
    cout << "===== BRUTE FORCE =====" << endl;

    int a1[] = {3, 2, 3};
    vector<int> r1 = majorityBrute(a1, 3);
    cout << "[3,2,3]           → "; printVec(r1);   // [3]

    int a2[] = {1, 2};
    vector<int> r2 = majorityBrute(a2, 2);
    cout << "[1,2]             → "; printVec(r2);   // [1,2]

    int a3[] = {1, 2, 3};
    vector<int> r3 = majorityBrute(a3, 3);
    cout << "[1,2,3]           → "; printVec(r3);   // []

    int a4[] = {1,1,1,3,3,2,2,2};
    vector<int> r4 = majorityBrute(a4, 8);
    cout << "[1,1,1,3,3,2,2,2] → "; printVec(r4);  // [1,2]

    return 0;
}


// =============================================================
// METHOD 2 — BETTER (HashMap)
// Idea : Count frequency of each element
//        Return elements with freq > n/3
// Time : O(N)   Space: O(N)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
vector<int> majorityBetter(int nums[], int n) {
    unordered_map<int, int> freq;
    vector<int> result;

    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;

        // add to result immediately when threshold crossed
        // (check not already added to avoid duplicates)
        if (freq[nums[i]] == n / 3 + 1) {   // just crossed n/3
            result.push_back(nums[i]);
        }

        if (result.size() == 2) break;       // at most 2 answers
    }
    return result;
}

int main() {
    cout << "===== BETTER (HashMap) =====" << endl;

    int a1[] = {3, 2, 3};
    vector<int> r1 = majorityBetter(a1, 3);
    cout << "[3,2,3]           → "; printVec(r1);   // [3]

    int a2[] = {1, 2};
    vector<int> r2 = majorityBetter(a2, 2);
    cout << "[1,2]             → "; printVec(r2);   // [1,2]

    int a3[] = {1, 2, 3};
    vector<int> r3 = majorityBetter(a3, 3);
    cout << "[1,2,3]           → "; printVec(r3);   // []

    int a4[] = {1,1,1,3,3,2,2,2};
    vector<int> r4 = majorityBetter(a4, 8);
    cout << "[1,1,1,3,3,2,2,2] → "; printVec(r4);  // [1,2]

    return 0;
}
*/


// =============================================================
// METHOD 3 — OPTIMAL (Extended Boyer-Moore Voting)
//
// KEY MATH: at most 2 elements can appear > n/3 times
//           → maintain exactly 2 candidates with 2 counts
//
// PASS 1 — Find candidates:
//   if nums[i] == cand1 → cnt1++
//   if nums[i] == cand2 → cnt2++
//   if cnt1 == 0 → cand1 = nums[i], cnt1 = 1
//   if cnt2 == 0 → cand2 = nums[i], cnt2 = 1
//   else → cnt1--, cnt2--  (cancel both candidates)
//
// PASS 2 — Verify (MANDATORY — no guarantee they exist):
//   Count actual frequency of cand1 and cand2
//   Add to result only if freq > n/3
//
// WHY cnt1-- and cnt2-- together?
//   Each cancellation removes one occurrence of cand1,
//   one of cand2, and one of nums[i] → 3 elements cancel
//   True majority (> n/3) survives all cancellations
//
// Time : O(N)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
vector<int> majorityOptimal(int nums[], int n) {
    int cand1 = INT_MIN, cnt1 = 0;   // candidate 1 + its count
    int cand2 = INT_MIN, cnt2 = 0;   // candidate 2 + its count

    // ── Pass 1: Find 2 potential candidates ──────────────────
    for (int i = 0; i < n; i++) {

        if (nums[i] == cand1) {
            cnt1++;                   // support candidate 1
        }
        else if (nums[i] == cand2) {
            cnt2++;                   // support candidate 2
        }
        else if (cnt1 == 0) {
            cand1 = nums[i];          // elect new candidate 1
            cnt1 = 1;
        }
        else if (cnt2 == 0) {
            cand2 = nums[i];          // elect new candidate 2
            cnt2 = 1;
        }
        else {
            cnt1--;                   // cancel: one vote vs cand1
            cnt2--;                   // cancel: one vote vs cand2
        }
    }

    // ── Pass 2: Verify actual frequency ──────────────────────
    int freq1 = 0, freq2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == cand1) freq1++;
        if (nums[i] == cand2) freq2++;
    }

    vector<int> result;
    if (freq1 > n / 3) result.push_back(cand1);
    if (freq2 > n / 3) result.push_back(cand2);

    return result;
}

int main() {
    cout << "===== OPTIMAL (Extended Boyer-Moore) =====" << endl;

    int a1[] = {3, 2, 3};
    vector<int> r1 = majorityOptimal(a1, 3);
    cout << "[3,2,3]            → "; printVec(r1);  // [3]

    int a2[] = {1, 2};
    vector<int> r2 = majorityOptimal(a2, 2);
    cout << "[1,2]              → "; printVec(r2);  // [1,2]

    int a3[] = {1, 2, 3};
    vector<int> r3 = majorityOptimal(a3, 3);
    cout << "[1,2,3]            → "; printVec(r3);  // []

    int a4[] = {1,1,1,3,3,2,2,2};
    vector<int> r4 = majorityOptimal(a4, 8);
    cout << "[1,1,1,3,3,2,2,2]  → "; printVec(r4); // [1,2]

    int a5[] = {1};
    vector<int> r5 = majorityOptimal(a5, 1);
    cout << "[1]                → "; printVec(r5);  // [1]

    return 0;
}
*/


// =============================================================
// JUDGE CODE — LeetCode #229
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cand1 = INT_MIN, cnt1 = 0;
        int cand2 = INT_MIN, cnt2 = 0;

        // Pass 1: find candidates
        for (int x : nums) {
            if      (x == cand1) cnt1++;
            else if (x == cand2) cnt2++;
            else if (cnt1 == 0)  { cand1 = x; cnt1 = 1; }
            else if (cnt2 == 0)  { cand2 = x; cnt2 = 1; }
            else                 { cnt1--; cnt2--; }
        }

        // Pass 2: verify
        int freq1 = 0, freq2 = 0;
        for (int x : nums) {
            if (x == cand1) freq1++;
            if (x == cand2) freq2++;
        }

        vector<int> result;
        if (freq1 > n / 3) result.push_back(cand1);
        if (freq2 > n / 3) result.push_back(cand2);
        return result;
    }
};
*/