#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/contest/2155/problem/B
* Date:    Sun Oct  5 11:45:44 2025
* Contest: Codeforces Round 1056 (Div. 2):
* Problem: B. Abraham's Great Escape
* Limits:  1500ms, 256MB
*/

void precalc(){
    // optional
}

void solve() {
    int n,k; cin >> n >> k;

    if(n*n-1 == k ){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    vector<vector<char>> o(n, vector<char>(n,'U'));
    int ki = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ki >= k){
                o[i][j] = 'D';
            }
            ki++;
        }
    }
    for(int i = 0; i < n; i++){
        if(o[n-1][i] == 'D'){
            o[n-1][i] = 'R';
        }
    }
    if(n*n != k){
        o[n-1][n-1] = 'L';
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << o[i][j];
        }
        cout << endl;
    }
    
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
