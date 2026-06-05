#include <bits/stdc++.h>
using namespace std;

// Function to perform Insertion Sort
void insertion_sort(int arr[], int n) {
    // Outer loop runs from 0 to n-1, selecting one element at a time
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        
        // Inner loop shifts the element backwards into its correct sorted position
        while (j > 0 && arr[j - 1] > arr[j]) {
            // Swap adjacent elements
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            
            j--; // Move leftward
        }
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

    // 3. Call the insertion sort function
    insertion_sort(arr, n);

    // 4. Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}