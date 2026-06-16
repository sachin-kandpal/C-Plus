/*
=============================================================
  PROBLEM : 4Sum
  Platform : LeetCode #18 (Medium)
  Sheet    : Striver A2Z DSA (Arrays - Medium)

  Find all unique quadruplets summing to target.
  No duplicate quadruplets in output.

  Example:
    [1,0,-1,0,-2,2], target=0 → [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
    [2,2,2,2,2],     target=8 → [[2,2,2,2]]

  KEY: Use long long for sum — values up to 10^9, 4 of them
       can overflow int!

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ four_sum.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;

void printResult(vector<vector<int>>& res) {
    if (res.empty()) { cout << "[]" << endl; return; }
    cout << "[";
    for (int i = 0; i < (int)res.size(); i++) {
        cout << "[" << res[i][0] << "," << res[i][1]
             << "," << res[i][2] << "," << res[i][3] << "]";
        if (i < (int)res.size()-1) cout << ", ";
    }
    cout << "]" << endl;
}


// =============================================================
// METHOD 1 — BRUTE FORCE
// Idea : 4 nested loops, try every quadruplet
//        Sort each → insert into set<vector<int>> for dedup
// Time : O(N^4 log N)   Space: O(unique quadruplets)
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

vector<vector<int>> fourSumBrute(int nums[], int n, int target) {
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            for (int k = j+1; k < n; k++)
                for (int l = k+1; l < n; l++)
                    if ((long long)nums[i]+nums[j]+nums[k]+nums[l] == target) {
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }

    return vector<vector<int>>(st.begin(), st.end());
}

int main() {
    cout << "===== BRUTE FORCE =====" << endl;

    int a1[] = {1,0,-1,0,-2,2};
    vector<vector<int>> r1 = fourSumBrute(a1, 6, 0);
    cout << "[1,0,-1,0,-2,2] target=0 → "; printResult(r1);

    int a2[] = {2,2,2,2,2};
    vector<vector<int>> r2 = fourSumBrute(a2, 5, 8);
    cout << "[2,2,2,2,2]     target=8 → "; printResult(r2);

    return 0;
}


// =============================================================
// METHOD 2 — BETTER (HashSet)
// Idea : Fix i and j (two loops)
//        For each k, compute fourth = target-(i+j+k)
//        Search fourth in hashset of elements seen so far
//        Use set<vector<int>> to deduplicate output
// Time : O(N^3 log N)   Space: O(N)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
vector<vector<int>> fourSumBetter(int nums[], int n, int target) {
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            set<long long> hashset;          // elements seen between j and k

            for (int k = j+1; k < n; k++) {
                long long fourth = (long long)target - nums[i] - nums[j] - nums[k];

                if (hashset.count(fourth)) { // found the fourth element!
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);     // add k for future iterations
            }
        }
    }
    return vector<vector<int>>(st.begin(), st.end());
}

int main() {
    cout << "===== BETTER (HashSet) =====" << endl;

    int a1[] = {1,0,-1,0,-2,2};
    vector<vector<int>> r1 = fourSumBetter(a1, 6, 0);
    cout << "[1,0,-1,0,-2,2] target=0 → "; printResult(r1);

    int a2[] = {2,2,2,2,2};
    vector<vector<int>> r2 = fourSumBetter(a2, 5, 8);
    cout << "[2,2,2,2,2]     target=8 → "; printResult(r2);

    return 0;
}
*/


// =============================================================
// METHOD 3 — OPTIMAL (Sort + Two Outer Loops + Two Pointers)
//
// Pattern: 4Sum = 3Sum with one extra outer loop
//          3Sum = 2Sum (two pointers) with one extra outer loop
//
// Sort first → duplicates adjacent → easy to skip
//
// i  = first element  (loop 0 to n-4)
// j  = second element (loop i+1 to n-3)
// k  = left pointer   (starts at j+1)
// l  = right pointer  (starts at n-1)
//
// Duplicate skipping (3 levels):
//   i: if i>0 && nums[i]==nums[i-1] → skip
//   j: if j>i+1 && nums[j]==nums[j-1] → skip
//   k,l: after adding triplet, skip while same value
//
// CRITICAL: Use long long for sum to prevent overflow!
//
// Time : O(N^3)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
vector<vector<int>> fourSumOptimal(int nums[], int n, long long target) {
    sort(nums, nums + n);
    vector<vector<int>> ans;

    for (int i = 0; i < n-3; i++) {

        // skip duplicate i
        if (i > 0 && nums[i] == nums[i-1]) continue;

        for (int j = i+1; j < n-2; j++) {

            // skip duplicate j (note: j > i+1 not j > 0)
            if (j > i+1 && nums[j] == nums[j-1]) continue;

            int k = j+1;      // left pointer
            int l = n-1;      // right pointer

            while (k < l) {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                if (sum < target) {
                    k++;               // sum too small → increase left
                }
                else if (sum > target) {
                    l--;               // sum too big → decrease right
                }
                else {                 // found a valid quadruplet!
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++; l--;

                    // skip duplicate k
                    while (k < l && nums[k] == nums[k-1]) k++;
                    // skip duplicate l
                    while (k < l && nums[l] == nums[l+1]) l--;
                }
            }
        }
    }
    return ans;
}

int main() {
    cout << "===== OPTIMAL (Sort + Two Pointers) =====" << endl;

    int a1[] = {1,0,-1,0,-2,2};
    vector<vector<int>> r1 = fourSumOptimal(a1, 6, 0);
    cout << "[1,0,-1,0,-2,2] target=0 → "; printResult(r1);

    int a2[] = {2,2,2,2,2};
    vector<vector<int>> r2 = fourSumOptimal(a2, 5, 8);
    cout << "[2,2,2,2,2]     target=8 → "; printResult(r2);

    int a3[] = {0,0,0,0};
    vector<vector<int>> r3 = fourSumOptimal(a3, 4, 0);
    cout << "[0,0,0,0]       target=0 → "; printResult(r3);

    int a4[] = {-3,-2,-1,0,0,1,2,3};
    vector<vector<int>> r4 = fourSumOptimal(a4, 8, 0);
    cout << "[-3,-2,-1,0,0,1,2,3] t=0 → "; printResult(r4);

    return 0;
}
*/


// =============================================================
// JUDGE CODE — LeetCode #18
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n-3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;  // skip dup i

            for (int j = i+1; j < n-2; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue; // skip dup j

                int k = j+1, l = n-1;

                while (k < l) {
                    long long sum = (long long)nums[i]+nums[j]+nums[k]+nums[l];

                    if      (sum < target) k++;
                    else if (sum > target) l--;
                    else {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++; l--;
                        while (k < l && nums[k] == nums[k-1]) k++; // dup k
                        while (k < l && nums[l] == nums[l+1]) l--; // dup l
                    }
                }
            }
        }
        return ans;
    }
};
*/