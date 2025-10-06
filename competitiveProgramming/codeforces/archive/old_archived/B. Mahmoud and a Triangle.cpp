#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> segments(n); for(int i = 0; i < n; i++){cin >> segments[i];}

    // non-degenerate triangle definition:
    // a + b > c && a - b < c && b - a < c
    // maybe only needs the 1st? not sure yet

    sort(segments.rbegin(), segments.rend());

    bool tri = false;
    for(int c = 0; c < n-2; ++c){
        int a = c+1, b = c+2;

        if(segments[a] + segments[b] > segments[c]){
            tri = true;
        }
        //cout << a << "," << b << "," << c << endl;
    }
    cout << (tri ? "YES" : "NO") << endl;
}

