#include <bits/stdc++.h>
using namespace std;

// Function to perform Binary Search on a sorted array
int binarySearch(vector<int>& nums, int target) {

    int n = nums.size();   // Size of the array
    int low = 0;
    int high = n - 1;

    // Continue searching until low crosses high
    while (low <= high) {

        // Find the middle index
        int mid = low + (high - low) / 2;

        // Target found
        if (nums[mid] == target)
            return mid;

        // Search in the right half
        else if (target > nums[mid])
            low = mid + 1;

        // Search in the left half
        else
            high = mid - 1;
    }

    // Target not found
    return -1;
}

int main() {

    // Sorted array
    vector<int> nums = {3, 4, 6, 7, 9, 12, 16, 17};

    // Element to search
    int target = 6;

    // Call Binary Search function
    int index = binarySearch(nums, target);

    // Print the result
    if (index == -1)
        cout << "The target is not present." << endl;
    else
        cout << "The target is at index: " << index << endl;

    return 0;
}


// // recursive approach
// #include <bits/stdc++.h>
// using namespace std;

// // Recursive Binary Search Function
// int binarySearch(vector<int>& nums, int low, int high, int target) {

//     // Base Case:
//     // If low crosses high, target is not present
//     if (low > high)
//         return -1;

//     // Find middle index
//     int mid = low + (high - low) / 2;

//     // Target found
//     if (nums[mid] == target)
//         return mid;

//     // Search in the right half
//     else if (target > nums[mid])
//         return binarySearch(nums, mid + 1, high, target);

//     // Search in the left half
//     else
//         return binarySearch(nums, low, mid - 1, target);
// }

// // Wrapper Function
// int search(vector<int>& nums, int target) {

//     return binarySearch(nums, 0, nums.size() - 1, target);
// }

// int main() {

//     // Sorted array
//     vector<int> nums = {3, 4, 6, 7, 9, 12, 16, 17};

//     // Target element
//     int target = 6;

//     // Call the search function
//     int index = search(nums, target);

//     // Print the result
//     if (index == -1)
//         cout << "The target is not present." << endl;
//     else
//         cout << "The target is at index: " << index << endl;

//     return 0;
// }