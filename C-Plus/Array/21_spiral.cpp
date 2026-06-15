/*
=============================================================
  PROBLEM : Spiral Matrix
  Platform : LeetCode #54 (Medium)
  Sheet    : Striver A2Z DSA (Arrays - Medium)

  Return all elements of an M×N matrix in spiral order.

  Example:
    [[1,2,3],[4,5,6],[7,8,9]] → [1,2,3,6,9,8,7,4,5]

  NOTE: Only ONE approach exists for this problem.
        vector<vector<int>> for matrix (2D, variable size).
        vector<int> for result (dynamic output).

  HOW TO RUN:
  → Compile: g++ spiral_matrix.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++)
        cout << v[i] << (i < (int)v.size()-1 ? ", " : "");
    cout << "]" << endl;
}

void printMatrix(vector<vector<int>>& mat) {
    for (auto& row : mat) {
        cout << "[ ";
        for (int x : row) cout << x << " ";
        cout << "]" << endl;
    }
}


// =============================================================
// ONLY APPROACH — Boundary Simulation
//
// 4 boundaries shrink inward after each direction:
//   top    → first unvisited row from top
//   bottom → first unvisited row from bottom
//   left   → first unvisited col from left
//   right  → first unvisited col from right
//
// 4 steps per layer (with guards for edge cases):
//   Step 1: → Left to Right  along top row    → top++
//   Step 2: ↓ Top to Bottom  along right col  → right--
//   Step 3: ← Right to Left  along bottom row → bottom-- (only if top<=bottom)
//   Step 4: ↑ Bottom to Top  along left col   → left++   (only if left<=right)
//
// Guards in Step 3 and 4 handle single row/col cases
// (when top==bottom or left==right after Steps 1 and 2)
//
// Time : O(N*M)   Space: O(1)
// =============================================================

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();       // number of rows
    int m = matrix[0].size();    // number of cols

    vector<int> result;
    result.reserve(n * m);       // pre-allocate for efficiency

    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    while (top <= bottom && left <= right) {

        // ── Step 1: Left → Right along top row ───────────────
        for (int col = left; col <= right; col++)
            result.push_back(matrix[top][col]);
        top++;                   // top row done, shrink inward

        // ── Step 2: Top → Bottom along right col ─────────────
        for (int row = top; row <= bottom; row++)
            result.push_back(matrix[row][right]);
        right--;                 // right col done, shrink inward

        // ── Step 3: Right → Left along bottom row ────────────
        // GUARD: only if there's still a row left (not single row)
        if (top <= bottom) {
            for (int col = right; col >= left; col--)
                result.push_back(matrix[bottom][col]);
            bottom--;            // bottom row done, shrink inward
        }

        // ── Step 4: Bottom → Top along left col ──────────────
        // GUARD: only if there's still a col left (not single col)
        if (left <= right) {
            for (int row = bottom; row >= top; row--)
                result.push_back(matrix[row][left]);
            left++;              // left col done, shrink inward
        }
    }
    return result;
}

int main() {
    cout << "===== SPIRAL MATRIX =====" << endl;

    // 3×3
    vector<vector<int>> mat1 = {{1,2,3},{4,5,6},{7,8,9}};
    cout << "3x3 Input:" << endl; printMatrix(mat1);
    vector<int> r1 = spiralOrder(mat1);
    cout << "Spiral: "; printVec(r1);
    cout << endl;

    // 4×4
    vector<vector<int>> mat2 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    cout << "4x4 Input:" << endl; printMatrix(mat2);
    vector<int> r2 = spiralOrder(mat2);
    cout << "Spiral: "; printVec(r2);
    cout << endl;

    // 1×4 (single row)
    vector<vector<int>> mat3 = {{1,2,3,4}};
    cout << "1x4 [1,2,3,4]:" << endl; printMatrix(mat3);
    vector<int> r3 = spiralOrder(mat3);
    cout << "Spiral: "; printVec(r3);
    cout << endl;

    // 4×1 (single col)
    vector<vector<int>> mat4 = {{1},{2},{3},{4}};
    cout << "4x1 col:" << endl; printMatrix(mat4);
    vector<int> r4 = spiralOrder(mat4);
    cout << "Spiral: "; printVec(r4);
    cout << endl;

    // 3×4 rectangle
    vector<vector<int>> mat5 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    cout << "3x4 Input:" << endl; printMatrix(mat5);
    vector<int> r5 = spiralOrder(mat5);
    cout << "Spiral: "; printVec(r5);

    return 0;
}


// =============================================================
// JUDGE CODE — LeetCode #54
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> result;

        int top = 0, bottom = n-1, left = 0, right = m-1;

        while (top <= bottom && left <= right) {

            // → left to right
            for (int col = left; col <= right; col++)
                result.push_back(matrix[top][col]);
            top++;

            // ↓ top to bottom
            for (int row = top; row <= bottom; row++)
                result.push_back(matrix[row][right]);
            right--;

            // ← right to left (guard for single row)
            if (top <= bottom) {
                for (int col = right; col >= left; col--)
                    result.push_back(matrix[bottom][col]);
                bottom--;
            }

            // ↑ bottom to top (guard for single col)
            if (left <= right) {
                for (int row = bottom; row >= top; row--)
                    result.push_back(matrix[row][left]);
                left++;
            }
        }
        return result;
    }
};
*/