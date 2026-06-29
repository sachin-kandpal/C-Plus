// brute force approach
#include <bits/stdc++.h>
using namespace std;

// Function to find both first and last occurrence
pair<int, int> firstLastOccurrence(vector<int>& arr, int target) {

    int first = -1;
    int last = -1;

    // Traverse the entire array
    for (int i = 0; i < arr.size(); i++) {

        if (arr[i] == target) {

            // First occurrence
            if (first == -1)
                first = i;

            // Update last occurrence every time
            last = i;
        }
    }

    return {first, last};
}

int main() {

    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};

    int target = 8;

    pair<int, int> ans = firstLastOccurrence(arr, target);

    cout << "First Occurrence = " << ans.first << endl;
    cout << "Last Occurrence  = " << ans.second << endl;

    return 0;
}

// // optimized approach
// #include <bits/stdc++.h>
// using namespace std;

// // find last index of key using binary search
// int solve(int n, int key, vector<int>& v) {
//   // initialize search bounds and result
//   int start = 0;
//   int end = n - 1;
//   int res = -1;

//   // binary search loop
//   while (start <= end) {
//     // compute mid safely
//     int mid = start + (end - start) / 2;
//     // when match found, store index and move right
//     if (v[mid] == key) {
//       res = mid;
//       start = mid + 1;
//     }
//     // when key is smaller, move left
//     else if (key < v[mid]) {
//       end = mid - 1;
//     }
//     // otherwise move right
//     else {
//       start = mid + 1;
//     }
//   }
//   // return last occurrence or -1
//   return res;
// }

// // program entry
// int main() {
//   // define input size and key
//   int n = 7;
//   int key = 13;
//   // define sorted array
//   vector<int> v = {3, 4, 13, 13, 13, 20, 40};
//   // print last occurrence index (or -1)
//   cout << solve(n, key, v) << "\n";
//   // exit
//   return 0;
// }
