/*
=============================================================
  PROBLEM : Union of Two Sorted Arrays
  Sheet   : Striver A2Z DSA (Arrays - Easy)

  Input : Two sorted arrays A (size n) and B (size m)
  Output: Sorted array of all unique elements from both

  Example:
    A = [1, 1, 2, 3, 4]
    B = [2, 3, 4, 4, 5]
    Output = [1, 2, 3, 4, 5]

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ union_two_sorted_arrays.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;


// =============================================================
// METHOD 1 — BRUTE FORCE (Using Set)
// Idea : Insert all elements of A and B into a set
//        Set removes duplicates + keeps sorted order
// Time : O((N+M) log(N+M))   Space: O(N+M)
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

vector<int> unionBrute(vector<int>& A, vector<int>& B) {
    set<int> st;

    for (int x : A) st.insert(x);   // insert all of A into set
    for (int x : B) st.insert(x);   // insert all of B into set
    // set automatically handles: duplicates removed + sorted order

    return vector<int>(st.begin(), st.end());  // convert set to vector
}

int main() {
    vector<int> A = {1, 1, 2, 3, 4};
    vector<int> B = {2, 3, 4, 4, 5};

    cout << "===== BRUTE FORCE (Set) =====" << endl;
    cout << "A = [1, 1, 2, 3, 4]" << endl;
    cout << "B = [2, 3, 4, 4, 5]" << endl;

    vector<int> result = unionBrute(A, B);

    cout << "Union : ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}


// =============================================================
// METHOD 2 — OPTIMAL (Two Pointers)  <- BEST SOLUTION
// Idea : Merge both sorted arrays like merge-sort
//        But before adding, check if it equals last added
//        If yes → duplicate → skip it
// Time : O(N+M)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
vector<int> unionOptimal(vector<int>& A, int n, vector<int>& B, int m) {
    vector<int> ans;
    int i = 0, j = 0;              // i → pointer on A, j → pointer on B

    while (i < n && j < m) {

        if (A[i] <= B[j]) {        // A[i] is smaller or equal
            // add only if ans is empty OR current != last added (avoid duplicate)
            if (ans.empty() || ans.back() != A[i])
                ans.push_back(A[i]);
            i++;                   // move A's pointer forward
        }
        else {                     // B[j] is smaller
            if (ans.empty() || ans.back() != B[j])
                ans.push_back(B[j]);
            j++;                   // move B's pointer forward
        }
    }

    // drain remaining elements of A (if any)
    while (i < n) {
        if (ans.empty() || ans.back() != A[i])
            ans.push_back(A[i]);
        i++;
    }

    // drain remaining elements of B (if any)
    while (j < m) {
        if (ans.empty() || ans.back() != B[j])
            ans.push_back(B[j]);
        j++;
    }

    return ans;
}

int main() {
    vector<int> A = {1, 1, 2, 3, 4};
    vector<int> B = {2, 3, 4, 4, 5};

    cout << "===== OPTIMAL (Two Pointers) =====" << endl;
    cout << "A = [1, 1, 2, 3, 4]" << endl;
    cout << "B = [2, 3, 4, 4, 5]" << endl;

    vector<int> result = unionOptimal(A, A.size(), B, B.size());

    cout << "Union : ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
*/


// =============================================================
// JUDGE CODE — Coding Ninjas / GFG submission
// Copy ONLY this function when submitting online
// =============================================================

/*
vector<int> sortedUnion(vector<int>& A, int n, vector<int>& B, int m) {
    vector<int> ans;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (A[i] <= B[j]) {
            if (ans.empty() || ans.back() != A[i])
                ans.push_back(A[i]);
            i++;
        } else {
            if (ans.empty() || ans.back() != B[j])
                ans.push_back(B[j]);
            j++;
        }
    }
    while (i < n) {
        if (ans.empty() || ans.back() != A[i]) ans.push_back(A[i]);
        i++;
    }
    while (j < m) {
        if (ans.empty() || ans.back() != B[j]) ans.push_back(B[j]);
        j++;
    }
    return ans;
}
*/