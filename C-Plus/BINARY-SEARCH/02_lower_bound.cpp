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