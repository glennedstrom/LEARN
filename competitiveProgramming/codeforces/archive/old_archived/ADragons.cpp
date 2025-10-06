#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
// EPS for doubles; do 1e-6 for floats
#define EPS 1e-9
#define INF 1e9

void solve() {
    int s,n; cin >> s >> n;
    vector<pair<int,int>> drags(n);
    for(int i = 0; i < n; i++){
        int strength, bonus; cin >> strength >> bonus;
        drags[i] = {strength, bonus};
    }

    sort(drags.begin(),drags.end());

    for(int i = 0; i < n; i++){
        if(s <= drags[i].first){ // dragon wins
            cout << "NO" << endl;
            return;
        }
        s += drags[i].second;
    }
    cout << "YES" << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
