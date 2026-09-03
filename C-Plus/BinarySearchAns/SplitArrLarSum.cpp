// // // split array largest sum

// // Problem Statement: Given an integer array ‘A’ of size ‘N’
// //  and an integer ‘K'. Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized.
// //   Your task is to return the minimized largest sum of the split. A subarray is a contiguous part of the array.

// // brute force solution
// #include <bits/stdc++.h>
// using namespace std;

// class SubarrayPartitioner {
// public:
//     // Function to count how many partitions are needed
//     // if each subarray sum is restricted to at most maxSum
//     int countPartitions(vector<int> &a, int maxSum) {
//         int n = a.size(); // size of the array
//         int partitions = 1; // always have at least 1 partition
//         long long subarraySum = 0; // sum of the current subarray

//         for (int i = 0; i < n; i++) {
//             // If adding this element doesn't exceed maxSum, keep adding to current subarray
//             if (subarraySum + a[i] <= maxSum) {
//                 subarraySum += a[i];
//             }
//             else {
//                 // Otherwise, start a new subarray
//                 partitions++;
//                 subarraySum = a[i];
//             }
//         }
//         return partitions;
//     }

//     // Function to find the smallest maximum subarray sum possible
//     // such that the array is split into exactly k subarrays
//     int largestSubarraySumMinimized(vector<int> &a, int k) {
//         // Lower bound: max element in array (can't be smaller than that)
//         int low = *max_element(a.begin(), a.end());
//         // Upper bound: sum of entire array (only one subarray)
//         int high = accumulate(a.begin(), a.end(), 0);

//         // Brute-force: test each possible maxSum from low to high
//         for (int maxSum = low; maxSum <= high; maxSum++) {
//             // If we can form exactly k partitions with this maxSum, return it
//             if (countPartitions(a, maxSum) == k)
//                 return maxSum;
//         }
//         return low; // fallback
//     }
// };

// int main() {
//     vector<int> a = {10, 20, 30, 40};
//     int k = 2;
//     SubarrayPartitioner sp; // Create object
//     int ans = sp.largestSubarraySumMinimized(a, k);
//     cout << "The answer is: " << ans << "\n";
//     return 0;
// }


// optimal solution
// same soln as the book allocaton as the problem was the same as the book allocation problem