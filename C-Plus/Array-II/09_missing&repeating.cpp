/*
=============================================================
  PROBLEM : Find the Repeating and Missing Number
  Platform : TUF+ / GFG
  Sheet    : Striver A2Z DSA (Arrays - Medium)

  Array of size n has values [1,n]. One value 'A' appears
  TWICE, one value 'B' is MISSING. Find A and B.

  Example:
    nums = [3,5,4,1,1]      → A=1, B=2
    nums = [1,2,3,6,7,5,7]  → A=7, B=4
    nums = [6,5,7,1,8,6,4,3,2] → A=6, B=9

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ find_missing_repeating.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;


// =============================================================
// METHOD 1 — BRUTE FORCE
// Idea : For every number 1 to n, count how many times it
//        appears in the array using a nested loop
//        count==2 → repeating, count==0 → missing
// Time : O(N^2)   Space: O(1)
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

pair<int,int> findMissingRepeatingBrute(vector<int>& nums) {
    int n = nums.size();
    int repeating = -1, missing = -1;

    for (int i = 1; i <= n; i++) {       // check every number 1 to n
        int cnt = 0;

        for (int j = 0; j < n; j++) {    // count occurrences of i
            if (nums[j] == i)
                cnt++;
        }

        if (cnt == 2)
            repeating = i;                // found the number appearing twice
        else if (cnt == 0)
            missing = i;                  // found the number missing
    }
    return {repeating, missing};
}

int main() {
    cout << "===== BRUTE FORCE =====" << endl;

    vector<int> a1 = {3,5,4,1,1};
    auto r1 = findMissingRepeatingBrute(a1);
    cout << "[3,5,4,1,1]         → repeating=" << r1.first << " missing=" << r1.second << endl; // 1,2

    vector<int> a2 = {1,2,3,6,7,5,7};
    auto r2 = findMissingRepeatingBrute(a2);
    cout << "[1,2,3,6,7,5,7]     → repeating=" << r2.first << " missing=" << r2.second << endl; // 7,4

    return 0;
}


// =============================================================
// METHOD 2 — BETTER (Hashing)
// Idea : Make a hash array of size n+1
//        Count frequency of each number using hash[nums[i]]++
//        Then scan hash: freq==2 → repeating, freq==0 → missing
// Time : O(N)   Space: O(N)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
pair<int,int> findMissingRepeatingBetter(vector<int>& nums) {
    int n = nums.size();
    vector<int> hash(n + 1, 0);     // hash[i] = how many times i appears

    for (int i = 0; i < n; i++) {
        hash[nums[i]]++;             // count frequency
    }

    int repeating = -1, missing = -1;

    for (int i = 1; i <= n; i++) {
        if (hash[i] == 2)
            repeating = i;           // appears twice
        else if (hash[i] == 0)
            missing = i;              // never appears
    }
    return {repeating, missing};
}

int main() {
    cout << "===== BETTER (Hashing) =====" << endl;

    vector<int> a1 = {3,5,4,1,1};
    auto r1 = findMissingRepeatingBetter(a1);
    cout << "[3,5,4,1,1]         → repeating=" << r1.first << " missing=" << r1.second << endl; // 1,2

    vector<int> a2 = {1,2,3,6,7,5,7};
    auto r2 = findMissingRepeatingBetter(a2);
    cout << "[1,2,3,6,7,5,7]     → repeating=" << r2.first << " missing=" << r2.second << endl; // 7,4

    vector<int> a3 = {6,5,7,1,8,6,4,3,2};
    auto r3 = findMissingRepeatingBetter(a3);
    cout << "[6,5,7,1,8,6,4,3,2] → repeating=" << r3.first << " missing=" << r3.second << endl; // 6,9

    return 0;
}
*/


// =============================================================
// METHOD 3 — OPTIMAL (Mathematical Formula)  <- SUBMIT THIS
//
// Let repeating = X, missing = Y
//
// S  = sum of array elements
// Sn = sum of first n natural numbers = n*(n+1)/2
//
// S - Sn = X - Y   ...(1)      ← extra X, missing Y
//
// S2  = sum of SQUARES of array elements
// S2n = sum of squares of first n natural numbers = n*(n+1)*(2n+1)/6
//
// S2 - S2n = X^2 - Y^2 = (X-Y)(X+Y)   ...(2)
//
// Divide (2) by (1):
//   (X-Y)(X+Y) / (X-Y) = X+Y
//   So: X+Y = (S2-S2n) / (S-Sn)
//
// Now we have:
//   X - Y = S - Sn        (from eq 1)
//   X + Y = (S2-S2n)/(S-Sn)   (derived above)
//
// Solve the 2 equations:
//   X = ((X-Y) + (X+Y)) / 2
//   Y = X - (X-Y)
//
// Time : O(N)   Space: O(1)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
pair<int,int> findMissingRepeatingOptimal(vector<int>& nums) {
    int n = nums.size();

    long long s = 0, s2 = 0;        // sum and sum of squares of array

    for (int i = 0; i < n; i++) {
        s  += nums[i];                // sum of array elements
        s2 += (long long)nums[i] * nums[i];  // sum of squares
    }

    long long sn  = (long long)n * (n + 1) / 2;              // sum 1 to n
    long long s2n = (long long)n * (n + 1) * (2 * n + 1) / 6; // sum of squares 1 to n

    long long val1 = s - sn;          // X - Y
    long long val2 = s2 - s2n;        // X^2 - Y^2
    val2 = val2 / val1;               // X + Y  (divide by X-Y)

    int x = (val1 + val2) / 2;        // X = ((X-Y)+(X+Y)) / 2
    int y = x - val1;                 // Y = X - (X-Y)

    return {x, y};                    // x=repeating, y=missing
}

int main() {
    cout << "===== OPTIMAL (Math Formula) =====" << endl;

    vector<int> a1 = {3,5,4,1,1};
    auto r1 = findMissingRepeatingOptimal(a1);
    cout << "[3,5,4,1,1]         → repeating=" << r1.first << " missing=" << r1.second << endl; // 1,2

    vector<int> a2 = {1,2,3,6,7,5,7};
    auto r2 = findMissingRepeatingOptimal(a2);
    cout << "[1,2,3,6,7,5,7]     → repeating=" << r2.first << " missing=" << r2.second << endl; // 7,4

    vector<int> a3 = {6,5,7,1,8,6,4,3,2};
    auto r3 = findMissingRepeatingOptimal(a3);
    cout << "[6,5,7,1,8,6,4,3,2] → repeating=" << r3.first << " missing=" << r3.second << endl; // 6,9

    return 0;
}
*/


// =============================================================
// JUDGE CODE — matches your screen exactly (Image 2)
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();

        long long sn  = (n * (n+1)) / 2;
        long long s2n = (n * (n+1) * (2*n+1)) / 6;

        long long s = 0, s2 = 0;
        for (int i = 0; i < n; i++) {
            s  += nums[i];
            s2 += (long long)nums[i] * nums[i];
        }

        long long val1 = s - sn;       // X - Y
        long long val2 = s2 - s2n;     // X^2 - Y^2
        val2 = val2 / val1;            // X + Y

        int x = (val1 + val2) / 2;     // repeating
        int y = x - val1;              // missing

        return {x, y};
    }
};
*/