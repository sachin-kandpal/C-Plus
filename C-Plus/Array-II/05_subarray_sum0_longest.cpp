#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int maxLen(vector<int>& arr) {

    unordered_map<int, int> mpp;

    int sum = 0;
    int maxi = 0;

    for(int i = 0; i < arr.size(); i++) {

        sum += arr[i];

        // If sum becomes 0,
        // subarray from 0 to i has sum 0
        if(sum == 0) {
            maxi = i + 1;
        }

        // If same prefix sum appeared before
        else if(mpp.find(sum) != mpp.end()) {
            maxi = max(maxi, i - mpp[sum]);
        }

        // Store first occurrence of prefix sum
        else {
            mpp[sum] = i;
        }
    }

    return maxi;
}

int main() {

    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

    cout << "Length of Largest Zero Sum Subarray = "
         << maxLen(arr);

    return 0;
}