#include <bits/stdc++.h>
using namespace std;

// Function to perform Selection Sort
void selection_sort(int arr[], int n) {
    // The outer loop runs from 0 to n-2
    for (int i = 0; i <= n - 2; i++) {
        int mini = i; // Assume the current element is the minimum
        
        // Inner loop finds the actual minimum element in the remaining unsorted part
        for (int j = i; j <= n - 1; j++) {
            if (arr[j] < arr[mini]) {
                mini = j; // Update the index of the minimum element
            }
        }
        
        // Swap the found minimum element with the first element of the unsorted part
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
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

    // 3. Call the selection sort function
    selection_sort(arr, n);

    // 4. Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}