/*
=============================================================
  PROBLEM : Majority Element II
  Platform : LeetCode #229 (Medium)
  Sheet    : Striver A2Z DSA (Arrays - Medium)

  Find ALL elements appearing MORE THAN n/3 times.
  At most 2 such elements can exist (mathematical fact).
  → Compile: g++ majority_element_2.cpp -o out && ./out
=============================================================
*/


// =============================================================
// METHOD 1 — BRUTE FORCE
// Idea : For every element, count its frequency
//        If freq > n/3 and not already added → add to result
// Time : O(N^2)   Space: O(1) excluding output
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums) {

    int n = nums.size();
    vector<int> ls;

    for (int i = 0; i < n; i++) {

        // Process only if list is empty or current element
        // is different from the first stored majority element
        if (ls.size() == 0 || ls[0] != nums[i]) {

            int cnt = 0;

            // Count frequency of nums[i]
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    cnt++;
                }
            }

            // If frequency > n/3, add to answer
            if (cnt > n / 3) {
                ls.push_back(nums[i]);
            }
        }

        // At most 2 majority elements can exist
        if (ls.size() == 2)
            break;
    }

    return ls;
}

int main() {

    vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};

    vector<int> ans = majorityElement(nums);

    cout << "Majority Elements: ";
    for (int x : ans)
        cout << x << " ";

    cout << endl;

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



// #include <bits/stdc++.h>
// using namespace std;

// vector<int> majorityElement(vector<int> &nums) {

//     int n = nums.size();

//     int cnt1 = 0, cnt2 = 0;
//     int el1 = INT_MIN, el2 = INT_MIN;

//     // Step 1: Find candidates
//     for (int i = 0; i < n; i++) {

//         if (cnt1 == 0 && el2 != nums[i]) {
//             cnt1 = 1;
//             el1 = nums[i];
//         }
//         else if (cnt2 == 0 && el1 != nums[i]) {
//             cnt2 = 1;
//             el2 = nums[i];
//         }
//         else if (nums[i] == el1) {
//             cnt1++;
//         }
//         else if (nums[i] == el2) {
//             cnt2++;
//         }
//         else {
//             cnt1--;
//             cnt2--;
//         }
//     }

//     // Step 2: Verify candidates
//     cnt1 = 0;
//     cnt2 = 0;

//     for (int i = 0; i < n; i++) {
//         if (nums[i] == el1)
//             cnt1++;

//         if (nums[i] == el2)
//             cnt2++;
//     }

//     vector<int> ans;
//     int mini = (n / 3) + 1;

//     if (cnt1 >= mini)
//         ans.push_back(el1);

//     if (cnt2 >= mini)
//         ans.push_back(el2);

//     return ans;
// }

// int main() {

//     vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};

//     vector<int> ans = majorityElement(nums);

//     cout << "Majority Elements: ";
//     for (int x : ans)
//         cout << x << " ";

//     cout << endl;

//     return 0;
// }

// =============================================================
// JUDGE CODE — LeetCode #229
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();

        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        // Step 1: Find potential candidates
        for (int i = 0; i < n; i++) {

            if (cnt1 == 0 && el2 != nums[i]) {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && el1 != nums[i]) {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if (nums[i] == el1) {
                cnt1++;
            }
            else if (nums[i] == el2) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        // Step 2: Verify the candidates
        cnt1 = 0;
        cnt2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == el1)
                cnt1++;
            if (nums[i] == el2)
                cnt2++;
        }

        vector<int> ans;

        int mini = (n / 3) + 1;

        if (cnt1 >= mini)
            ans.push_back(el1);

        if (cnt2 >= mini)
            ans.push_back(el2);

        return ans;
    }
};
*/