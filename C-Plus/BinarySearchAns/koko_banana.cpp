// // brute force solution
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     // Function to calculate total hours for given speed
//     int calculateTotalHours(vector<int>& a, int hourly) {
//         int totalHours = 0;
//         for (int pile : a) {
//             // Add hours using ceil
//             totalHours += (pile + hourly - 1) / hourly;
//         }
//         return totalHours;
//     }

//     // Function to find minimum eating speed
//     int minEatingSpeed(vector<int>& a, int h) {
//         // Find maximum pile size
//         int maxVal = *max_element(a.begin(), a.end());

//         // Try every possible speed
//         for (int i = 1; i <= maxVal; i++) {
//             int hours = calculateTotalHours(a, i);

//             // If hours fit within h
//             if (hours <= h) {
//                 return i;
//             }
//         }
//         return maxVal;
//     }
// };

// int main() {
//     // Input array
//     vector<int> a = {3, 6, 7, 11};
//     // Hours allowed
//     int h = 8;

//     Solution obj;
//     cout << obj.minEatingSpeed(a, h);
//     return 0;
// }




// optimal solution
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate total hours at given speed
    int calculateTotalHours(vector<int>& piles, int speed) {
        int totalH = 0;
        for (int bananas : piles) {
            totalH += ceil((double)bananas / speed);
        }
        return totalH;
    }

    // Function to find minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        // Find maximum element
        int maxPile = *max_element(piles.begin(), piles.end());

        // Initialize low and high pointers
        int low = 1, high = maxPile;
        int ans = maxPile;

        // Binary search on answer space
        while (low <= high) {
            int mid = (low + high) / 2;
            int totalH = calculateTotalHours(piles, mid);

            // If possible, try smaller speed
            if (totalH <= h) {
                ans = mid;
                high = mid - 1;
            }
            // Otherwise, try larger speed
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    Solution obj;
    cout << obj.minEatingSpeed(piles, h);
    return 0;
}