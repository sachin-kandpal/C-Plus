/*
=============================================================
  PROBLEM : Intersection of Two Sorted Arrays
  Sheet   : Striver A2Z DSA (Arrays - Easy)
  Platform: Coding Ninjas / LeetCode

  Input : Two sorted arrays A (size n) and B (size m)
  Output: Array of common elements (with duplicates)

  Example:
    A = [1, 2, 2, 3, 4]
    B = [2, 2, 4, 6]
    Output = [2, 2, 4]

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ intersection_two_sorted_arrays.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;


// =============================================================
// METHOD 1 — BRUTE FORCE
// Idea : For each element in A, search entire B
//        Use visited[] to avoid reusing B's elements
// Time : O(N * M)   Space: O(M)
// STATUS: ACTIVE ← comment out this main() to switch method
// =============================================================

vector<int> intersectionBrute(vector<int>& A, int n, vector<int>& B, int m) {
    vector<int> visited(m, 0);  // visited[j]=1 means B[j] already matched
    vector<int> ans;

    for (int i = 0; i < n; i++) {          // pick each element of A
        for (int j = 0; j < m; j++) {      // search in B
            if (A[i] == B[j] && visited[j] == 0) {  // found + not reused
                ans.push_back(A[i]);       // common element found
                visited[j] = 1;           // mark B[j] as used
                break;                    // done with A[i], move on
            }
            if (B[j] > A[i]) break;       // B is sorted: no match possible ahead
        }
    }
    return ans;
}

int main() {
    vector<int> A = {1, 2, 2, 3, 4};
    vector<int> B = {2, 2, 4, 6};

    cout << "===== BRUTE FORCE =====" << endl;
    cout << "A = [1, 2, 2, 3, 4]" << endl;
    cout << "B = [2, 2, 4, 6]" << endl;

    vector<int> result = intersectionBrute(A, A.size(), B, B.size());

    cout << "Intersection : ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}


// =============================================================
// METHOD 2 — OPTIMAL (Two Pointers)  <- BEST SOLUTION
// Idea : Use two pointers i on A, j on B
//        Equal   → add to answer, move both
//        A[i]<B[j] → move i
//        A[i]>B[j] → move j
// Time : O(N + M)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
vector<int> intersectionOptimal(vector<int>& A, int n, vector<int>& B, int m) {
    vector<int> ans;
    int i = 0, j = 0;            // two pointers, one on each array

    while (i < n && j < m) {    // run until either array ends
        if (A[i] == B[j]) {
            ans.push_back(A[i]); // common element found
            i++;                 // move both pointers ahead
            j++;
        }
        else if (A[i] < B[j]) {
            i++;                 // A[i] too small, move it forward
        }
        else {
            j++;                 // B[j] too small, move it forward
        }
    }
    return ans;
}

int main() {
    vector<int> A = {1, 2, 2, 3, 4};
    vector<int> B = {2, 2, 4, 6};

    cout << "===== OPTIMAL (Two Pointers) =====" << endl;
    cout << "A = [1, 2, 2, 3, 4]" << endl;
    cout << "B = [2, 2, 4, 6]" << endl;

    vector<int> result = intersectionOptimal(A, A.size(), B, B.size());

    cout << "Intersection : ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
*/


// =============================================================
// JUDGE CODE — Coding Ninjas / LeetCode submission
// Copy ONLY this function when submitting online
// =============================================================

/*
vector<int> findArrayIntersection(vector<int>& A, int n, vector<int>& B, int m) {
    vector<int> ans;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (A[i] == B[j]) {
            ans.push_back(A[i]);   // common element
            i++;
            j++;
        }
        else if (A[i] < B[j]) {
            i++;                   // A is smaller, move i
        }
        else {
            j++;                   // B is smaller, move j
        }
    }
    return ans;
}
*/