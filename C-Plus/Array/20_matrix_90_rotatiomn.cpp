/*
=============================================================
  PROBLEM : Rotate Image (90° Clockwise)
  Platform : LeetCode #48 (Medium)
  Sheet    : Striver A2Z DSA (Arrays - Medium)

  Rotate N×N matrix 90° clockwise IN-PLACE.
  DO NOT use an extra matrix.

  Example:
    [[1,2,3],[4,5,6],[7,8,9]] → [[7,4,1],[8,5,2],[9,6,3]]

  KEY INSIGHT:
    90° clockwise = Transpose + Reverse each row

  NOTE: 2D matrix → vector<vector<int>> used throughout.

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ rotate_image.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>>& mat) {
    for (auto& row : mat) {
        cout << "[ ";
        for (int x : row) cout << x << " ";
        cout << "]" << endl;
    }
    cout << endl;
}


// =============================================================
// METHOD 1 — BRUTE FORCE
// Idea : Create a new matrix
//        Place element (i,j) at position (j, n-1-i) in new matrix
//        Copy new matrix back to original
// Formula: new[j][n-1-i] = matrix[i][j]
// Time : O(N^2)   Space: O(N^2)
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

void rotateBrute(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> temp(n, vector<int>(n)); // extra N×N matrix

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[j][n - 1 - i] = matrix[i][j];  // (i,j) → (j, n-1-i)

    matrix = temp;   // copy back to original
}

int main() {
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};

    cout << "===== BRUTE FORCE =====" << endl;
    cout << "Input:" << endl;  printMatrix(mat);
    rotateBrute(mat);
    cout << "Output:" << endl; printMatrix(mat);  // [[7,4,1],[8,5,2],[9,6,3]]

    // 4×4 test
    vector<vector<int>> mat2 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    cout << "4x4 Input:" << endl;  printMatrix(mat2);
    rotateBrute(mat2);
    cout << "4x4 Output:" << endl; printMatrix(mat2);

    return 0;
}


// =============================================================
// METHOD 2 — OPTIMAL (Transpose + Reverse)  <- SUBMIT THIS
//
// 90° clockwise = 2 simple in-place steps:
//
// STEP 1 — TRANSPOSE:
//   Swap matrix[i][j] with matrix[j][i]
//   Only iterate upper triangle (j > i) to avoid double swap
//
//   [[1,2,3],      [[1,4,7],
//    [4,5,6],  →    [2,5,8],
//    [7,8,9]]       [3,6,9]]
//
// STEP 2 — REVERSE each row:
//   Use two pointers or reverse() on each row
//
//   [[1,4,7],      [[7,4,1],
//    [2,5,8],  →    [8,5,2],
//    [3,6,9]]       [9,6,3]]  ✅
//
// WHY THIS WORKS:
//   Transpose: (i,j) → (j,i)
//   Row reverse: (i,j) → (i, n-1-j)
//   Combined: (i,j) → (j, n-1-i) = exact 90° clockwise formula
//
// Time : O(N^2)   Space: O(1) — fully in-place!
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
void rotateOptimal(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // ── Step 1: Transpose ─────────────────────────────────────
    // Only swap upper triangle (i < j) to avoid undoing swaps
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)     // j starts from i+1 !
            swap(matrix[i][j], matrix[j][i]);

    // ── Step 2: Reverse each row ──────────────────────────────
    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}

int main() {
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};

    cout << "===== OPTIMAL (Transpose + Reverse) =====" << endl;
    cout << "Input:" << endl;  printMatrix(mat);
    rotateOptimal(mat);
    cout << "Output:" << endl; printMatrix(mat);  // [[7,4,1],[8,5,2],[9,6,3]]

    // 4×4 test
    vector<vector<int>> mat2 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    cout << "4x4 Input:" << endl;  printMatrix(mat2);
    rotateOptimal(mat2);
    cout << "4x4 Output:" << endl; printMatrix(mat2);

    // 1×1 edge case
    vector<vector<int>> mat3 = {{7}};
    rotateOptimal(mat3);
    cout << "1x1 [7] → "; printMatrix(mat3);   // [[7]]

    return 0;
}
*/


// =============================================================
// JUDGE CODE — LeetCode #48
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose (swap across diagonal)
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};
*/