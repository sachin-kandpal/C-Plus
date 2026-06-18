/*
=============================================================
  PROBLEM : Merge Overlapping Subintervals
  Platform : LeetCode #56 (Medium)
  Sheet    : Striver A2Z DSA (Arrays - Medium)

  Merge all overlapping intervals, return non-overlapping list.

  Example:
    [[1,5],[3,6],[8,10],[15,18]] → [[1,6],[8,10],[15,18]]
    [[5,7],[1,3],[4,6],[8,10]]   → [[1,3],[4,7],[8,10]]
    [[1,4],[4,5]]                → [[1,5]]  (touching counts as overlap)

  KEY RULE: sort by start time first → then a single pass
            comparing only with the LAST merged interval works.

  NOTE: vector<vector<int>> used — 2D dynamic output.

  HOW TO RUN:
  → Compile: g++ merge_intervals.cpp -o out && ./out
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
// ONLY APPROACH — Sort + Single Pass Merge
//
// Step 1: Sort intervals by start time
//         (this brings overlapping intervals adjacent)
//
// Step 2: Walk through sorted intervals
//   For each interval:
//     If ans is empty OR current.start > ans.back().end:
//        → NO overlap → push current as new entry
//     Else (current.start <= ans.back().end):
//        → OVERLAP → merge: ans.back().end = max(ans.back().end, current.end)
//
// Why comparing only with ans.back() works:
//   After sorting, if current doesn't overlap with the LAST
//   merged interval, it can't overlap with any earlier one
//   either (since all earlier ones end before or at ans.back())
//
// Time : O(N log N)   Space: O(N) for output
// =============================================================

vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
    int n = arr.size();

    // Step 1: sort by start time (arr[i][0])
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {

        // if ans is empty OR no overlap with last merged interval
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);          // push as a new interval
        }
        else {
            // overlap found → extend the end of last merged interval
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main() {
    cout << "===== MERGE OVERLAPPING INTERVALS =====" << endl;

    vector<vector<int>> v1 = {{1,5},{3,6},{8,10},{15,18}};
    cout << "Input  : [[1,5],[3,6],[8,10],[15,18]]" << endl;
    vector<vector<int>> r1 = mergeOverlap(v1);
    cout << "Output : "; printResult(r1);   // [[1,6],[8,10],[15,18]]
    cout << endl;

    vector<vector<int>> v2 = {{5,7},{1,3},{4,6},{8,10}};
    cout << "Input  : [[5,7],[1,3],[4,6],[8,10]]" << endl;
    vector<vector<int>> r2 = mergeOverlap(v2);
    cout << "Output : "; printResult(r2);   // [[1,3],[4,7],[8,10]]
    cout << endl;

    // touching intervals (edge case)
    vector<vector<int>> v3 = {{1,4},{4,5}};
    cout << "Input  : [[1,4],[4,5]]  (touching)" << endl;
    vector<vector<int>> r3 = mergeOverlap(v3);
    cout << "Output : "; printResult(r3);   // [[1,5]]
    cout << endl;

    // all overlapping into one
    vector<vector<int>> v4 = {{1,4},{2,5},{3,6}};
    cout << "Input  : [[1,4],[2,5],[3,6]]" << endl;
    vector<vector<int>> r4 = mergeOverlap(v4);
    cout << "Output : "; printResult(r4);   // [[1,6]]
    cout << endl;

    // no overlaps at all
    vector<vector<int>> v5 = {{1,2},{3,4},{5,6}};
    cout << "Input  : [[1,2],[3,4],[5,6]]" << endl;
    vector<vector<int>> r5 = mergeOverlap(v5);
    cout << "Output : "; printResult(r5);   // [[1,2],[3,4],[5,6]]

    return 0;
}


// =============================================================
// JUDGE CODE — LeetCode #56
// Copy ONLY this class when submitting online
// =============================================================

/*
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());  // sort by start time

        vector<vector<int>> ans;

        for (int i = 0; i < (int)intervals.size(); i++) {

            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);        // no overlap → new entry
            }
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]); // merge
            }
        }
        return ans;
    }
};
*/