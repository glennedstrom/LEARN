#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;



void solve() {
    string s; int q; cin >> s >> q;
    vector<int> pfs(s.size(),0);

    for(int i = 0; i < s.size()-1; i++){ pfs[i+1] = pfs[i] + (s[i] == s[i+1]); }
    while(q--){
        int l,r; cin >> l >> r;

        cout << pfs[r-1] - (l > 0 ? pfs[l-1] : 0) << endl;
    }
}

int main() {solve();}
