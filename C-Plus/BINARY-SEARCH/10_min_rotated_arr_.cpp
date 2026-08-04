// // bruute force approach
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     // Function to find the minimum element using linear search
//     int findMin(vector<int>& nums) {

//         // Initialize answer with a large number
//         int minVal = INT_MAX;

//         // Traverse each element
//         for (int i = 0; i < nums.size(); i++) {

//             // Update minimum value
//             minVal = min(minVal, nums[i]);
//         }

//         // Return the result
//         return minVal;
//     }
// };

// int main() {

//     // Input array
//     vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

//     // Create object of Solution
//     Solution sol;

//     // Call function and store result
//     int result = sol.findMin(nums);

//     // Output the result
//     cout << "Minimum element is " << result << endl;

//     return 0;
// }


// optimal approach
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = low + (high - low) / 2;
            // left half sorted ko dekhte h
            if(nums[low]<=nums[mid]){
                ans = min(nums[low],ans);
                low = mid +1; 
            }
            // right half sorted
            else{
                ans = min(nums[mid],ans);
                high = mid -1;
            }
        }
        return ans; 
          
    }
};
int main() {

    // Input array
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    // Create object of Solution
    Solution sol;

    // Call function and store result
    int result = sol.findMin(nums);

    // Output the result
    cout << "Minimum element is " << result << endl;

    return 0;
}