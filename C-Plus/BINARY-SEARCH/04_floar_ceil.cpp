// Floor of $X$: The largest element in the array that is $\le X$ (less than or equal to $X$)
// Ceil of $X$: The smallest element in the array that is $\ge X$ (greater than or equal to $X$).
#include <bits/stdc++.h>
using namespace std;

// Function to find the Floor of x
int findFloor(vector<int>& arr, int x) {

    int low = 0;
    int high = arr.size() - 1;

    // Default answer
    int ans = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        // Current element can be the floor
        if (arr[mid] <= x) {

            ans = arr[mid];

            // Search on the right side for a larger floor
            low = mid + 1;
        }
        else {

            // Search on the left side
            high = mid - 1;
        }
    }

    return ans;
}

// Function to find the Ceil of x
int findCeil(vector<int>& arr, int x) {

    int low = 0;
    int high = arr.size() - 1;

    // Default answer
    int ans = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        // Current element can be the ceil
        if (arr[mid] >= x) {

            ans = arr[mid];

            // Search on the left side for a smaller ceil
            high = mid - 1;
        }
        else {

            // Search on the right side
            low = mid + 1;
        }
    }

    return ans;
}

// Function to return both Floor and Ceil
pair<int, int> getFloorAndCeil(vector<int>& arr, int x) {

    int floor = findFloor(arr, x);
    int ceil = findCeil(arr, x);

    return {floor, ceil};
}

int main() {

    // Sorted array
    vector<int> arr = {3, 4, 4, 7, 8, 10};

    // Target value
    int x = 5;

    // Find floor and ceil
    pair<int, int> ans = getFloorAndCeil(arr, x);

    cout << "Floor = " << ans.first << endl;
    cout << "Ceil  = " << ans.second << endl;

    return 0;
} 