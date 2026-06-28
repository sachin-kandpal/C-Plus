// brute force approach
#include <bits/stdc++.h>
using namespace std;

// find last index of key by scanning from right
int solve(int n, int key, vector<int>& v) {
  // initialize result as not found
  int res = -1;
  // scan from the end toward the start
  for (int i = n - 1; i >= 0; i--) {
    // update and stop when match found
    if (v[i] == key) {
      res = i;
      break;
    }
  }
  // return index or -1
  return res;
}

// program entry
int main() {
  // set size
  int n = 7;
  // set key to search
  int key = 13;
  // define input array
  vector<int> v = {3, 4, 13, 13, 13, 20, 40};
  // print last occurrence index (or -1)
  cout << solve(n, key, v) << "\n";
  // exit
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