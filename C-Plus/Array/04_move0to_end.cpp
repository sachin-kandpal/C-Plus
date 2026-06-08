//  PROBLEM : Move Zeros to End

#include <bits/stdc++.h>
using namespace std;

void printArr(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
}


// // =============================================================
// // METHOD  — BRUTE FORCE
// // Idea : Copy non-zeros to temp array, paste back, fill 0s
// // Time : O(N)   Space: O(N)
// // STATUS: ← ACTIVE (uncomment Method 2 or 3 main to switch)
// // =============================================================

// void moveZerosBrute(vector<int>& arr) {
//     int n = arr.size();
//     vector<int> temp;

//     for (int i = 0; i < n; i++)
//         if (arr[i] != 0)
//             temp.push_back(arr[i]);   // collect all non-zeros

//     int k = temp.size();
//     for (int i = 0; i < k; i++)
//         arr[i] = temp[i];             // paste non-zeros back

//     for (int i = k; i < n; i++)
//         arr[i] = 0;                   // fill rest with 0
// }

// int main() {
//     cout << "===== BRUTE FORCE =====\n";
//     vector<int> arr = {1, 0, 2, 3, 0, 4, 0, 1};
//     cout << "Input : "; printArr(arr);
//     moveZerosBrute(arr);
//     cout << "Output: "; printArr(arr);
//     return 0;
// }

// =============================================================
// METHOD  — OPTIMAL (Two Pointer)  <- SUBMIT THIS ON JUDGE
// Idea : j = next slot for non-zero; i scans, swaps when != 0
// Time : O(N)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================


void moveZerosOptimal(vector<int>& arr) {
    int j = 0;                         // slot for next non-zero
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main() {
    cout << "===== OPTIMAL =====\n";
    vector<int> arr = {1, 0, 2, 3, 0, 4, 0, 1};
    cout << "Input : "; printArr(arr);
    moveZerosOptimal(arr);
    cout << "Output: "; printArr(arr);
    return 0;
}



// // =============================================================
// // JUDGE / ONLINE SUBMISSION CODE (LeetCode #283 - Move Zeroes)
// // Copy ONLY this class when submitting on LeetCode / GFG
// // =============================================================


// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int j = 0;
//         for (int i = 0; i < (int)nums.size(); i++) {
//             if (nums[i] != 0) {
//                 swap(nums[i], nums[j]);
//                 j++;
//             }
//         }
//     }
// };
