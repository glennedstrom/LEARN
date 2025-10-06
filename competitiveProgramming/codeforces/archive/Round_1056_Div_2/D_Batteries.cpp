#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/contest/2155/problem/D
* Date:    Sun Oct  5 12:38:33 2025
* Contest: Codeforces Round 1056 (Div. 2):
* Problem: D. Batteries
* Limits:  2000ms, 256MB
*/

void precalc(){
    // optional
}

void solve() {
    int n; cin >> n;
    cout << endl;

    // batteries are 1 to n;
    vector<pair<int,int>> queries;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j+i <= n; j++){
            if(i+j<=n){
                queries.emplace_back(j,j+i);
            }
        }
    }
    //for(int i = 1; i <= n; i++){
    //    for(int j = i+1; j <= n; j++){
    //        queries.emplace_back(i,j);
    //        //cout << i << ' ' << j << endl;
    //        //int ans; cin >> ans;

    //        //if(ans){
    //        //    return;
    //        //}
    //    }
    //}
    //sort
    //int mid = n/2;
    //ranges::sort(queries,[&](pair<int,int> a, pair<int,int> b){
    //    return abs(a.first-mid)+abs(a.second-mid) < abs(b.first-mid)+abs(b.second-mid);
    //});
    for(auto& [a,b] : queries){
        cout << a << ' ' << b << endl;
        int ans; cin >> ans;

        if(ans){
            return;
        }
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
