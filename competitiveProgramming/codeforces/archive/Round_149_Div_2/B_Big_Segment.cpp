#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/contest/242/problem/B
* Date:    Fri Oct  3 23:52:03 2025
* Contest: Codeforces Round 149 (Div. 2):
* Problem: B. Big Segment
* Limits:  2000ms, 256MB
*/

void precalc(){
    // optional
}

void solve() {
    int n; cin >> n;
    vector<pair<pair<int,int>,int>> segs(n); for(int i = 0; i < n; i++){int a,b;cin >> a >> b;segs[i] = {{a,b},i};}

    ranges::sort(segs,[](pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
        if(a.first.first == b.first.first){
            return a > b;
        }
        return a < b;
    });
    int high = segs[0].first.second;
    for(int i = 0; i < n; i++){
        if(segs[i].first.second > high){
            cout << -1 << endl;
            return;
        }
    }
    cout << segs[0].second+1 << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
