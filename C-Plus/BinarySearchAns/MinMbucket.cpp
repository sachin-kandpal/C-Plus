// // brute force solution
// #include <bits/stdc++.h>
// using namespace std;

// // Class to handle bouquet formation logic
// class RoseGarden {
// public:
//     // Function to check if we can form 'm' bouquets by 'day'
//     bool isPossible(vector<int>& bloomDays, int day, int m, int k) {
//         int count = 0;  // consecutive flowers that bloomed by 'day'
//         int bouquets = 0;

//         for (int bloom : bloomDays) {
//             if (bloom <= day) {
//                 count++;
//                 if (count == k) {
//                     bouquets++;
//                     count = 0;
//                 }
//             } else {
//                 count = 0;
//             }
//         }

//         return bouquets >= m;
//     }

//     // Main function to find the minimum day to form 'm' bouquets
//     int minDaysToMakeBouquets(vector<int>& bloomDays, int m, int k) {
//         long long totalFlowers = 1LL * m * k;
//         if (totalFlowers > bloomDays.size()) return -1; // Not enough flowers

//         int low = *min_element(bloomDays.begin(), bloomDays.end());
//         int high = *max_element(bloomDays.begin(), bloomDays.end());

//         // Brute-force search from min to max bloom day
//         for (int day = low; day <= high; ++day) {
//             if (isPossible(bloomDays, day, m, k)) {
//                 return day;
//             }
//         }

//         return -1; // Not possible to make bouquets
//     }
// };

// int main() {
//     vector<int> bloomDays = {7, 7, 7, 7, 13, 11, 12, 7};
//     int k = 3;
//     int m = 2;

//     RoseGarden garden;
//     int result = garden.minDaysToMakeBouquets(bloomDays, m, k);

//     if (result == -1)
//         cout << "We cannot make m bouquets.\n";
//     else
//         cout << "We can make bouquets on day " << result << "\n";

//     return 0;
// }


// optimal solution
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to check if it's possible to make m bouquets on or before a given day
    bool possible(vector<int>& arr, int day, int m, int k) {
        int n = arr.size();         // Total number of flowers
        int cnt = 0;                // Counter for consecutive bloomed flowers
        int bouquets = 0;           // Count of bouquets made

        for (int i = 0; i < n; i++) {
            if (arr[i] <= day) {
                // Flower bloomed, increment consecutive count
                cnt++;
                if (cnt == k) {
                    // We have k consecutive bloomed flowers — make 1 bouquet
                    bouquets++;
                    cnt = 0; // reset for next bouquet
                }
            } else {
                // Flower not bloomed, reset consecutive count
                cnt = 0;
            }
        }

        // Check if at least m bouquets can be made
        return bouquets >= m;
    }

    // Main function to find the minimum day to make m bouquets
    int roseGarden(vector<int>& arr, int k, int m) {
        long long total = 1LL * k * m; // Total flowers required

        // If total required flowers > available flowers, it's impossible
        if (total > arr.size()) return -1;

        // Find minimum and maximum bloom days from array
        int mini = *min_element(arr.begin(), arr.end());
        int maxi = *max_element(arr.begin(), arr.end());

        // Apply binary search on number of days
        int low = mini, high = maxi;
        int result = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (possible(arr, mid, m, k)) {
                // If it's possible to make bouquets on this day, try to find an earlier day
                result = mid;
                high = mid - 1;
            } else {
                // Otherwise, try with a later day
                low = mid + 1;
            }
        }

        return result;
    }
};

int main() {
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3; // number of flowers needed per bouquet
    int m = 2; // number of bouquets to make

    Solution sol;
    int ans = sol.roseGarden(arr, k, m);

    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";

    return 0;
}