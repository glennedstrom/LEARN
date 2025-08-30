#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b; // init
    vector dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = 1; i <= a.size(); i++) { dp[i][0] = i; }
    for (int i = 1; i <= b.size(); i++) { dp[0][i] = i; }

    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else {
                int replace = dp[i - 1][j - 1] + 1;
                int insert = dp[i][j - 1] + 1;
                int del = dp[i - 1][j] + 1;
                dp[i][j] = min(replace, min(insert, del));
            }
        }
    }
    for (auto &v : dp) {
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << "Edit Distance: " << dp[a.size()][b.size()] << endl;

    // Backtrack to re-build the edits

    int i = a.size(), j = b.size();

    while (i > 0 || j > 0) {
        int replace = dp[i - 1][j - 1] + 1;
        int insert = dp[i][j - 1] + 1;
        int del = dp[i - 1][j] + 1;

        if (i > 0 && j > 0 && a[i - 1] == b[j - 1]) {
            // no change
            cout << "LEAVE: " << a[i - 1] << endl;
            i--;
            j--;
        } else if (j > 0 && dp[i][j] == insert) {
            // insert a[i-1] into b
            cout << "INSERT: " << b[j - 1] << endl;
            j--;
        } else if (i > 0 && dp[i][j] == del) {
            // delete a[i-1]
            cout << "DELETE: " << a[i - 1] << endl;
            i--;
        } else if (i > 0 && j > 0 && dp[i][j] == replace) {
            // replace a[i-1] for b[i-1] // OR reverse if going from b to a
            cout << "REPLACE: " << a[i - 1] << " -> " << b[j - 1] << endl;
            i--;
            j--;
        }
    }
    cout << "DONE" << endl;
}

int main() { int testcase; cin >> testcase; while (testcase--) { solve(); } } //{solve();}
