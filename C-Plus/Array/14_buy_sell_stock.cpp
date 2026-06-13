/*
=============================================================
  PROBLEM : Best Time to Buy and Sell Stock
  Platform : TUF+ / LeetCode #121 (Easy)
  Sheet    : Striver A2Z DSA (Arrays - Easy)

  Buy once, sell once. Maximize profit.
  Must buy before selling. Same day not allowed.
  Return 0 if no profit possible.

  Example:
    arr = [10, 7, 5, 8, 11, 9]  →  Output: 6  (buy@5, sell@11)
    arr = [5, 4, 3, 2, 1]       →  Output: 0  (prices only fall)
    arr = [3, 8, 1, 4, 6, 2]    →  Output: 5  (buy@1, sell@6)

  NOTE: Raw array in VS Code (fixed known input).
        Judge uses vector<int> per platform signature.

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ best_time_buy_sell_stock.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;


// =============================================================
// METHOD 1 — BRUTE FORCE
// Idea : Try every pair (i, j) where j > i
//        profit = arr[j] - arr[i]
//        Track maximum profit
// Time : O(N^2)   Space: O(1)
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

int maxProfitBrute(int arr[], int n) {
    int maxProfit = 0;                      // 0 = no transaction baseline

    for (int i = 0; i < n - 1; i++) {      // buy day
        for (int j = i + 1; j < n; j++) {  // sell day (must be after buy)
            int profit = arr[j] - arr[i];  // profit if buy on i, sell on j

            maxProfit = max(maxProfit, profit); // keep track of best
        }
    }
    return maxProfit;
}

int main() {
    int arr[] = {10, 7, 5, 8, 11, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "===== BRUTE FORCE =====" << endl;
    cout << "Input  : [10, 7, 5, 8, 11, 9]" << endl;
    cout << "Max Profit : " << maxProfitBrute(arr, n) << endl;  // 6

    int e1[] = {5, 4, 3, 2, 1};
    cout << "Only falling [5,4,3,2,1] : "
         << maxProfitBrute(e1, 5) << endl;  // 0

    return 0;
}


// =============================================================
// METHOD 2 — OPTIMAL (Track Minimum Price So Far)
//
// Idea : On every day, the best profit = currentPrice - minSoFar
//        minSoFar = cheapest price we could have bought at
//
// Walk left to right:
//   → Update minPrice if current price is lower (better buy day)
//   → Calculate profit = arr[i] - minPrice
//   → Update maxProfit if profit is better
//
// Why this works:
//   For each sell day, the optimal buy is always the minimum
//   price seen before that day → track it as you go
//
// Time : O(N)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
int maxProfitOptimal(int arr[], int n) {
    int minPrice  = INT_MAX;   // cheapest buy price seen so far
    int maxProfit = 0;         // 0 = no transaction baseline

    for (int i = 0; i < n; i++) {
        minPrice = min(minPrice, arr[i]);       // update cheapest buy day

        int profit = arr[i] - minPrice;         // profit if we sell today

        maxProfit = max(maxProfit, profit);     // update best profit
    }
    return maxProfit;
}

int main() {
    int arr[] = {10, 7, 5, 8, 11, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "===== OPTIMAL (Min So Far) =====" << endl;
    cout << "Input  : [10, 7, 5, 8, 11, 9]" << endl;
    cout << "Max Profit : " << maxProfitOptimal(arr, n) << endl;  // 6

    int e1[] = {5, 4, 3, 2, 1};
    cout << "Only falling [5,4,3,2,1]   : "
         << maxProfitOptimal(e1, 5) << endl;  // 0

    int e2[] = {3, 8, 1, 4, 6, 2};
    cout << "Now your turn [3,8,1,4,6,2]: "
         << maxProfitOptimal(e2, 6) << endl;  // 5

    int e3[] = {1};
    cout << "Single element [1]         : "
         << maxProfitOptimal(e3, 1) << endl;  // 0

    return 0;
}
*/


// =============================================================
// JUDGE CODE — LeetCode #121 / TUF+
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice  = INT_MAX;   // best buy price so far
        int maxProfit = 0;         // best profit so far

        for (int price : prices) {
            minPrice  = min(minPrice, price);       // update cheapest buy
            maxProfit = max(maxProfit, price - minPrice); // update best profit
        }
        return maxProfit;
    }
};
*/