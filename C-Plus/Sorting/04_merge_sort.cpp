#include <bits/stdc++.h>
using namespace std;

// Function to merge two sorted halves back into a single sorted section
void merge(int arr[], int low, int mid, int high) {
    vector<int> temp; // Temporary array to store the sorted elements
    int left = low;      // Starting index of the left half
    int right = mid + 1; // Starting index of the right half

    // Compare elements from both halves and push the smaller one into temp
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // If elements are left over in the left half, copy them
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // If elements are left over in the right half, copy them
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Transfer all elements from temp back into the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Recursive function to divide the array
void merge_sort(int arr[], int low, int high) {
    // Base case: If the section has 1 or 0 elements, it's already sorted
    if (low >= high) return;

    int mid = low + (high - low) / 2;

    merge_sort(arr, low, mid);      // Sort the left half
    merge_sort(arr, mid + 1, high);  // Sort the right half
    
    merge(arr, low, mid, high);     // Merge the sorted halves
}

int main() {
    // 1. Read the size of the array
    int n;
    cin >> n;

    // 2. Read the elements into the array
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 3. Call the merge sort function passing (array, starting_index, ending_index)
    merge_sort(arr, 0, n - 1);

    // 4. Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}



//                            MERGE SORT CHEAT SHEET
// ==============================================================================
//
//  SCENARIO      |  TIME COMPLEXITY            |  SPACE COMPLEXITY
//  --------------|-----------------------------|-------------------------------
//  Best Case     |  O(N log N)                 |  O(N) 
//  Average Case  |  O(N log N)                 |  O(N) -> Due to temporary vector
//  Worst Case    |  O(N log N)                 |  O(N)    used during merge step