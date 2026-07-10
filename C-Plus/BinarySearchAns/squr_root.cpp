// // brute force solution
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     // Function to find floor of square root using linear search
//     int floorSqrt(int n) {
//         // Variable to store answer
//         int ans = 0;

//         // Run loop from 1 to n
//         for (int i = 1; i <= n; i++) {
//             // Check if i*i <= n
//             if ((long long)i * i <= n) {
//                 // Update answer
//                 ans = i;
//             } else {
//                 // Break when i*i > n
//                 break;
//             }
//         }
//         // Return final answer
//         return ans;
//     }
// };

// int main() {
//     // Example input
//     int n = 27;

//     // Create object of Solution
//     Solution sol;

//     // Call function and print result
//     cout << sol.floorSqrt(n) << endl;

//     return 0;
// }




// optimal solution
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // This function returns the floor value of the square root of a number
    int mySqrt(int x) {
        // Handle small numbers directly
        if (x < 2) return x;

        // Initialize binary search range
        int left = 1, right = x / 2, ans = 0;

        // Perform binary search
        while (left <= right) {
            // Find middle point
            long long mid = left + (right - left) / 2;

            // Check if mid*mid is less than or equal to x
            if (mid * mid <= x) {
                // Store mid as potential answer
                ans = mid;
                // Move to right half
                left = mid + 1;
            } else {
                // Move to left half
                right = mid - 1;
            }
        }

        // Return final answer
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.mySqrt(8) << endl;
    return 0;
}