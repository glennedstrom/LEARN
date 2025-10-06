#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/contest/2155/problem/A
* Date:    Sun Oct  5 11:35:15 2025
* Contest: Codeforces Round 1056 (Div. 2):
* Problem: A. El fucho
* Limits:  1000ms, 256MB
*/

void precalc(){
    // optional
}

void solve() {
    int n; cin >> n;

    int tot = 0;
    
    int winners_group = n;
    int losers_group = 0;

    while(winners_group > 1){
        tot += winners_group/2;

        losers_group += winners_group / 2;
        winners_group -= winners_group / 2;
    }
    while(losers_group > 1){
        tot += losers_group/2;

        losers_group -= losers_group / 2;
    }
    tot++;
    cout << tot << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
