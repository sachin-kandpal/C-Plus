// // brute force approach
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     // Function to find a peak element in the array
//     int findPeakElement(vector<int>& nums) {
//         int n = nums.size();

//         // Traverse the array
//         for (int i = 0; i < n; i++) {
//             // Check left neighbor if exists
//             bool left = (i == 0) || (nums[i] >= nums[i - 1]);
//             // Check right neighbor if exists
//             bool right = (i == n - 1) || (nums[i] >= nums[i + 1]);

//             // If both sides are valid, return index
//             if (left && right) return i;
//         }

//         // In case no peak found (shouldn't happen)
//         return -1;
//     }
// };

// // Driver
// int main() {
//     Solution sol;
//     vector<int> nums = {1, 3, 20, 4, 1, 0};
//     int index = sol.findPeakElement(nums);
//     cout << "Peak at index: " << index << " with value: " << nums[index] << endl;
//     return 0;
// }

// ###############################//
// optimal approach
#include <bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;
    // Set left and right bounds
    int low = 1, high = n - 2;

    // Binary search loop
    while (low < high)
    {
        // Find mid point
        int mid = (low + high) / 2;

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;
        else if (nums[mid] > nums[mid + 1])
            high = mid - 1;
        else
            low = mid + 1;
    }
};

int main()
{
    // Input array
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    // Output result
    cout << findPeakElement(nums) << endl;

    return 0;
}