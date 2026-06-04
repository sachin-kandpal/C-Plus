#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1. Take the input string
    string s;
    cin >> s;

    // 2. Precompute character frequencies
    // An array size of 256 covers all standard ASCII table indices (0 to 255).
    // Initializing with {0} sets all starting frequencies to zero.
    int hash[256] = {0};
    for (int i = 0; i < s.size(); i++) {
        // C++ implicitly converts the character s[i] to its ASCII integer value
        hash[s[i]]++; 
    }

    // 3. Process the queries
    int q;
    cin >> q; // Read total number of queries
    while (q--) {
        char c;
        cin >> c; // Read the specific character to look up
        
        // Fetch the precomputed frequency in O(1) constant time
        cout << hash[c] << endl;
    }

    return 0;
}