// brute force approach
#include <bits/stdc++.h>
using namespace std;

// Function to find both first and last occurrence
pair<int, int> firstLastOccurrence(vector<int>& arr, int target) {

    int first = -1;
    int last = -1;

    // Traverse the entire array
    for (int i = 0; i < arr.size(); i++) {

        if (arr[i] == target) {

            // First occurrence
            if (first == -1)
                first = i;

            // Update last occurrence every time
            last = i;
        }
    }

    return {first, last};
}

int main() {

    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};

    int target = 8;

    pair<int, int> ans = firstLastOccurrence(arr, target);

    cout << "First Occurrence = " << ans.first << endl;
    cout << "Last Occurrence  = " << ans.second << endl;

    return 0;
}

// // optimized approach
// #include <bits/stdc++.h>
// using namespace std;

// // Function to find Lower Bound
// int lowerBound(vector<int>& arr, int target) {

//     int low = 0;
//     int high = arr.size() - 1;
//     int ans = arr.size();

//     while (low <= high) {

//         int mid = low + (high - low) / 2;

//         if (arr[mid] >= target) {
//             ans = mid;
//             high = mid - 1;
//         }
//         else {
//             low = mid + 1;
//         }
//     }

//     return ans;
// }

// // Function to find Upper Bound
// int upperBound(vector<int>& arr, int target) {

//     int low = 0;
//     int high = arr.size() - 1;
//     int ans = arr.size();

//     while (low <= high) {

//         int mid = low + (high - low) / 2;

//         if (arr[mid] > target) {
//             ans = mid;
//             high = mid - 1;
//         }
//         else {
//             low = mid + 1;
//         }
//     }

//     return ans;
// }

// int main() {

//     vector<int> arr = {2,4,6,8,8,8,11,13};

//     int target = 8;

//     int first = lowerBound(arr, target);

//     // Target not found
//     if (first == arr.size() || arr[first] != target) {
//         cout << "First Occurrence = -1" << endl;
//         cout << "Last Occurrence  = -1" << endl;
//         return 0;
//     }

//     int last = upperBound(arr, target) - 1;

//     cout << "First Occurrence = " << first << endl;
//     cout << "Last Occurrence  = " << last << endl;

//     return 0;
// }