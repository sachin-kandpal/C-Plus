// brute force Solution

// // judge version
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;

//         // Try every starting index
//         for (int i = 0; i < n; i++) {

//             int sum = 0;

//             // Extend the subarray to every ending index
//             for (int j = i; j < n; j++) {

//                 // Add current element
//                 sum += nums[j];

//                 // If sum becomes k, increment answer
//                 if (sum == k) {
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };

// vs code
#include <bits/stdc++.h>
using namespace std;

// Function to count subarrays with sum k
int subarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    int count = 0;

    // Fix starting index
    for (int i = 0; i < n; i++) {

        int sum = 0;

        // Extend ending index
        for (int j = i; j < n; j++) {

            sum += nums[j];

            // Check if current subarray sum equals k
            if (sum == k) {
                count++;
            }
        }
    }

    return count;
}

int main() {

    vector<int> nums = {1, 1, 1};
    int k = 2;

    cout << "Number of subarrays = "
         << subarraySum(nums, k) << endl;

    return 0;
}



// bettter


// // judge versio
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {

//         unordered_map<int, int> mp;

//         // Prefix sum 0 occurs once before the array starts
//         mp[0] = 1;

//         int prefixSum = 0;
//         int count = 0;

//         for (int i = 0; i < nums.size(); i++) {

//             // Update running sum
//             prefixSum += nums[i];

//             // If (prefixSum - k) exists,
//             // add its frequency to answer
//             if (mp.find(prefixSum - k) != mp.end()) {
//                 count += mp[prefixSum - k];
//             }

//             // Store current prefix sum
//             mp[prefixSum]++;
//         }

//         return count;
//     }
// };

// // vs code
// #include <bits/stdc++.h>
// using namespace std;

// // Function to count subarrays with sum k
// int subarraySum(vector<int> &nums, int k) {
//     int n = nums.size();
//     int count = 0;

//     // Fix starting index
//     for (int i = 0; i < n; i++) {

//         int sum = 0;

//         // Extend ending index
//         for (int j = i; j < n; j++) {

//             sum += nums[j];

//             // Check if current subarray sum equals k
//             if (sum == k) {
//                 count++;
//             }
//         }
//     }

//     return count;
// }

// int main() {

//     vector<int> nums = {1, 1, 1};
//     int k = 2;

//     cout << "Number of subarrays = "
//          << subarraySum(nums, k) << endl;

//     return 0;
// }


// // optimal
// // judge version
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {

//         unordered_map<int, int> mp;

//         // Prefix sum 0 occurs once before the array starts
//         mp[0] = 1;

//         int prefixSum = 0;
//         int count = 0;

//         for (int i = 0; i < nums.size(); i++) {

//             // Update running sum
//             prefixSum += nums[i];

//             // If (prefixSum - k) exists,
//             // add its frequency to answer
//             if (mp.find(prefixSum - k) != mp.end()) {
//                 count += mp[prefixSum - k];
//             }

//             // Store current prefix sum
//             mp[prefixSum]++;
//         }

//         return count;
//     }
// };
// // vs code
// #include <bits/stdc++.h>
// using namespace std;

// // Function to count subarrays with sum k
// int subarraySum(vector<int> &nums, int k) {

//     // Stores frequency of prefix sums
//     unordered_map<int, int> mp;

//     // Prefix sum 0 exists once initially
//     mp[0] = 1;

//     int prefixSum = 0;
//     int count = 0;

//     for (int i = 0; i < nums.size(); i++) {

//         // Add current element
//         prefixSum += nums[i];

//         // Check if required prefix exists
//         if (mp.find(prefixSum - k) != mp.end()) {
//             count += mp[prefixSum - k];
//         }

//         // Record current prefix sum
//         mp[prefixSum]++;
//     }

//     return count;
// }

// int main() {

//     vector<int> nums = {1, 1, 1};
//     int k = 2;

//     cout << "Number of subarrays = "
//          << subarraySum(nums, k) << endl;

//     return 0;
// }