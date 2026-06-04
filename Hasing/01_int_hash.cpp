#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1. Take the size of the array as input
    int n;
    cin >> n;
    
    // 2. Read the elements into the array
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 3. Precompute frequencies using a Hash Array
    // We choose size 13 assuming the maximum element in our input won't exceed 12.
    // Initializing with {0} ensures all frequencies start at zero.
    int hash[13] = {0}; 
    for (int i = 0; i < n; i++) {
        hash[arr[i]] += 1; // Increment the count at the index equal to the element value
    }

    // 4. Handle the queries
    int q;
    cin >> q; // Read total number of queries
    while (q--) {
        int number;
        cin >> number; // Read the specific number we want to search for
        
        // Fetch the count in O(1) time complexity
        cout << hash[number] << endl;
    }

    return 0;
}




// The Memory Limitation (Array Size Limit)
// If you declare an array inside the main() function,
//  your computer allocates memory on the stack.
//   The maximum array size you can declare here is roughly $10^6$ elements.
//   If you declare it globally, it goes into the data segment,
//    allowing a size up to $10^7$.The Problem: If your input
//    array contains a number like 1,000,000,000 ($10^9$), you would need 
//    an array of size $10^9 + 1$. Trying to allocate an array that big will instantly 
//    crash your program with a Segmentation Fault (Memory Limit Exceeded).