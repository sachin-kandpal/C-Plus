// brute force
#include <bits/stdc++.h>
using namespace std;

// Class to encapsulate search logic
class Solution {
public:
    // Linear search in rotated sorted array (with duplicates)
    bool searchInARotatedSortedArrayII(vector<int>& arr, int k) {
        int n = arr.size(); // size of the array
        for (int i = 0; i < n; i++) {
            if (arr[i] == k) return true; // if found, return true
        }
        return false; // not found
    }
};

int main() {
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;

    // Create object of Solution class
    Solution obj;
    bool ans = obj.searchInARotatedSortedArrayII(arr, k);

    // Print result
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";

    return 0;
}


// optimal approach
#include <bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // If mid points to the target
        if (arr[mid] == k) return true;

        // Edge case: all three are equal, we cannot determine which side is sorted
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }

        // If the left half is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                high = mid - 1; // Target lies in left
            } else {
                low = mid + 1;  // Target lies in right
            }
        } else {
            // Right half is sorted
            if (arr[mid] <= k && k <= arr[high]) {
                low = mid + 1;  // Target lies in right
            } else {
                high = mid - 1; // Target lies in left
            }
        }
    }

    return false;
}

int main() {
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;
    bool ans = searchInARotatedSortedArrayII(arr, k);
    if (ans)
        cout << "Target is present in the array.\n";
    else
        cout << "Target is not present.\n";
    return 0;
}


