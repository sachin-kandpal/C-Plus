#include <bits/stdc++.h>
using namespace std;

// ============================================================
// BRUTE FORCE APPROACH
// Try every subarray, extend product incrementally, track max
// Time: O(N^2)   Space: O(1)
// ============================================================
int maxProductBruteForce(vector<int>& nums) {
    int n = nums.size();
    long long maxProduct = nums[0]; // initialize with first element (handles single-element case)

    // 'i' is the starting index of the subarray
    for (int i = 0; i < n; i++) {
        long long product = 1; // running product for subarray starting at i

        // 'j' extends the subarray one element at a time
        for (int j = i; j < n; j++) {
            product *= nums[j]; // extend the subarray by including nums[j]
            maxProduct = max(maxProduct, product); // update global max if this is bigger
        }
    }

    return (int)maxProduct;
}

int main() {
    // sample test cases
    vector<int> nums1 = {2, 3, -2, 4};   // expected output: 6
    vector<int> nums2 = {-2, 0, -1};     // expected output: 0

    vector<int> nums = nums1; // change to nums2 to test the other case

    int ans;

    ans = maxProductBruteForce(nums);
    cout << "Maximum Product Subarray: " << ans << endl;

    return 0;
}




// // ============================================================
// // OPTIMAL APPROACH
// // Track running max product and running min product ending at
// // each index, because multiplying by a negative number flips
// // max and min (min can become max after one more negative multiply)
// // Time: O(N)   Space: O(1)
// // ============================================================
// #include <bits/stdc++.h>
// using namespace std;

// // Striver Optimal Approach
// int maxProductSubarray(vector<int>& arr)
// {
//     int n = arr.size();

//     long long pre = 1;
//     long long suff = 1;

//     long long ans = LLONG_MIN;

//     for(int i = 0; i < n; i++)
//     {
//         // Restart product after zero
//         if(pre == 0)
//             pre = 1;

//         if(suff == 0)
//             suff = 1;

//         // Prefix product
//         pre *= arr[i];

//         // Suffix product
//         suff *= arr[n - i - 1];

//         // Update answer
//         ans = max(ans, max(pre, suff));
//     }

//     return (int)ans;
// }

// int main()
// {
//     vector<int> nums = {2,3,-2,4};

//     cout << "Maximum Product Subarray = "
//          << maxProductSubarray(nums);

//     return 0;
// }


// // judge version
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {

//         long long pre = 1;
//         long long suff = 1;

//         long long ans = LLONG_MIN;

//         int n = nums.size();

//         for(int i = 0; i < n; i++)
//         {
//             if(pre == 0)
//                 pre = 1;

//             if(suff == 0)
//                 suff = 1;

//             pre *= nums[i];
//             suff *= nums[n - i - 1];

//             ans = max(ans, max(pre, suff));
//         }

//         return (int)ans;
//     }
// };