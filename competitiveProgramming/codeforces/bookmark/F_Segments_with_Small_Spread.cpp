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

// TODO: Bookmark this algorithm. Copy this to a special bookmark folder.

void solve() {
    ll n,k; cin >> n >> k;
    vector<ll> v(n); for(auto& i : v)cin >> i;

    // 7 3
    // 2 6 4 3 6 8 9

    // If the values are decreasing, push to the back of maxdq; if they are higher than the back, pop until they are equal so you can push to the dq
    //
    deque<ll> maxdq;
    deque<ll> mindq;

    ll cnt = 0;
    int l = 0;
    for(int r = 0; r < n; r++){
        // Remove anything below v[r] to set the new max from between (prev_max) and r
        while(!maxdq.empty() && maxdq.back() < v[r]) maxdq.pop_back();
        maxdq.push_back(v[r]);
        // Remove anything above v[r] to set the new min from between (prev_min) and r
        while(!mindq.empty() && mindq.back() > v[r]) mindq.pop_back();
        mindq.push_back(v[r]);

        while(maxdq.front()-mindq.front() > k){
            if(maxdq.front() == v[l]){ maxdq.pop_front(); }
            if(mindq.front() == v[l]){ mindq.pop_front(); }
            l++;
        }
        ll span = maxdq.front() - mindq.front();
        if(span <= k){
            cnt += r-l+1;
        }
    }

    cout << cnt << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
