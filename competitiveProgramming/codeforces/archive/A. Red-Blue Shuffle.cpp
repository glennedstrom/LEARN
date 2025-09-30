#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int n; cin >> n;

        vector<char> r(n);
        vector<char> b(n);

        for(int i = 0; i < n; i++){ cin >> r[i]; }
        for(int i = 0; i < n; i++){ cin >> b[i]; }

        int red = 0;
        int blue = 0;

        for(int i = 0; i < n; i++){
            if(r[i] > b[i]){ red++; }
            else if(b[i] > r[i]){ blue++; }
        }

        cout << (red == blue ? "EQUAL" : red > blue ? "RED" : "BLUE") << endl;

    }

    return 0;
}
