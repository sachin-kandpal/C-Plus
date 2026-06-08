
// Second largest in array

#include <bits/stdc++.h>
using namespace std;

// Function to find the second largest element in the array
int secondLargest(vector<int> &a, int n) {
    int largest = a[0];
    int slargest = -1;

    for (int i = 1; i < n; i++) {
        if (a[i] > largest) {
            slargest = largest;
            largest = a[i];
        } 
        else if (a[i] < largest && a[i] > slargest) {
            slargest = a[i];
        }
    }
    return slargest;
}

// Function to find the second smallest element in the array
int secondSmallest(vector<int> &a, int n) {
    int smallest = a[0];
    int ssmallest = INT_MAX; // Initialized to a very large value

    for (int i = 1; i < n; i++) {
        if (a[i] < smallest) {
            ssmallest = smallest;
            smallest = a[i];
        } 
        else if (a[i] != smallest && a[i] < ssmallest) {
            ssmallest = a[i];
        }
    }
    return ssmallest;
}

// Wrapper function matching the CodeStudio signature
vector<int> getSecondOrderElements(int n, vector<int> a) {
    int slargest = secondLargest(a, n);
    int ssmallest = secondSmallest(a, n);

    return {slargest, ssmallest};
}

int main() {
    // Sample test case
    vector<int> arr = {1, 2, 4, 7, 7, 5};
    int n = arr.size();

    vector<int> result = getSecondOrderElements(n, arr);

    cout << "Second Largest: " << result[0] << endl;
    cout << "Second Smallest: " << result[1] << endl;

    return 0;
}


