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


// // judge version
// class Solution {
// public:
//     int subarraySum(vector<int>& arr, int k) {

//         int n = arr.size();
//         int count = 0;

//         // Create prefix sum array
//         vector<int> prefixSum(n, 0);

//         prefixSum[0] = arr[0];

//         // Build prefix sums
//         for (int i = 1; i < n; i++) {
//             prefixSum[i] = prefixSum[i - 1] + arr[i];
//         }

//         // Stores frequency of previous prefix sums
//         unordered_map<int, int> mp;

//         for (int i = 0; i < n; i++) {

//             // Subarray starting from index 0
//             if (prefixSum[i] == k)
//                 count++;

//             // Required previous prefix sum
//             int val = prefixSum[i] - k;

//             // Add all previous occurrences
//             if (mp.find(val) != mp.end()) {
//                 count += mp[val];
//             }

//             // Store current prefix sum
//             mp[prefixSum[i]]++;
//         }

//         return count;
//     }
// };

// // vs code
// #include <bits/stdc++.h>
// using namespace std;

// // Function to count subarrays with sum k
// int subarraySum(vector<int>& arr, int k) {

//     int n = arr.size();
//     int count = 0;

//     // Prefix sum array
//     vector<int> prefixSum(n, 0);

//     // First prefix sum
//     prefixSum[0] = arr[0];

//     // Build prefix sum array
//     for (int i = 1; i < n; i++) {
//         prefixSum[i] = prefixSum[i - 1] + arr[i];
//     }

//     // Hash map stores frequency of prefix sums
//     unordered_map<int, int> mp;

//     for (int i = 0; i < n; i++) {

//         // If subarray starts from index 0
//         if (prefixSum[i] == k)
//             count++;

//         // Find required prefix sum
//         int val = prefixSum[i] - k;

//         if (mp.find(val) != mp.end()) {
//             count += mp[val];
//         }

//         // Store current prefix sum
//         mp[prefixSum[i]]++;
//     }

//     return count;
// }

// int main() {

//     vector<int> arr = {1, 2, 3};
//     int k = 3;

//     cout << "Number of subarrays = "
//          << subarraySum(arr, k) << endl;

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