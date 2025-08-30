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

long long f(long long k, vector<long long>& a, long long l, long long r){
    long long ans = 0;

    for(int i = l; i <= r; i++){
        while(k % a[i] == 0){
            k /= a[i];
        }
        ans += k;
    }
    return ans;
}

void solve() {
    long long n,q; cin >> n >> q;
    vector<long long> a(n+1);
    for(int i = 1; i <= n; i++){cin >> a[i];}

    
    while(q--){
        long long k,l,r; 
        cin >> k >> l >> r;
        cout << f(k,a,l,r) << endl;
    }
}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
