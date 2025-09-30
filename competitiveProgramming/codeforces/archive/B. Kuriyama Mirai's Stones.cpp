#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int n; cin >> n;
    vector<long long> cost(n+1);
    for(int i = 1; i <= n; i++){cin >> cost[i];}
    vector<long long> scost(cost.begin(),cost.end());
    sort(scost.begin(),scost.end());

    for(int i = 2; i <= n; i++){
        cost[i] += cost[i-1];
        scost[i] += scost[i-1];
    }

    int m; cin >> m;

    while(m--){
        int type, l, r; cin >> type >> l >> r;
        switch (type) {
            case 1: // sum of values between l and r
                cout << cost[r] - cost[l-1] << endl;
            break;
            case 2: // sum of lth cheapest to rth cheapest stones
                cout << scost[r] - scost[l-1] << endl;
            break;
        }
    }
}

int main(){solve();}
