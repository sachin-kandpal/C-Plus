// // brute force solution
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     // Function to find the smallest divisor such that
//     // the sum of ceil(arr[i] / d) over all i <= limit
//     int smallestDivisor(vector<int>& arr, int limit) {
//         int n = arr.size(); // Size of the array

//         // Find the maximum element in the array
//         int maxi = *max_element(arr.begin(), arr.end());

//         // Try every possible divisor from 1 to maxi
//         for (int d = 1; d <= maxi; d++) {
//             int sum = 0;

//             // For each element, compute ceil(arr[i] / d) and add to sum
//             for (int i = 0; i < n; i++) {
//                 sum += ceil((double)(arr[i]) / (double)(d));
//             }

//             // If the total sum is within the limit, return this divisor
//             if (sum <= limit) {
//                 return d;
//             }
//         }

//         // If no valid divisor is found, return -1
//         return -1;
//     }
// };

// int main() {
//     vector<int> arr = {1, 2, 3, 4, 5};
//     int limit = 8;

//     Solution obj;
//     int ans = obj.smallestDivisor(arr, limit);

//     cout << "The minimum divisor is: " << ans << "\n";
//     return 0;
// }


// optimal approach
#include <bits/stdc++.h>
using namespace std;

class SmallestDivisorFinder {
public:
    // Helper function to calculate sum of division results
    int sumByD(vector<int>& arr, int div) {
        int sum = 0;
        for (int num : arr) {
            sum += ceil((double)num / div);
        }
        return sum;
    }

    // Function to find the smallest divisor
    int smallestDivisor(vector<int>& arr, int limit) {
        if (arr.size() > limit) return -1;

        int low = 1;
        int high = *max_element(arr.begin(), arr.end());

        // Binary search to find smallest divisor
        while (low <= high) {
            int mid = (low + high) / 2;
            if (sumByD(arr, mid) <= limit) {
                high = mid - 1;  // Try smaller divisor
            } else {
                low = mid + 1;   // Try larger divisor
            }
        }

        return low;
    }
};

int main() {
    SmallestDivisorFinder solver;
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = solver.smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}