/*
=============================================================
  PROBLEM : Merge Overlapping Intervals
  Platform : Coding Ninjas / LeetCode #56
  Sheet    : Striver A2Z DSA (Arrays - Medium)

  Merge all overlapping intervals, return non-overlapping list.

  Example:
    [[1,3],[2,4],[2,6],[8,9],[8,10],[9,11],[15,18],[16,17]]
    → [[1,6],[8,11],[15,18]]

  This file has BOTH versions you tested:
    Method 1 → Brute (nested loop, extend inline) - Coding Ninjas style
    Method 2 → Optimal (sort + single pass with ans.back()) - your LC submission

  NOTE: vector<vector<int>> used — 2D dynamic output.

  HOW TO RUN:
  → Keep only ONE main() uncommented at a time
  → Compile: g++ merge_intervals_two_versions.cpp -o out && ./out
=============================================================
*/

#include <bits/stdc++.h>
using namespace std;

void printResult(vector<vector<int>>& res) {
    cout << "[";
    for (int i = 0; i < (int)res.size(); i++) {
        cout << "[" << res[i][0] << "," << res[i][1] << "]";
        if (i < (int)res.size()-1) cout << ",";
    }
    cout << "]" << endl;
}


// =============================================================
// METHOD 1 — BRUTE FORCE (Coding Ninjas style)
// Idea : Sort by start. For each interval i, extend merge by
//        scanning ahead with j while overlap continues.
//        Skip i if it's already covered by ans.back().
// Time : O(N^2) worst case   Space: O(N)
// STATUS: ACTIVE ← comment this main() to switch method
// =============================================================

vector<vector<int>> mergeOverlappingIntervalsBrute(vector<vector<int>>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());      // sort by start time
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        int start = arr[i][0];
        int end   = arr[i][1];

        // if this interval is already covered by the last merged interval, skip
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        // try to extend the merge by scanning ahead
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]);   // extend end if overlapping
            } else {
                break;                       // no more overlap, stop scanning
            }
        }

        ans.push_back({start, end});         // push the fully merged interval
    }
    return ans;
}

int main() {
    cout << "===== BRUTE FORCE (Coding Ninjas style) =====" << endl;

    vector<vector<int>> v1 = {{1,3},{2,4},{3,5},{6,7}};
    cout << "Input  : [[1,3],[2,4],[3,5],[6,7]]" << endl;
    vector<vector<int>> r1 = mergeOverlappingIntervalsBrute(v1);
    cout << "Output : "; printResult(r1);   // [[1,5],[6,7]]
    cout << endl;

    vector<vector<int>> v2 = {{1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}};
    cout << "Input  : [[1,3],[2,4],[2,6],[8,9],[8,10],[9,11],[15,18],[16,17]]" << endl;
    vector<vector<int>> r2 = mergeOverlappingIntervalsBrute(v2);
    cout << "Output : "; printResult(r2);   // [[1,6],[8,11],[15,18]]
    cout << endl;

    vector<vector<int>> v3 = {{1,4},{4,5}};
    cout << "Input  : [[1,4],[4,5]]  (touching)" << endl;
    vector<vector<int>> r3 = mergeOverlappingIntervalsBrute(v3);
    cout << "Output : "; printResult(r3);   // [[1,5]]

    return 0;
}


// =============================================================
// METHOD 2 — OPTIMAL (Sort + Single Pass with ans.back())
// Idea : Sort by start. Walk once. Compare current interval
//        only with the LAST merged interval in ans.
//        Overlap → extend ans.back()'s end.
//        No overlap → push as new entry.
// Time : O(N log N)   Space: O(N)
// STATUS: COMMENTED — remove /* and */ below to activate
// =============================================================

/*
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());      // sort by start time
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {

        // no overlap with last merged interval → push new entry
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        else {
            // overlap → extend the end of the last merged interval
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main() {
    cout << "===== OPTIMAL (Sort + Single Pass) =====" << endl;

    vector<vector<int>> v1 = {{1,3},{2,4},{3,5},{6,7}};
    cout << "Input  : [[1,3],[2,4],[3,5],[6,7]]" << endl;
    vector<vector<int>> r1 = mergeOverlappingIntervals(v1);
    cout << "Output : "; printResult(r1);   // [[1,5],[6,7]]
    cout << endl;

    vector<vector<int>> v2 = {{1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}};
    cout << "Input  : [[1,3],[2,4],[2,6],[8,9],[8,10],[9,11],[15,18],[16,17]]" << endl;
    vector<vector<int>> r2 = mergeOverlappingIntervals(v2);
    cout << "Output : "; printResult(r2);   // [[1,6],[8,11],[15,18]]
    cout << endl;

    vector<vector<int>> v3 = {{1,4},{4,5}};
    cout << "Input  : [[1,4],[4,5]]  (touching)" << endl;
    vector<vector<int>> r3 = mergeOverlappingIntervals(v3);
    cout << "Output : "; printResult(r3);   // [[1,5]]

    return 0;
}
*/


// =============================================================
// JUDGE CODE — matches your LeetCode submission exactly
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for (int i = 0; i < (int)intervals.size(); i++) {
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};
*/