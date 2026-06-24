// Given an integer array nums. Return the number of inversions in the array.
// Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
// It indicates how close an array is to being sorted.
// A sorted array has an inversion count of 0.
// An array sorted in descending order has maximum inversion


// brute force approach is to use two loops and check for every pair of elements if they form an inversion or not. This will take O(n^2) time complexity. A better approach is to use merge sort which takes O(nlogn) time complexity.
#include <bits/stdc++.h>
using namespace std;

// Function to count inversions using brute force
long long numberOfInversions(vector<int>& nums) {
    int n = nums.size();
    long long count = 0; // counter for inversions, long long to avoid overflow

    // outer loop picks the first element of the pair
    for (int i = 0; i < n; i++) {
        // inner loop picks the second element of the pair, always after i
        for (int j = i + 1; j < n; j++) {
            if (nums[i] > nums[j]) {
                count++; // nums[i] and nums[j] form an inversion
            }
        }
    }
    return count;
}

int main() {
    vector<int> nums = {2, 3, 7, 1, 3, 5}; // sample input

    long long ans = numberOfInversions(nums);

    cout << "Number of Inversions: " << ans << endl; // expected output: 5

    return 0;
}

// // optimal approach using merge sort
// #include <bits/stdc++.h>
// using namespace std;

// // Merges arr[low..mid] and arr[mid+1..high], counts cross-inversions
// long long mergeAndCount(vector<int>& arr, int low, int mid, int high) {
//     vector<int> temp; // temp storage for merged sorted segment
//     int left = low;       // pointer into left half
//     int right = mid + 1;  // pointer into right half
//     long long count = 0;  // inversions found during this merge

//     // compare elements from both halves and merge in sorted order
//     while (left <= mid && right <= high) {
//         if (arr[left] <= arr[right]) {
//             // no inversion, left element is already in correct relative order
//             temp.push_back(arr[left]);
//             left++;
//         } else {
//             // arr[left] > arr[right]
//             // since left half (arr[left..mid]) is sorted ascending,
//             // ALL elements from current 'left' to 'mid' are > arr[right]
//             count += (mid - left + 1); // batch-count these inversions
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }

//     // if left half has leftover elements, copy them (no more comparisons needed)
//     while (left <= mid) {
//         temp.push_back(arr[left]);
//         left++;
//     }

//     // if right half has leftover elements, copy them
//     while (right <= high) {
//         temp.push_back(arr[right]);
//         right++;
//     }

//     // place merged sorted elements back into original array
//     for (int i = low; i <= high; i++) {
//         arr[i] = temp[i - low];
//     }

//     return count;
// }

// // Recursive function: sorts arr[low..high] and returns total inversions in that range
// long long mergeSortAndCount(vector<int>& arr, int low, int high) {
//     long long count = 0;

//     // base case: a single element (or invalid range) has no inversions
//     if (low >= high) return 0;

//     int mid = (low + high) / 2;

//     // count inversions in left half recursively
//     count += mergeSortAndCount(arr, low, mid);

//     // count inversions in right half recursively
//     count += mergeSortAndCount(arr, mid + 1, high);

//     // count inversions formed between left half and right half during merge
//     count += mergeAndCount(arr, low, mid, high);

//     return count;
// }

// int main() {
//     vector<int> nums = {2, 3, 7, 1, 3, 5}; // sample input
//     int n = nums.size();

//     long long ans = mergeSortAndCount(nums, 0, n - 1);

//     cout << "Number of Inversions: " << ans << endl; // expected output: 5

//     return 0;
// }

