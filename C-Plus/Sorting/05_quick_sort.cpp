#include <bits/stdc++.h>
using namespace std;

// Function to find the partition index
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Choosing the first element as the pivot
    int i = low;
    int j = high;

    while (i < j) {
        // Move 'i' forward to find the first element greater than the pivot
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        
        // Move 'j' backward to find the first element smaller than or equal to the pivot
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }

        // If pointers haven't crossed, swap the elements at i and j
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    
    // Final step: Place the pivot in its correct sorted position by swapping with arr[j]
    swap(arr[low], arr[j]);
    
    return j; // Return the partition index where the pivot settled
}

// Recursive function to perform Quick Sort
void quick_sort(int arr[], int low, int high) {
    // Base Case: If the subarray has 1 or 0 elements, it's already sorted
    if (low < high) {
        // Step 1: Put the pivot in its correct spot and get its index
        int partition_index = partition(arr, low, high);
        
        // Step 2: Recursively sort the left and right halves around the pivot
        quick_sort(arr, low, partition_index - 1);  // Left side of pivot
        quick_sort(arr, partition_index + 1, high); // Right side of pivot
    }
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

    // 3. Call the quick sort function passing (array, starting_index, ending_index)
    quick_sort(arr, 0, n - 1);

    // 4. Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}