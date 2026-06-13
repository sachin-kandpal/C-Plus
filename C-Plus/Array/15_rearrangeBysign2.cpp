#include <bits/stdc++.h>
using namespace std;

// Rearrange array with alternating positive and negative numbers.
// Extra elements (if any) are appended at the end while preserving order.
vector<int> alternateNumbers(vector<int> &a) {

    // Store positives and negatives separately
    vector<int> pos, neg;

    for (int i = 0; i < a.size(); i++) {

        if (a[i] >= 0)
            pos.push_back(a[i]);
        else
            neg.push_back(a[i]);
    }

    // More positives
    if (pos.size() > neg.size()) {

        // Fill alternately
        for (int i = 0; i < neg.size(); i++) {
            a[2 * i] = pos[i];
            a[2 * i + 1] = neg[i];
        }

        // Append remaining positives
        int index = 2 * neg.size();

        for (int i = neg.size(); i < pos.size(); i++) {
            a[index] = pos[i];
            index++;
        }
    }
    // More negatives or equal
    else {

        // Fill alternately
        for (int i = 0; i < pos.size(); i++) {
            a[2 * i] = pos[i];
            a[2 * i + 1] = neg[i];
        }

        // Append remaining negatives
        int index = 2 * pos.size();

        for (int i = pos.size(); i < neg.size(); i++) {
            a[index] = neg[i];
            index++;
        }
    }

    return a;
}

int main() {

    vector<int> a = {1, 2, -4, -5, 3, 4};

    vector<int> ans = alternateNumbers(a);

    cout << "Rearranged Array: ";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}