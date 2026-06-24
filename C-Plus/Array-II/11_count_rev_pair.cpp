// // brute force approach
// The naive approach is pretty straightforward. We will use nested loops to generate all possible pairs.
//  We know index i must be smaller than index j. So, we will fix i at one index at a time through a loop,
//   and with another loop, we will check(the condition a[i] > 2*a[j]) the elements from index i+1 to N-1  if they can form a pair with a[i].
#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int>&a, int n) {

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > 2 * a[j]) cnt++;
        }
    }
    return cnt;
}

int team(vector <int> & skill, int n) {
    return countPairs(skill, n);
}

int main()
{
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = team(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
// }



// // optimal approach
// In order to solve this problem we will use the merge sort algorithm like we used in the problem count inversion with a slight modification of the merge() function
// . But in this case, the same logic will not work. In order to understand this, we need to deep dive into the merge() function.

// Why the same logic of count inversion will not work?

// The merge function works by comparing two elements from two halves i.e. arr[left] and arr[right]. Now, the condition in the question was arr[i] > arr[j].
//  That is why we merged the logic. While comparing the elements, we counted the number of pairs.
// But in this case, the condition is arr[i] > 2*arr[j]. And, we cannot change the condition of comparing the elements in the merge() function.
//  If we change the condition, the merge() function will fail to merge the elements. So, we need to check this condition and count the number of pairs separately.



// #include <bits/stdc++.h>
// using namespace std;

// void merge(vector<int> &arr, int low, int mid, int high) {
//     vector<int> temp; // temporary array
//     int left = low;      // starting index of left half of arr
//     int right = mid + 1;   // starting index of right half of arr

//     //storing elements in the temporary array in a sorted manner//

//     while (left <= mid && right <= high) {
//         if (arr[left] <= arr[right]) {
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else {
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }

//     // if elements on the left half are still left //

//     while (left <= mid) {
//         temp.push_back(arr[left]);
//         left++;
//     }

//     //  if elements on the right half are still left //
//     while (right <= high) {
//         temp.push_back(arr[right]);
//         right++;
//     }

//     // transfering all elements from temporary to arr //
//     for (int i = low; i <= high; i++) {
//         arr[i] = temp[i - low];
//     }
// }

// int countPairs(vector<int> &arr, int low, int mid, int high) {
//     int right = mid + 1;
//     int cnt = 0;
//     for (int i = low; i <= mid; i++) {
//         while (right <= high && arr[i] > 2 * arr[right]) right++;
//         cnt += (right - (mid + 1));
//     }
//     return cnt;
// }

// int mergeSort(vector<int> &arr, int low, int high) {
//     int cnt = 0;
//     if (low >= high) return cnt;
//     int mid = (low + high) / 2 ;
//     cnt += mergeSort(arr, low, mid);  // left half
//     cnt += mergeSort(arr, mid + 1, high); // right half
//     cnt += countPairs(arr, low, mid, high); //Modification
//     merge(arr, low, mid, high);  // merging sorted halves
//     return cnt;
// }

// int team(vector <int> & skill, int n)
// {
//     return mergeSort(skill, 0, n - 1);
// }

// int main()
// {
//     vector<int> a = {4, 1, 2, 3, 1};
//     int n = 5;
//     int cnt = team(a, n);
//     cout << "The number of reverse pair is: "
//          << cnt << endl;
//     return 0;
// }


// // JUDGE VERSION
// // LeetCode 493 - Reverse Pair

// class Solution {
// public:

//     // Merge two sorted halves
//     void merge(vector<int>& arr, int low, int mid, int high) {

//         vector<int> temp;

//         int left = low;
//         int right = mid + 1;

//         while (left <= mid && right <= high) {

//             if (arr[left] <= arr[right]) {
//                 temp.push_back(arr[left]);
//                 left++;
//             }
//             else {
//                 temp.push_back(arr[right]);
//                 right++;
//             }
//         }

//         while (left <= mid) {
//             temp.push_back(arr[left]);
//             left++;
//         }

//         while (right <= high) {
//             temp.push_back(arr[right]);
//             right++;
//         }

//         for (int i = low; i <= high; i++) {
//             arr[i] = temp[i - low];
//         }
//     }

//     // Count reverse pairs
//     int countPairs(vector<int>& arr, int low, int mid, int high) {

//         int right = mid + 1;
//         int cnt = 0;

//         for (int i = low; i <= mid; i++) {

//             while (right <= high &&
//                    arr[i] > 2LL * arr[right]) {
//                 right++;
//             }

//             cnt += (right - (mid + 1));
//         }

//         return cnt;
//     }

//     int mergeSort(vector<int>& arr, int low, int high) {

//         if (low >= high)
//             return 0;

//         int mid = (low + high) / 2;

//         int cnt = 0;

//         // Left half
//         cnt += mergeSort(arr, low, mid);

//         // Right half
//         cnt += mergeSort(arr, mid + 1, high);

//         // Count reverse pairs
//         cnt += countPairs(arr, low, mid, high);

//         // Merge sorted halves
//         merge(arr, low, mid, high);

//         return cnt;
//     }

//     int reversePairs(vector<int>& nums) {

//         return mergeSort(nums, 0, nums.size() - 1);
//     }
// };