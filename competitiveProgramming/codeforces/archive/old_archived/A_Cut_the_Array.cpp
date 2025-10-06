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
    int n; cin >> n;

    vector<int> v(n+1); for (int i = 1; i <= n; i++)cin >> v[i];
    vector<int> pfs(v); for (int i = 1; i <= n; i++){ pfs[i] += pfs[i-1];}


    //sum1 == pfs[l] % 3
    //sum2 == (pfs[r] - pfs[l]) % 3
    //sum2 == (pfs[n] - pfs[r]) % 3


    //int r = 2; // strictly greater than l
    // check the value and move forwards to find a valid solution with r
    for(int l = 1; l < n; l++){
        //int s1 = pfs[l] % 3;
        //int s2 = (pfs[r] - pfs[l]) % 3;
        //int s3 = (pfs[n] - pfs[r]) % 3;
        //while(r < l && (!(s1 == s2 && s2 == s3) || !(s1 != s2 && s2 == s3))){
        for(int r = l+1; r < n; r++){
            int s1 = pfs[l] % 3;
            int s2 = (pfs[r] - pfs[l]) % 3;
            int s3 = (pfs[n] - pfs[r]) % 3;
            if((s1 == s2 && s2 == s3) || (s1 != s2 && s2 != s3 && s1 != s3)){
                //cout << l << "," << r << "," << n <<  ": " << s1 << " " << s2 << " " << s3 << endl;
                cout << l << " " << r << endl;
                return;
            }
        }
    }
    cout << 0 << " " << 0 << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
