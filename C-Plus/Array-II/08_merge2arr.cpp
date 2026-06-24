/*
=============================================================
  PROBLEM : Merge Two Sorted Arrays Without Extra Space
  Platform : GFG / LeetCode #88 (variant)
  Sheet    : Striver A2Z DSA (Arrays - Medium)

  Merge arr1[n] and arr2[m] (both sorted) such that
  arr1 ends up with the smallest n elements (sorted),
  arr2 ends up with the largest m elements (sorted).
  Must be done with O(1) extra space (no temp array).

  Example:
    arr1=[1,3,5,7], arr2=[0,2,6,8,9]
    → arr1=[0,1,2,3], arr2=[5,6,7,8,9]

  This file has 3 versions matching your screenshots:
    Method 1 → Brute (extra array + sort) - LC#88 simplest approach
    Method 2 → Better (merge using arr3) - Image 2 on screen
    Method 3 → OPTIMAL (swap-based, O(1) space) - Image 3 on screen

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ merge_sorted_arrays_no_extra_space.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;

void printArr(long long arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++)
        cout << arr[i] << (i < n-1 ? "," : "");
    cout << "]";
}


// =============================================================
// METHOD 1 — BRUTE FORCE (Extra array + sort)
// Idea : Combine both arrays into one temp array, sort it,
//        split back into arr1 (first n) and arr2 (last m)
// Time : O((N+M) log(N+M))   Space: O(N+M)
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

void mergeBrute(long long arr1[], long long arr2[], int n, int m) {
    vector<long long> temp;

    for (int i = 0; i < n; i++) temp.push_back(arr1[i]); // copy arr1
    for (int i = 0; i < m; i++) temp.push_back(arr2[i]); // copy arr2

    sort(temp.begin(), temp.end());        // sort combined array

    for (int i = 0; i < n; i++) arr1[i] = temp[i];        // first n → arr1
    for (int i = 0; i < m; i++) arr2[i] = temp[n + i];     // last m → arr2
}

int main() {
    int n = 4, m = 5;
    long long arr1[] = {1, 3, 5, 7};
    long long arr2[] = {0, 2, 6, 8, 9};

    cout << "===== BRUTE FORCE (Extra array) =====" << endl;
    cout << "Before: arr1="; printArr(arr1, n);
    cout << "  arr2="; printArr(arr2, m); cout << endl;

    mergeBrute(arr1, arr2, n, m);

    cout << "After : arr1="; printArr(arr1, n);
    cout << "  arr2="; printArr(arr2, m); cout << endl;
    // arr1=[0,1,2,3]  arr2=[5,6,7,8,9]

    return 0;
}


// =============================================================
// METHOD 2 — BETTER (Merge using extra array arr3)
// Idea : Standard merge-two-sorted-arrays logic (merge sort style)
//        Use 2 pointers, fill arr3, then copy back to arr1/arr2
// Time : O(N+M)   Space: O(N+M)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
void mergeBetter(long long arr1[], long long arr2[], int n, int m) {
    long long arr3[n + m];             // temp array to hold merged result
    int left = 0, right = 0, index = 0;

    // standard merge logic (like merge sort's merge step)
    while (left < n && right < m) {
        if (arr1[left] <= arr2[right]) {
            arr3[index] = arr1[left];
            left++; index++;
        } else {
            arr3[index] = arr2[right];
            right++; index++;
        }
    }

    // copy remaining elements of arr1 (if any)
    while (left < n) {
        arr3[index++] = arr1[left++];
    }

    // copy remaining elements of arr2 (if any)
    while (right < m) {
        arr3[index++] = arr2[right++];
    }

    // copy arr3 back: first n elements → arr1, rest → arr2
    for (int i = 0; i < n + m; i++) {
        if (i < n) arr1[i] = arr3[i];
        else        arr2[i - n] = arr3[i];
    }
}

int main() {
    int n = 4, m = 5;
    long long arr1[] = {1, 3, 5, 7};
    long long arr2[] = {0, 2, 6, 8, 9};

    cout << "===== BETTER (Merge using arr3) =====" << endl;
    cout << "Before: arr1="; printArr(arr1, n);
    cout << "  arr2="; printArr(arr2, m); cout << endl;

    mergeBetter(arr1, arr2, n, m);

    cout << "After : arr1="; printArr(arr1, n);
    cout << "  arr2="; printArr(arr2, m); cout << endl;
    // arr1=[0,1,2,3]  arr2=[5,6,7,8,9]

    return 0;
}
*/


// =============================================================
// METHOD 3 — OPTIMAL (Swap-Based, O(1) Space)  <- TRUE OPTIMAL
//
// Idea :
//   left  = n-1   → last (largest) index of arr1
//   right = 0     → first (smallest) index of arr2
//
//   While left >= 0 AND right < m:
//     if arr1[left] > arr2[right]:
//        → swap them (bigger element belongs in arr2)
//        → left--, right++
//     else:
//        → break (rest is already correctly placed)
//
//   Finally: sort arr1 and sort arr2 separately
//            (swaps can leave each array locally unsorted)
//
// Why this works:
//   arr1 holds the n SMALLEST elements eventually,
//   arr2 holds the m LARGEST elements eventually.
//   Comparing arr1's largest with arr2's smallest tells us
//   immediately if they're in the wrong array.
//
// Time : O(min(N,M)) for swap + O(N logN + M logM) for sort
// Space: O(1) — TRUE in-place!
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
void mergeOptimal(long long arr1[], long long arr2[], int n, int m) {
    int left = n - 1;      // last index of arr1 (largest element)
    int right = 0;         // first index of arr2 (smallest element)

    // swap out-of-place elements between arr1 and arr2
    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);  // bigger element moves to arr2
            left--;                          // move left pointer back
            right++;                         // move right pointer forward
        } else {
            break;                           // no more swaps needed
        }
    }

    // sort both arrays individually (swaps may have left them unsorted)
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main() {
    int n = 4, m = 5;
    long long arr1[] = {1, 3, 5, 7};
    long long arr2[] = {0, 2, 6, 8, 9};

    cout << "===== OPTIMAL (Swap-Based, O(1) Space) =====" << endl;
    cout << "Before: arr1="; printArr(arr1, n);
    cout << "  arr2="; printArr(arr2, m); cout << endl;

    mergeOptimal(arr1, arr2, n, m);

    cout << "After : arr1="; printArr(arr1, n);
    cout << "  arr2="; printArr(arr2, m); cout << endl;
    // arr1=[0,1,2,3]  arr2=[5,6,7,8,9]

    // another test
    int n2 = 4, m2 = 4;
    long long b1[] = {1, 4, 7, 8};
    long long b2[] = {2, 3, 9, 10};
    cout << "\nBefore: arr1="; printArr(b1, n2);
    cout << "  arr2="; printArr(b2, m2); cout << endl;

    mergeOptimal(b1, b2, n2, m2);

    cout << "After : arr1="; printArr(b1, n2);
    cout << "  arr2="; printArr(b2, m2); cout << endl;
    // arr1=[1,2,3,4]  arr2=[7,8,9,10]

    return 0;
}
*/


// =============================================================
// JUDGE CODE — GFG style (matches Image 3 exactly)
// Copy ONLY this function/class when submitting online
// =============================================================

/*
class Solution {
public:
    // Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m) {
        int left = n - 1;
        int right = 0;

        while (left >= 0 && right < m) {
            if (arr1[left] > arr2[right]) {
                swap(arr1[left], arr2[right]);
                left--;
                right++;
            } else {
                break;
            }
        }

        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};
*/


// JUDGE CODE — LeetCode #88 version
