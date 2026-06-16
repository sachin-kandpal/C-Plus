/*
=============================================================
  PROBLEM : 3Sum
  Platform : LeetCode #15 (Medium)
  Sheet    : Striver A2Z DSA (Arrays - Medium)

  Find all unique triplets that sum to 0.
  No duplicate triplets in output.

  Example:
    [-1,0,1,2,-1,-4] → [[-1,-1,2],[-1,0,1]]
    [0,1,1]          → []
    [0,0,0]          → [[0,0,0]]

  NOTE: vector<vector<int>> for output (dynamic 2D result).
        Input uses raw array in VS Code.

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ three_sum.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;

void printResult(vector<vector<int>>& res) {
    if (res.empty()) { cout << "[]" << endl; return; }
    cout << "[";
    for (int i = 0; i < (int)res.size(); i++) {
        cout << "[" << res[i][0] << "," << res[i][1] << "," << res[i][2] << "]";
        if (i < (int)res.size()-1) cout << ", ";
    }
    cout << "]" << endl;
}


// =============================================================
// METHOD 1 — BRUTE FORCE
// Idea : 3 nested loops, try every triplet
//        Sort each triplet + insert into set<vector<int>>
//        Set auto-removes duplicate triplets
// Time : O(N^3 log N)   Space: O(unique triplets)
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

vector<vector<int>> threeSumBrute(int nums[], int n) {
    set<vector<int>> st;                   // stores unique sorted triplets

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            for (int k = j+1; k < n; k++)
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end()); // sort to normalize
                    st.insert(temp);               // set handles dedup
                }

    return vector<vector<int>>(st.begin(), st.end());
}

int main() {
    cout << "===== BRUTE FORCE =====" << endl;

    int a1[] = {-1,0,1,2,-1,-4};
    vector<vector<int>> r1 = threeSumBrute(a1, 6);
    cout << "[-1,0,1,2,-1,-4] → "; printResult(r1);

    int a2[] = {0,1,1};
    vector<vector<int>> r2 = threeSumBrute(a2, 3);
    cout << "[0,1,1]          → "; printResult(r2);

    int a3[] = {0,0,0};
    vector<vector<int>> r3 = threeSumBrute(a3, 3);
    cout << "[0,0,0]          → "; printResult(r3);

    return 0;
}


// =============================================================
// METHOD 2 — BETTER (HashSet per i)
// Idea : Fix i, fix j, find third = -(nums[i]+nums[j])
//        Use hashset built as j moves to find third quickly
//        Use set<vector<int>> for dedup of output
// Time : O(N^2 log N)   Space: O(N)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
vector<vector<int>> threeSumBetter(int nums[], int n) {
    set<vector<int>> st;               // for unique triplets in output

    for (int i = 0; i < n; i++) {
        set<int> hashset;              // tracks elements seen for this i

        for (int j = i+1; j < n; j++) {
            int third = -(nums[i] + nums[j]);  // we need this to complete triplet

            if (hashset.count(third)) {        // found the third element!
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);               // set deduplicates
            }

            hashset.insert(nums[j]);   // add nums[j] for future j iterations
        }
    }
    return vector<vector<int>>(st.begin(), st.end());
}

int main() {
    cout << "===== BETTER (HashSet) =====" << endl;

    int a1[] = {-1,0,1,2,-1,-4};
    vector<vector<int>> r1 = threeSumBetter(a1, 6);
    cout << "[-1,0,1,2,-1,-4] → "; printResult(r1);

    int a2[] = {0,1,1};
    vector<vector<int>> r2 = threeSumBetter(a2, 3);
    cout << "[0,1,1]          → "; printResult(r2);

    int a3[] = {0,0,0};
    vector<vector<int>> r3 = threeSumBetter(a3, 3);
    cout << "[0,0,0]          → "; printResult(r3);

    return 0;
}
*/


// =============================================================
// METHOD 3 — OPTIMAL (Sort + Two Pointers)  <- SUBMIT THIS
//
// Step 1: Sort the array
// Step 2: Fix i (loop 0 to n-3)
//   Skip duplicate i: if nums[i]==nums[i-1] → continue
//   j = i+1  (left pointer)
//   k = n-1  (right pointer)
//
//   While j < k:
//     sum = nums[i]+nums[j]+nums[k]
//     sum < 0 → j++ (need larger value)
//     sum > 0 → k-- (need smaller value)
//     sum == 0:
//       → add triplet {nums[i],nums[j],nums[k]}
//       → skip dup j: while(j<k && nums[j]==nums[j-1]) j++
//       → skip dup k: while(j<k && nums[k]==nums[k+1]) k--
//       → j++, k--
//
// Why no set needed?
//   Sorting + skipping duplicates at i, j, k level
//   guarantees no duplicate triplets → O(1) dedup
//
// Time : O(N log N + N^2) = O(N^2)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
vector<vector<int>> threeSumOptimal(int nums[], int n) {
    sort(nums, nums + n);              // sort first!
    vector<vector<int>> ans;

    for (int i = 0; i < n - 2; i++) {
        // skip duplicate i values
        if (i > 0 && nums[i] == nums[i-1]) continue;

        // early exit: smallest possible sum already > 0
        if (nums[i] > 0) break;

        int j = i + 1;                 // left pointer
        int k = n - 1;                 // right pointer

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum < 0) {
                j++;                   // sum too small → move left ptr right
            }
            else if (sum > 0) {
                k--;                   // sum too big → move right ptr left
            }
            else {                     // sum == 0 → found a triplet!
                ans.push_back({nums[i], nums[j], nums[k]});

                j++; k--;              // move both pointers inward

                // skip duplicate j values
                while (j < k && nums[j] == nums[j-1]) j++;
                // skip duplicate k values
                while (j < k && nums[k] == nums[k+1]) k--;
            }
        }
    }
    return ans;
}

int main() {
    cout << "===== OPTIMAL (Sort + Two Pointers) =====" << endl;

    int a1[] = {-1,0,1,2,-1,-4};
    vector<vector<int>> r1 = threeSumOptimal(a1, 6);
    cout << "[-1,0,1,2,-1,-4] → "; printResult(r1);  // [[-1,-1,2],[-1,0,1]]

    int a2[] = {0,1,1};
    vector<vector<int>> r2 = threeSumOptimal(a2, 3);
    cout << "[0,1,1]          → "; printResult(r2);   // []

    int a3[] = {0,0,0};
    vector<vector<int>> r3 = threeSumOptimal(a3, 3);
    cout << "[0,0,0]          → "; printResult(r3);   // [[0,0,0]]

    int a4[] = {-2,0,1,1,2};
    vector<vector<int>> r4 = threeSumOptimal(a4, 5);
    cout << "[-2,0,1,1,2]     → "; printResult(r4);  // [[-2,0,2],[-2,1,1]]

    return 0;
}
*/


// =============================================================
// JUDGE CODE — LeetCode #15
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // skip dup i
            if (nums[i] > 0) break;                       // no triplet possible

            int j = i+1, k = n-1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if      (sum < 0) j++;
                else if (sum > 0) k--;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    while (j < k && nums[j] == nums[j-1]) j++; // skip dup j
                    while (j < k && nums[k] == nums[k+1]) k--; // skip dup k
                }
            }
        }
        return ans;
    }
};
*/