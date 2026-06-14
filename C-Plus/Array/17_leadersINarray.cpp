/*
=============================================================
  PROBLEM : Leaders in an Array
  Platform : TUF+ / GFG
  Sheet    : Striver A2Z DSA (Arrays - Easy)

  An element is a leader if strictly greater than all
  elements to its right. Rightmost is always a leader.
  Return leaders in original left-to-right order.

  Example:
    nums = [1, 2, 5, 3, 1, 2]    →  [5, 3, 2]
    nums = [-3, 4, 5, 1, -4, -5] →  [5, 1, -4, -5] 
    nums = [5, 4, 3, 2, 1]       →  [5, 4, 3, 2, 1] (all leaders)
    nums = [1, 2, 3, 4, 5]       →  [5]             (only rightmost)

  NOTE: Output is dynamic (unknown size) → vector for result.
        Input uses raw array in VS Code version.

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ leaders_in_array.cpp -o out && ./out
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
// Idea : For every element, check ALL elements to its right
//        If greater than all of them → it's a leader
// Time : O(N^2)   Space: O(1) excluding output
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

vector<int> leadersBrute(int nums[], int n) {
    vector<int> result;

    for (int i = 0; i < n; i++) {
        bool isLeader = true;

        for (int j = i + 1; j < n; j++) {    // check all elements to right
            if (nums[j] >= nums[i]) {         // found something >= nums[i]
                isLeader = false;             // not a leader
                break;
            }
        }

        if (isLeader)
            result.push_back(nums[i]);        // add to result in original order
    }
    return result;
}

int main() {
    int nums[] = {1, 2, 5, 3, 1, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "===== BRUTE FORCE =====" << endl;
    cout << "Input  : [1, 2, 5, 3, 1, 2]" << endl;
    vector<int> r1 = leadersBrute(nums, n);
    cout << "Output : "; printVec(r1);        // [5, 3, 2]

    int e1[] = {5, 4, 3, 2, 1};
    vector<int> r2 = leadersBrute(e1, 5);
    cout << "Descending : "; printVec(r2);    // [5,4,3,2,1]

    int e2[] = {1, 2, 3, 4, 5};
    vector<int> r3 = leadersBrute(e2, 5);
    cout << "Ascending  : "; printVec(r3);    // [5]

    return 0;
}


// =============================================================
// METHOD 2 — OPTIMAL (Right to Left Scan)  <- SUBMIT THIS
//
// Key insight:
//   An element is a leader if it's > MAX of all elements to its right
//   So track maxFromRight as we scan right to left
//
// Steps:
//   → Start from rightmost element (always a leader)
//   → Track maxFromRight = INT_MIN initially
//   → If nums[i] > maxFromRight → leader → collect it
//   → Update maxFromRight
//   → At end: reverse collected leaders (they're in reverse order)
//
// Time : O(N)   Space: O(1) excluding output
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
vector<int> leadersOptimal(int nums[], int n) {
    vector<int> result;
    int maxFromRight = INT_MIN;          // max element seen from the right

    for (int i = n - 1; i >= 0; i--) {  // scan right to left
        if (nums[i] > maxFromRight) {    // greater than all to its right
            result.push_back(nums[i]);   // it's a leader!
        }
        maxFromRight = max(maxFromRight, nums[i]); // update running max
    }

    reverse(result.begin(), result.end()); // reverse to get original order
    return result;
}

int main() {
    int nums[] = {1, 2, 5, 3, 1, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "===== OPTIMAL (Right to Left) =====" << endl;
    cout << "Input  : [1, 2, 5, 3, 1, 2]" << endl;
    vector<int> r1 = leadersOptimal(nums, n);
    cout << "Output : "; printVec(r1);         // [5, 3, 2]

    int e1[] = {-3, 4, 5, 1, -4, -5};
    vector<int> r2 = leadersOptimal(e1, 6);
    cout << "[-3,4,5,1,-4,-5] : "; printVec(r2); // [5,1,-4,-5]

    int e2[] = {5, 4, 3, 2, 1};
    vector<int> r3 = leadersOptimal(e2, 5);
    cout << "Descending [5,4,3,2,1] : "; printVec(r3); // [5,4,3,2,1]

    int e3[] = {1, 2, 3, 4, 5};
    vector<int> r4 = leadersOptimal(e3, 5);
    cout << "Ascending  [1,2,3,4,5] : "; printVec(r4); // [5]

    int e4[] = {7};
    vector<int> r5 = leadersOptimal(e4, 1);
    cout << "Single element [7]     : "; printVec(r5); // [7]

    return 0;
}
*/


// =============================================================
// JUDGE CODE — GFG / TUF+
// Copy ONLY this function when submitting online
// =============================================================

/*
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        int maxFromRight = INT_MIN;

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > maxFromRight)
                result.push_back(nums[i]);   // leader found

            maxFromRight = max(maxFromRight, nums[i]);
        }

        reverse(result.begin(), result.end()); // restore original order
        return result;
    }
};
*/