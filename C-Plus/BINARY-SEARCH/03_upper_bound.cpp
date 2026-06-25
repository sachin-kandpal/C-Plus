// upper bound has only one difference that is that we have to find the first index which element is greater then target
// arr[mid]>x   -> no =(equal to)
// brute-force approach to find the Upper Bound of a given element in a sorted array using Linear Search
#include <bits/stdc++.h>
using namespace std;

// Function to find the Upper Bound using Linear Search
int upperBound(vector<int>& arr, int x) {

    int n = arr.size();

    // Traverse the array
    for (int i = 0; i < n; i++) {

        // First element strictly greater than x
        if (arr[i] > x) {
            return i;
        }
    }

    // If no such element exists
    return n;
}

int main() {

    // Sorted array
    vector<int> arr = {3, 5, 8, 9, 15, 19};

    // Target value
    int x = 9;

    // Call the function
    int index = upperBound(arr, x);

    cout << "The Upper Bound Index is: " << index << endl;

    return 0;
}

// optimal solution
// #include <bits/stdc++.h>
// using namespace std;

// // Function to find the Lower Bound using Binary Search
// int lowerBound(vector<int>& arr, int x) {

//     int n = arr.size();

//     int low = 0;
//     int high = n - 1;

//     // Default answer
//     // If no element is >= x, return n
//     int ans = n;

//     // Binary Search
//     while (low <= high) {

//         // Find the middle index
//         int mid = low + (high - low) / 2;

//         // Current element can be a lower bound
//         if (arr[mid] > x) {

//             ans = mid;

//             // Search on the left side
//             // to find an even smaller index
//             high = mid - 1;
//         }
//         else {

//             // Search on the right side
//             low = mid + 1;
//         }
//     }

//     return ans;
// }

// int main() {

//     // Sorted array
//     vector<int> arr = {3, 5, 8, 15, 19};

//     // Target value
//     int x = 9;

//     // Call the function
//     int index = lowerBound(arr, x);

//     cout << "The Lower Bound Index is: " << index << endl;

//     return 0;
// }