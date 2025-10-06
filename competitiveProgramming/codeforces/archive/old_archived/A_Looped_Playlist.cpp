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
    ll n,p; cin >> n >> p;

    ll vsum = 0;
    vector<ll>v(n); for(auto& i : v){cin >> i;vsum += i;}

    // you need to compute first how many total sums can fit into the number, then two pointers from there to "finish it off" maybe
    ll sums = (p / vsum-1) * vsum; // distributing it in evenly without going over. Then two pointers to finish it off; Maybe subtract one to make sure it works?


    ll bestl = -1;
    ll bestc = 1e18;
    // cout << '!' << p - sums << endl;
    // cout << p << ',' << vsum << "," << sums << endl;
    ll l = 0;
    ll acc = 0;

    for(ll r = 0; r < 2*n; r++){
        acc += v[r%n];

        while(sums + acc - v[l%n] >= p){
            acc -= v[l%n];
            l++;
        }
        // cout << l << "," << r << ": " << sums + acc << endl;

        ll cur_cnt = (p/vsum-1)*(ll)v.size() + r-l+1;
        if(acc+sums >= p && cur_cnt < bestc){ // this is a valid sum, and a new shortest length
            bestl = l;
            bestc = cur_cnt;
            cout << (p/vsum-1)*(ll)v.size() << " + " << r-l+1 << endl;
        }
    }
    cout << bestl + 1 << ' ' << bestc << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
