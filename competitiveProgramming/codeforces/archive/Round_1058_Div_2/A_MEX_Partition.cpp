#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/contest/2160/problem/A
* Date:    Sun 12 Oct 2025 09:39:25 AM CDT
* Contest: Codeforces Round 1058 (Div. 2):
* Problem: A. MEX Partition
* Limits:  1000ms, 256MB
*/

void precalc(){
    // optional
}

void solve() {
    int n; cin >> n;
    vector<int> v(n); for(auto& i : v) cin >> i;
    ranges::sort(v);

    if(v[0] != 0){ cout << 0 << endl; return; }


    for(int i = 1; i < n; i++){
        if(v[i] != v[i-1] + 1){
            cout << v[i] + 1 << endl;
            return;
        }
    }
    cout << v[n-1]+1 << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
