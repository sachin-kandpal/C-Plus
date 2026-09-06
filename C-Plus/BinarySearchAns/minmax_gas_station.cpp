// // // Minimize Max Distance to Gas Station

// // Given a sorted array arr of size n, containing integer positions of n gas stations on the X-axis, and an integer k, place k new gas stations on the X-axis.
// // The new gas stations can be placed anywhere on the non-negative side of the X-axis, including non-integer positions.
// // Let dist be the maximum distance between adjacent gas stations after adding the k new gas stations.
// // Find the minimum value of dist.


// // brute force approach is to try all possible positions for the new gas stations, but this would be inefficient. Instead, we can use a binary search approach to find the minimum value of dist.
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// class Solution {
// public:
//     long double minimiseMaxDistance(vector<int> &arr, int k) {
//         int n = arr.size();

//         // howMany[i] stores how many NEW gas stations are placed between arr[i] and arr[i+1]
//         // Initially initialized to 0 for all (n - 1) gaps
//         vector<int> howMany(n - 1, 0);

//         // Outer loop: Place 'k' gas stations one by one
//         for (int gasStations = 1; gasStations <= k; gasStations++) {
//             long double maxSection = -1;
//             int maxInd = -1;

//             // Inner loop: Find which section/gap is currently the LARGEST
//             for (int i = 0; i < n - 1; i++) {
//                 long double diff = (arr[i + 1] - arr[i]);
                
//                 // If we place howMany[i] stations, the gap splits into (howMany[i] + 1) equal parts
//                 long double sectionLength = diff / (long double)(howMany[i] + 1);

//                 if (sectionLength > maxSection) {
//                     maxSection = sectionLength;
//                     maxInd = i; // Save the index of the largest section
//                 }
//             }

//             // GREEDY CHOICE (Your question): 
//             // Place 1 new gas station in the section that was the largest (maxInd)
//             howMany[maxInd]++;
//         }

//         // Final step: Calculate the maximum section length remaining after placing all k stations
//         long double maxAns = -1;
//         for (int i = 0; i < n - 1; i++) {
//             long double diff = (arr[i + 1] - arr[i]);
//             long double sectionLength = diff / (long double)(howMany[i] + 1);
//             maxAns = max(maxAns, sectionLength);
//         }

//         return maxAns;
//     }
// };

// int main() {
//     Solution sol;

//     // Test case from the video screenshot
//     vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
//     int k = 6;

//     long double ans = sol.minimiseMaxDistance(arr, k);

//     cout << "Minimum value of maximum distance: " << ans << endl;

//     return 0;
// }





// // better approach using queue
// #include <iostream>
// #include <vector>
// #include <queue>     // For priority_queue
// #include <algorithm>
// #include <iomanip>   // For fixed decimal output

// using namespace std;

// class Solution {
// public:
//     long double minimiseMaxDistance(vector<int> &arr, int k) {
//         int n = arr.size();

//         // howMany[i] stores how many extra gas stations are added in section 'i'
//         vector<int> howMany(n - 1, 0);

//         // Max-Heap (Priority Queue) storing pair: <section_length, section_index>
//         priority_queue<pair<long double, int>> pq;

//         // Step 1: Insert all initial section lengths and their indices into the heap
//         for (int i = 0; i < n - 1; i++) {
//             pq.push({(long double)(arr[i + 1] - arr[i]), i});
//         }

//         // Step 2: Place 'k' gas stations one by one using the max-heap
//         for (int gasStations = 1; gasStations <= k; gasStations++) {
//             // Get the current largest section
//             auto tp = pq.top();
//             pq.pop();

//             int secInd = tp.second; // Index of the largest section

//             // Place a gas station in this section
//             howMany[secInd]++;

//             // Calculate new section length after adding the station
//             long double iniDiff = arr[secInd + 1] - arr[secInd];
//             long double newSecLen = iniDiff / (long double)(howMany[secInd] + 1);

//             // Push the updated section back into the heap
//             pq.push({newSecLen, secInd});
//         }

//         // Step 3: The top element of the heap is the maximum section length
//         return pq.top().first;
//     }
// };

// int main() {
//     Solution sol;

//     // Test case matching Striver's example
//     vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
//     int k = 6;

//     long double ans = sol.minimiseMaxDistance(arr, k);

//     cout << fixed << setprecision(6);
//     cout << "Minimum value of maximum distance: " << ans << endl;

//     return 0;
// }




// optimized approach using binary search
#include <bits/stdc++.h>
using namespace std;

// Class that contains methods for optimizing gas station placement
class GasStationOptimizer {
public:
    // Function to calculate number of gas stations required such that
    // no segment exceeds the max allowed distance `dist`
    int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
        int n = arr.size();
        int cnt = 0;

        for (int i = 1; i < n; i++) {
            // Number of stations needed between arr[i-1] and arr[i]
            int numberInBetween = (arr[i] - arr[i - 1]) / dist;

            // If perfectly divisible, reduce one to avoid extra placement
            if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
                numberInBetween--;
            }
            cnt += numberInBetween;
        }
        return cnt;
    }

    // Function to minimize the maximum distance between gas stations
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        long double low = 0, high = 0;

        // Determine max initial distance between stations
        for (int i = 0; i < n - 1; i++) {
            high = max(high, (long double)(arr[i + 1] - arr[i]));
        }

        long double diff = 1e-6;

        // Binary search to find minimum possible maximum distance
        while (high - low > diff) {
            long double mid = (low + high) / 2.0;
            int cnt = numberOfGasStationsRequired(mid, arr);
            if (cnt > k) low = mid;
            else high = mid;
        }

        return high;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;

    GasStationOptimizer optimizer;
    long double ans = optimizer.minimiseMaxDistance(arr, k);

    cout << "The answer is: " << ans << "\n";
    return 0;
}