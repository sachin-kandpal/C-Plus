/*
=============================================================
  PROBLEM : Set Matrix Zeroes
  Platform : TUF+ / LeetCode #73 (Medium)
  Sheet    : Striver A2Z DSA (Arrays - Medium)

  If matrix[i][j] == 0, set entire row i and col j to 0.
  Must be done IN-PLACE.

  Example:
    [[1,1,1],[1,0,1],[1,1,1]]  →  [[1,0,1],[0,0,0],[1,0,1]]
    [[0,1,2],[3,4,5],[1,0,1]]  →  [[0,0,0],[0,4,5],[0,0,0]]

  NOTE: 2D matrix → vector<vector<int>> used throughout
        since 2D raw arrays are messy to pass as parameters.

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ set_matrix_zeroes.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>>& mat) {
    for (auto& row : mat) {
        cout << "[";
        for (int j = 0; j < (int)row.size(); j++)
            cout << row[j] << (j < (int)row.size()-1 ? ", " : "");
        cout << "]" << endl;
    }
    cout << endl;
}


// =============================================================
// METHOD 1 — BRUTE FORCE
// Idea : Use -1 as a temporary marker (assuming no -1 in input)
//        Pass 1: wherever 0 found → mark entire row+col as -1
//        Pass 2: convert all -1 to 0
// Time : O((N*M)*(N+M))   Space: O(1) — in-place with markers
// NOTE : Only works if -1 is NOT a valid matrix value!
//        Safe general version would need a copy → O(N*M) space
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

void setZeroesBrute(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    // Pass 1: for every 0, mark its row and col with -1
    //         (skip cells already 0 to avoid double processing)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {

                // mark entire row with -1 (skip existing 0s)
                for (int k = 0; k < m; k++)
                    if (matrix[i][k] != 0) matrix[i][k] = -1;

                // mark entire col with -1 (skip existing 0s)
                for (int k = 0; k < n; k++)
                    if (matrix[k][j] != 0) matrix[k][j] = -1;
            }
        }
    }

    // Pass 2: convert all -1 to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == -1) matrix[i][j] = 0;
}

int main() {
    vector<vector<int>> mat = {{1,1,1},{1,0,1},{1,1,1}};

    cout << "===== BRUTE FORCE =====" << endl;
    cout << "Input:" << endl; printMatrix(mat);
    setZeroesBrute(mat);
    cout << "Output:" << endl; printMatrix(mat);

    vector<vector<int>> mat2 = {{0,1,2},{3,4,5},{1,0,1}};
    cout << "Input:" << endl; printMatrix(mat2);
    setZeroesBrute(mat2);
    cout << "Output:" << endl; printMatrix(mat2);

    return 0;
}


// =============================================================
// METHOD 2 — BETTER (Row + Col Marker Arrays)
// Idea : rowZero[i]=true if row i has zero
//        colZero[j]=true if col j has zero
//        Pass 1: mark rows and cols
//        Pass 2: zero out marked rows and cols
// Time : O(N*M)   Space: O(N+M)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
void setZeroesBetter(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<bool> rowZero(n, false);   // rowZero[i] = row i has a zero
    vector<bool> colZero(m, false);   // colZero[j] = col j has a zero

    // Pass 1: find which rows and cols have zeros
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == 0) {
                rowZero[i] = true;
                colZero[j] = true;
            }

    // Pass 2: set zeros based on markers
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (rowZero[i] || colZero[j])
                matrix[i][j] = 0;
}

int main() {
    vector<vector<int>> mat = {{1,1,1},{1,0,1},{1,1,1}};

    cout << "===== BETTER (Marker Arrays) =====" << endl;
    cout << "Input:" << endl; printMatrix(mat);
    setZeroesBetter(mat);
    cout << "Output:" << endl; printMatrix(mat);

    vector<vector<int>> mat2 = {{0,1,2},{3,4,5},{1,0,1}};
    cout << "Input:" << endl; printMatrix(mat2);
    setZeroesBetter(mat2);
    cout << "Output:" << endl; printMatrix(mat2);

    return 0;
}
*/


// =============================================================
// METHOD 3 — OPTIMAL (First Row/Col as Markers)  <- SUBMIT
//
// Use matrix[0][j] to mark "col j needs zeroing"
// Use matrix[i][0] to mark "row i needs zeroing"
// matrix[0][0] is shared → handle col 0 separately with col0 var
//
// Steps:
//   1. Check if col 0 has any zero → store in bool col0
//   2. Scan matrix: if matrix[i][j]==0 → mark matrix[i][0] and matrix[0][j]
//   3. Zero inner cells [1..n-1][1..m-1] based on markers
//   4. Zero row 0 if matrix[0][0]==0
//   5. Zero col 0 if col0==true
//
// Must process inner cells BEFORE row 0 and col 0
// to avoid corrupting the markers prematurely
//
// Time : O(N*M)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
void setZeroesOptimal(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    bool col0 = false;   // separate flag for column 0

    // Step 1 & 2: scan matrix, mark first row/col as indicators
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;          // mark row i via first col

                if (j == 0)
                    col0 = true;            // col 0 itself has a zero
                else
                    matrix[0][j] = 0;      // mark col j via first row
            }
        }
    }

    // Step 3: zero out inner matrix [1..n-1][1..m-1] using markers
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    // Step 4: handle first row (controlled by matrix[0][0])
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++)
            matrix[0][j] = 0;
    }

    // Step 5: handle first col (controlled by col0 flag)
    if (col0) {
        for (int i = 0; i < n; i++)
            matrix[i][0] = 0;
    }
}

int main() {
    vector<vector<int>> mat = {{1,1,1},{1,0,1},{1,1,1}};

    cout << "===== OPTIMAL (First Row/Col Markers) =====" << endl;
    cout << "Input:" << endl; printMatrix(mat);
    setZeroesOptimal(mat);
    cout << "Output:" << endl; printMatrix(mat);

    vector<vector<int>> mat2 = {{0,1,2},{3,4,5},{1,0,1}};
    cout << "Input:" << endl; printMatrix(mat2);
    setZeroesOptimal(mat2);
    cout << "Output:" << endl; printMatrix(mat2);

    // now your turn test
    vector<vector<int>> mat3 = {{1,2,3,4},{5,6,0,8},{9,10,11,12}};
    cout << "Now your turn:" << endl; printMatrix(mat3);
    setZeroesOptimal(mat3);
    cout << "Output:" << endl; printMatrix(mat3);

    return 0;
}
*/


// =============================================================
// JUDGE CODE — LeetCode #73 / TUF+
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool col0 = false;

        // Step 1+2: mark first row and col
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if (j == 0) col0 = true;
                    else        matrix[0][j] = 0;
                }
            }
        }

        // Step 3: zero inner matrix
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        // Step 4: zero first row
        if (matrix[0][0] == 0)
            for (int j = 0; j < m; j++) matrix[0][j] = 0;

        // Step 5: zero first col
        if (col0)
            for (int i = 0; i < n; i++) matrix[i][0] = 0;
    }
};
*/