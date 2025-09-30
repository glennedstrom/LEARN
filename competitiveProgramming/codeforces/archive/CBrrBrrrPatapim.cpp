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
    int n; cin >> n;
    vector nums(n,vector<int>(n));
    unordered_set<int> s;
    for(int i = 0; i < n; i++){for(int j = 0; j < n; j++){cin >> nums[i][j];s.insert(nums[i][j]);}}

    for(int i = 1; i <= 2*n; i++){
        if(s.find(i) == s.end()){
            cout << i << ' ';
        }
    }

    for(int i = 0; i < n; i++){
        cout << nums[i][0] << ' ';
    }
    for(int j = 1; j < n; j++){
        cout << nums[n-1][j] << ' ';
    }
    cout << endl;
}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
