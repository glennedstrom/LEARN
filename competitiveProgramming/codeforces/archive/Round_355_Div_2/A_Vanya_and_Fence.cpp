#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* https://codeforces.com/problemset/problem/677/A
* Tue Sep 30 14:31:01 2025
* Codeforces Round 355 (Div. 2): A. Vanya and Fence;
* 1000ms, 256MB
*/

void precalc(){
    // optional
}

void solve() {
    int n,h; cin >> n >> h;
    vector<int>v(n); for(auto& i : v)cin >> i;

    int tot = 0;
    for(int i = 0; i < n; i++){
        tot += v[i] > h ? 2 : 1;
    }
    cout << tot << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
