#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysWithXorK(vector<int>& nums, int k) {

    unordered_map<int,int> mpp;

    int xr = 0;
    int cnt = 0;

    mpp[0] = 1;

    for(int i = 0; i < nums.size(); i++) {

        xr ^= nums[i];

        int x = xr ^ k;

        cnt += mpp[x];

        mpp[xr]++;
    }

    return cnt;
}

int main() {

    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;

    cout << subarraysWithXorK(nums, k);

    return 0;
}


// BRUTE FORCE

// #include <iostream>
// #include <vector>
// using namespace std;

// int subarraysWithXorK(vector<int>& nums, int k) {

//     int n = nums.size();
//     int cnt = 0;

//     // Generate all subarrays
//     for(int i = 0; i < n; i++) {

//         int xr = 0;

//         for(int j = i; j < n; j++) {

//             xr ^= nums[j];

//             if(xr == k)
//                 cnt++;
//         }
//     }

//     return cnt;
// }

// int main() {

//     vector<int> nums = {4, 2, 2, 6, 4};
//     int k = 6;

//     cout << "Count of Subarrays = "
//          << subarraysWithXorK(nums, k);

//     return 0;
// }