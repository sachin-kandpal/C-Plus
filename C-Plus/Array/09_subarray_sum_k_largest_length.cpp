/*
=============================================================
  PROBLEM : Longest Subarray with Sum K
  Platform : TUF+ / GFG
  Sheet    : Striver A2Z DSA (Arrays - Medium)

  Find length of longest subarray with sum exactly equal to K.
  Array can have NEGATIVES → use Prefix Sum + HashMap.

  Example:
    nums = [10, 5, 2, 7, 1, 9],  k=15  →  Output: 4
    nums = [-3, 2, 1],            k=6   →  Output: 0

  NOTE: vector used here because:
        - size is unknown / dynamic input
        - problem itself uses vector<int>& in judge signature

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ longest_subarray_sum_k.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;


// =============================================================
// METHOD 1 — BRUTE FORCE
// Idea : Check every subarray using two loops
//        Calculate sum from i to j each time
//        If sum == k → update max length
// Time : O(N^2)   Space: O(1)
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

int longestSubarrayBrute(vector<int>& nums, int k) {
    int n = nums.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {       // starting index of subarray
        int sum = 0;

        for (int j = i; j < n; j++) {   // ending index of subarray
            sum += nums[j];             // add element to current sum

            if (sum == k)
                maxLen = max(maxLen, j - i + 1);  // update if longer
        }
    }
    return maxLen;
}

int main() {
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;

    cout << "===== BRUTE FORCE =====" << endl;
    cout << "Input : [10, 5, 2, 7, 1, 9],  k = 15" << endl;
    cout << "Longest Subarray Length : " << longestSubarrayBrute(nums, k) << endl;

    return 0;
}


// =============================================================
// METHOD 2 — OPTIMAL (Prefix Sum + HashMap)  <- SUBMIT THIS
// Idea : Store prefix sums in a map with their EARLIEST index
//        At each index j, check if (prefixSum - k) exists in map
//        If yes → subarray from map[prefixSum-k]+1 to j sums to k
//
// Key rules:
//   → Initialize map with {0 : -1}  (sum 0 at index -1)
//   → Only store index if prefix sum NOT already in map
//     (we want earliest index → longest subarray)
//
// Time : O(N)   Space: O(N)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
int longestSubarrayOptimal(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<long long, int> prefMap;  // prefixSum → earliest index
    prefMap[0] = -1;           // base case: sum 0 exists before index 0

    long long prefSum = 0;     // running prefix sum (long long avoids overflow)
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        prefSum += nums[i];    // add current element to prefix sum

        long long need = prefSum - k;   // we need THIS value in our map

        if (prefMap.count(need)) {
            // subarray from (prefMap[need]+1) to i sums to k
            int len = i - prefMap[need];
            maxLen = max(maxLen, len);  // update max length
        }

        // store this prefix sum ONLY if not already present
        // (we want earliest index for maximum length)
        if (!prefMap.count(prefSum))
            prefMap[prefSum] = i;
    }
    return maxLen;
}

int main() {
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;

    cout << "===== OPTIMAL (Prefix Sum + HashMap) =====" << endl;
    cout << "Input : [10, 5, 2, 7, 1, 9],  k = 15" << endl;
    cout << "Longest Subarray Length : " << longestSubarrayOptimal(nums, k) << endl;

    // with negatives
    vector<int> v2 = {-3, 2, 1};
    cout << "[-3,2,1] k=6 → " << longestSubarrayOptimal(v2, 6) << endl;  // 0

    // negatives present, valid subarray
    vector<int> v3 = {-1, 1, 1};
    cout << "[-1,1,1] k=1 → " << longestSubarrayOptimal(v3, 1) << endl;  // 3

    return 0;
}
*/


// =============================================================
// BONUS METHOD — SLIDING WINDOW (Only for positive arrays!)
// Idea : Expand window by moving right pointer
//        Shrink window from left when sum > k
//        Works ONLY when all elements are positive/zero
// Time : O(N)   Space: O(1)
// ⚠️  DO NOT USE when array has negative numbers
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
int longestSubarraySlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0, sum = 0, maxLen = 0;

    for (int right = 0; right < n; right++) {
        sum += nums[right];             // expand window to the right

        while (sum > k && left <= right) {
            sum -= nums[left];          // shrink from left if sum exceeds k
            left++;
        }

        if (sum == k)
            maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;

    cout << "===== SLIDING WINDOW (positives only) =====" << endl;
    cout << "Input : [10, 5, 2, 7, 1, 9],  k = 15" << endl;
    cout << "Longest Subarray Length : " << longestSubarraySlidingWindow(nums, k) << endl;

    return 0;
}
*/


// =============================================================
// JUDGE CODE — TUF+ / GFG / LeetCode style
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<long long, int> prefMap;
        prefMap[0] = -1;           // base: sum 0 seen before index 0

        long long prefSum = 0;
        int maxLen = 0;

        for (int i = 0; i < (int)nums.size(); i++) {
            prefSum += nums[i];

            long long need = prefSum - k;
            if (prefMap.count(need))
                maxLen = max(maxLen, i - prefMap[need]);

            if (!prefMap.count(prefSum))  // store earliest index only
                prefMap[prefSum] = i;
        }
        return maxLen;
    }
};
*/