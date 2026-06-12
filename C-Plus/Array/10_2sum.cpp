/*
=============================================================
  PROBLEM : Two Sum
  Platform : LeetCode #1 (Easy)
  Sheet    : Striver A2Z DSA (Arrays - Easy)

  Find two indices i, j such that nums[i] + nums[j] = target.
  Exactly one solution exists. Cannot use same index twice.

  Example:
    nums=[2,7,11,15], target=9  →  Output: [0,1]
    nums=[3,2,4],     target=6  →  Output: [1,2]
    nums=[3,3],       target=6  →  Output: [0,1]

  NOTE: Output is a pair of indices → vector<int> used for
        return type (size 2, dynamic return from function).
        Input array uses raw array in VS Code version.

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ two_sum.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;


// =============================================================
// METHOD 1 — BRUTE FORCE
// Idea : Check every pair (i, j) where j > i
//        If nums[i] + nums[j] == target → return {i, j}
// Time : O(N^2)   Space: O(1)
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

vector<int> twoSumBrute(int nums[], int n, int target) {
    for (int i = 0; i < n; i++) {             // pick first element
        for (int j = i + 1; j < n; j++) {     // pick second element (always after i)
            if (nums[i] + nums[j] == target)  // pair found!
                return {i, j};
        }
    }
    return {-1, -1};   // no answer (problem guarantees this won't happen)
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int n = sizeof(nums) / sizeof(nums[0]);   
    int target = 9;

    cout << "===== BRUTE FORCE =====" << endl;
    cout << "Input : [2, 7, 11, 15],  target = 9" << endl;

    vector<int> ans = twoSumBrute(nums, n, target);
    cout << "Output : [" << ans[0] << ", " << ans[1] << "]" << endl;

    // test: same value twice
    int nums2[] = {3, 3};
    vector<int> ans2 = twoSumBrute(nums2, 2, 6);
    cout << "[3,3] target=6 → [" << ans2[0] << ", " << ans2[1] << "]" << endl;

    return 0;
}


// =============================================================
// METHOD 2 — OPTIMAL (HashMap)  <- SUBMIT THIS
// Idea : For each nums[i], compute complement = target - nums[i]
//        If complement already in map → found the pair!
//        Else store nums[i] and its index in map
//
// Why not update existing keys?
//   Not needed here — problem guarantees exactly one solution
//   and we return immediately when found
//
// Time : O(N)   Space: O(N)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
vector<int> twoSumOptimal(int nums[], int n, int target) {
    unordered_map<int, int> seen;  // seen[value] = index

    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];   // what we need to find

        if (seen.count(complement))          // complement already seen!
            return {seen[complement], i};    // return both indices

        seen[nums[i]] = i;                   // store current element
    }
    return {-1, -1};
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 9;

    cout << "===== OPTIMAL (HashMap) =====" << endl;
    cout << "Input : [2, 7, 11, 15],  target = 9" << endl;

    vector<int> ans = twoSumOptimal(nums, n, target);
    cout << "Output : [" << ans[0] << ", " << ans[1] << "]" << endl;

    // test 2
    int n2[] = {3, 2, 4};
    vector<int> a2 = twoSumOptimal(n2, 3, 6);
    cout << "[3,2,4] target=6 → [" << a2[0] << ", " << a2[1] << "]" << endl;

    // test 3: same value
    int n3[] = {3, 3};
    vector<int> a3 = twoSumOptimal(n3, 2, 6);
    cout << "[3,3]   target=6 → [" << a3[0] << ", " << a3[1] << "]" << endl;

    return 0;
}
*/


// =============================================================
// JUDGE CODE — LeetCode #1
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;   // value → index

        for (int i = 0; i < (int)nums.size(); i++) {
            int complement = target - nums[i];  // need this value

            if (seen.count(complement))          // found complement!
                return {seen[complement], i};

            seen[nums[i]] = i;                   // store for future lookups
        }
        return {-1, -1};  // never reached
    }
};
*/