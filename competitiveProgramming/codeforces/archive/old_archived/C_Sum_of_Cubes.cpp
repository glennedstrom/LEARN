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
    ll target; cin >> target;
    //up to 10k
    ll upper = 10001;
    auto test = [](ll l, ll r, ll target){return pow(l,3) + pow(r,3) == target;};
    auto testlt = [](ll l, ll r, ll target){return pow(l,3) + pow(r,3) < target;};
    auto testgt = [](ll l, ll r, ll target){return pow(l,3) + pow(r,3) > target;};

    for(ll up = 1; up < upper; up++){
        // binary search for the other value
        int l = 1, r = up+1;

        while(l<r){
            ll mid = (r-l)/2+l;

            if(testlt(mid,up,target)){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }

        if(test(l,up,target)){ cout << "YES" << endl; return; }
    }
    cout << "NO" << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
