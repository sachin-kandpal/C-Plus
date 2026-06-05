#include <bits/stdc++.h>
using namespace std;

// Function to perform Optimized Bubble Sort
void bubble_sort(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        int didSwap = 0; // Reset flag for this pass
        
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                
                didSwap = 1; // Mark that a swap occurred
            }
        }
        
        // If no two elements were swapped by inner loop, then break
        if (didSwap == 0) {
            break;
        }
        
        // This print statement is just to see how many outer loops actually ran
        cout << "runs" << endl;
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubble_sort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}