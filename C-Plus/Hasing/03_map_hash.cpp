#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1. Read size of the array
    int n;
    cin >> n;
    
    // 2. Read the elements into the array
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 3. Precompute frequencies using std::map
    unordered_map<int, int> mpp; 
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++; 
    }

    // // 4. Iterate and print the entire map structure
    // cout << "--- Map Elements (Key -> Frequency) ---" << endl;
    // for (auto it : mpp) {
    //     cout << it.first << " -> " << it.second << endl;
    // }
    // cout << "---------------------------------------" << endl;

    // 5. Handle the queries

    int q;
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        
        // Fetch the frequency count from the map
        cout << "Frequency of " << number << ": " << mpp[number] << endl;
    }

    return 0;
}


//                    TIME COMPLEXITY COMPARISON: MAP vs UNORDERED_MAP
//
//  OPERATION      |  std::map (Ordered)         |  std::unordered_map
//  ---------------|-----------------------------|------------------------------
//  Insertion      |  O(log N)                   |  O(1) [Worst case: O(N)]
//  Deletion       |  O(log N)                   |  O(1) [Worst case: O(N)]
//  Lookup/Fetch   |  O(log N)                   |  O(1) [Worst case: O(N)]