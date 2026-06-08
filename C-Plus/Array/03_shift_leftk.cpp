// #include <bits/stdc++.h>
// using namespace std;

// int main() {

//     int n;

//     // Input size of vector
//     cout << "Enter size: ";
//     cin >> n;

//     vector<int> nums(n);

//     // Input elements
//     cout << "Enter elements: ";
//     for(int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }

//     // Store first element
//     int temp = nums[0];

//     // Shift all elements one position to the left
//     for(int i = 1; i < n; i++) {
//         nums[i - 1] = nums[i];
//     }

//     // Put first element at the last position
//     nums[n - 1] = temp;

//     // Print rotated array
//     cout << "Array after left rotation by one:\n";

//     for(int i = 0; i < n; i++) {
//         cout << nums[i] << " ";
//     }

//     return 0;
// }




// // shift left by k
// #include <bits/stdc++.h>
// using namespace  std;

// // Function to left-rotate an array by d steps
// void leftRotate(int arr[], int n, int d) {
//     // Handle cases where d is greater than or equal to n
//     d = d % n; 

//     // 1. Store the first d elements in a temporary array
//     int temp[d];
//     for (int i = 0; i < d; i++) {
//         temp[i] = arr[i];
//     }

//     // 2. Shift the remaining elements of the array to the left
//     for (int i = d; i < n; i++) {
//         arr[i - d] = arr[i];
//     }

//     // 3. Copy the elements back from the temporary array to the end
//     for (int i = n - d; i < n; i++) {
//         arr[i] = temp[i - (n - d)];
//     }
// }

// int main() {
//     int n;
//     // Input the size of the array
//     cin >> n;
    
//     int arr[n];
//     // Input the array elements
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int d;
//     // Input the number of steps to rotate
//     cin >> d;

//     // Call the rotation logic
//     leftRotate(arr, n, d);

//     // Print the rotated array
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

// shift left by k  optimized approach known as the Reversal Algorithm
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm> // Contains std::reverse

using namespace std;

void leftRotate(int arr[], int n, int d) {
    // Handle cases where d >= n
    d = d % n; 
    
    // Step 1: Reverse first d elements
    reverse(arr, arr + d);
    
    // Step 2: Reverse remaining elements
    reverse(arr + d, arr + n);
    
    // Step 3: Reverse the entire array
    reverse(arr, arr + n);
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int d;
    cin >> d;

    leftRotate(arr, n, d);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}