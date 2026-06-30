// // brute force 
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     // Function to search target in rotated sorted array using brute force
//     int search(vector<int>& nums, int target) {

//         // Loop through each element in the array
//         for (int i = 0; i < nums.size(); i++) {

//             // If current element matches target, return index
//             if (nums[i] == target) {
//                 return i;
//             }
//         }

//         // If not found, return -1
//         return -1;
//     }
// };

// // Driver code
// int main() {
//     vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
//     int target = 0;

//     Solution obj;
//     int index = obj.search(nums, target);

//     cout << index << endl;

//     return 0;
// }



// optimal approach
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to search for target using binary search in rotated sorted array
    int search(vector<int>& nums, int target) {

        // Set the search space to entire array
        int low = 0;
        int high = nums.size() - 1;

        // Continue until the search space becomes invalid
        while (low <= high) {

            // Find the middle index
            int mid = (low + high) / 2;

            // If the target is found at mid, return mid
            if (nums[mid] == target)
                return mid;

            // Check if the left half is sorted
            if (nums[low] <= nums[mid]) {

                // If target lies in the sorted left half, search there
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                }
                // Else search in the right half
                else {
                    low = mid + 1;
                }
            }

            // Otherwise, right half is sorted
            else {

                // If target lies in the sorted right half, search there
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                }
                // Else search in the left half
                else {
                    high = mid - 1;
                }
            }
        }

        // If not found, return -1
        return -1;
    }
};

// Driver code
int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    Solution obj;
    int result = obj.search(nums, target);

    cout << result << endl;

    return 0;
}