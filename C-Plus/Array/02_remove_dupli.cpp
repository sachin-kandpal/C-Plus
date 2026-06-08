#include <iostream>
using namespace std;

int main() {

    int n;

    // Input size of array
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];

    // Input array elements
    cout << "Enter sorted array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // If array is empty
    if(n == 0) {
        cout << "Array is empty";
        return 0;
    }

    // k points to the last unique element
    int k = 0;

    // Traverse the array
    for(int i = 1; i < n; i++) {

        // If current element is different,
        // it is a new unique element
        if(arr[i] != arr[k]) {

            k++;

            // Place the unique element at next position
            arr[k] = arr[i];
        }
    }

    // Print array after removing duplicates
    cout << "\nArray after removing duplicates:\n";

    for(int i = 0; i <= k; i++) {
        cout << arr[i] << " ";
    }

    // Number of unique elements
    cout << "\n\nNumber of unique elements = " << k + 1;

    return 0;
}