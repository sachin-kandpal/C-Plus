// // Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
// // Allocate books in such a way that:

// // Each student gets at least one book.
// // Each book should be allocated to only one student.
// // Book allocation should be in a contiguous manner.
// // You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1




// // brute force solution
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:

//     // Function to count the minimum number of students required
//     // if each student can read at most 'pages' pages.
//     int countStudents(vector<int> &arr, int pages) {
//         // Initially assign books to the first student.
//         int students = 1;

//         // Stores pages allocated to the current student.
//         int pagesStudent = 0;

//         // Traverse all books.
//         for (int book : arr) {

//             // If the current book can be assigned to the current student.
//             if (pagesStudent + book <= pages) {
//                 pagesStudent += book;
//             }

//             // Otherwise, assign the book to the next student.
//             else {
//                 students++;
//                 pagesStudent = book;
//             }
//         }

//         // Return the number of students required.
//         return students;
//     }

//     // Function to find the minimum possible maximum pages.
//     int findPages(vector<int> &arr, int n, int m) {

//         // If students are more than books, allocation is impossible.
//         if (m > n) return -1;

//         // Minimum possible answer is the largest book.
//         int low = *max_element(arr.begin(), arr.end());

//         // Maximum possible answer is the sum of all pages.
//         int high = accumulate(arr.begin(), arr.end(), 0);

//         // Check every possible answer from low to high.
//         for (int pages = low; pages <= high; pages++) {

//             // If exactly m students are required, return the answer.
//             if (countStudents(arr, pages) == m)
//                 return pages;
//         }

//         // Fallback (should never occur for valid inputs).
//         return -1;
//     }
// };

// int main() {

//     // Input array.
//     vector<int> arr = {25, 46, 28, 49, 24};

//     int m = 4;

//     // Create Solution object.
//     Solution obj;

//     // Print the answer.
//     cout << obj.findPages(arr, arr.size(), m);

//     return 0;
// }



// optimal solution
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

int countStudents(vector<int> &arr, int pages) {
    int n = arr.size(); //size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {
            //add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    //book allocation impossible:
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}
};

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    Solution obj;
    int ans = obj.findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}