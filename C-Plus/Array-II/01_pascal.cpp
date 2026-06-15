// // TO PRINT A PARTICULAR ROW OF PASCAL'S TRIANGLE
// #include <bits/stdc++.h>
// using namespace std;

// void printPascalRow(int n) {

//     long long ans = 1;
//     cout << ans << " ";

//     // n is 1-based row number
//     for (int i = 1; i < n; i++) {

//         ans = ans * (n - i);
//         ans = ans / i;

//         cout << ans << " ";
//     }

//     cout << endl;
// }

// int main() {

//     int n = 5;   // Print 5th row

//     printPascalRow(n);

//     return 0;
// }


// // TO PRINT THE ELEMENT AT (i,j) OF PASCAL'S TRIANGLE
// #include <bits/stdc++.h>
// using namespace std;

// // Function to calculate nCr
// long long nCr(int n, int r) {

//     long long ans = 1;

//     for (int i = 0; i < r; i++) {
//         ans = ans * (n - i);
//         ans = ans / (i + 1);
//     }

//     return ans;
// }

// int main() {

//     int row = 5;
//     int col = 3;

//     // Convert to 0-based for nCr
//     cout << nCr(row - 1, col - 1) << endl;

//     return 0;
// }



// TO PRINT THE ENTIRE PASCAL'S TRIANGLE

// // BRUTE FORCE: O(N^3) — calculate each element with nCr formula
// #include <bits/stdc++.h>
// using namespace std;

// // Function to calculate nCr
// long long nCr(int n, int r) {

//     long long ans = 1;

//     for (int i = 0; i < r; i++) {
//         ans = ans * (n - i);
//         ans = ans / (i + 1);
//     }

//     return ans;
// }

// int main() {

//     int numRows = 5;

//     vector<vector<int>> triangle;

//     for (int row = 1; row <= numRows; row++) {

//         vector<int> temp;

//         for (int col = 1; col <= row; col++) {
//             temp.push_back((int)nCr(row - 1, col - 1));
//         }

//         triangle.push_back(temp);
//     }

//     // Print Pascal Triangle
//     for (auto &r : triangle) {
//         for (auto x : r) {
//             cout << x << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }


// OPTIMAL: O(N^2) — generate each row iteratively using previous row
#include <bits/stdc++.h>
using namespace std;

// Function to generate one row
vector<int> generateRow(int row) {

    vector<int> temp;
    long long ans = 1;

    temp.push_back(1);

    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        temp.push_back((int)ans);
    }

    return temp;
}

int main() {

    int numRows = 5;

    vector<vector<int>> triangle;

    for (int row = 1; row <= numRows; row++) {
        triangle.push_back(generateRow(row));
    }

    // Print Pascal Triangle
    for (auto &r : triangle) {
        for (auto x : r) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

// // JUDGE CODE — LeetCode #118
// class Solution {
// public:

//     vector<int> generateRow(int row) {

//         vector<int> temp;
//         long long ans = 1;

//         temp.push_back(1);

//         for (int col = 1; col < row; col++) {
//             ans = ans * (row - col);
//             ans = ans / col;
//             temp.push_back((int)ans);
//         }

//         return temp;
//     }

//     vector<vector<int>> generate(int numRows) {

//         vector<vector<int>> result;

//         for (int row = 1; row <= numRows; row++) {
//             result.push_back(generateRow(row));
//         }

//         return result;
//     }
// };