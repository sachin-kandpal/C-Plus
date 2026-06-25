// also same code for search insert position


// BRUTE FORCE  
#include <bits/stdc++.h>
using namespace std;

// Function to find the Lower Bound
int lowerBound(vector<int>& arr, int x) {

    int n = arr.size();

    // Traverse the array
    for (int i = 0; i < n; i++) {

        // First element greater than or equal to x
        if (arr[i] >= x) {
            return i;
        }
    }

    // If no such element exists,
    // return n
    return n;
}

int main() {

    // Sorted array
    vector<int> arr = {3, 5, 8, 15, 19};

    // Target element
    int x = 9;

    // Call lowerBound function
    int index = lowerBound(arr, x);

    cout << "The lower bound index is: " << index << endl;

    return 0;
}



// // optimal solution
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
//         if (arr[mid] >= x) {

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