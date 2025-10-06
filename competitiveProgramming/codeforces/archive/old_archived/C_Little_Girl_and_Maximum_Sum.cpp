#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,q; cin >> n >> q;

    vector<ll> v(n); for(auto& i : v)cin >> i;
    sort(v.rbegin(),v.rend());

    vector<ll> counter(n+2, 0);

    while(q--){
        ll l,r;
        cin >> l >> r;
        counter[l]++;
        counter[r+1]--;
    }
    
    //smoothen the range: non-decreasing to the maximum, non-increasing to the end by filling the gaps
    // "push" the left values through the array with a prefix sum. It will naturally shrink as they pop from the -1
    for(ll i = 1; i < counter.size(); i++){ counter[i] += counter[i-1]; }

    // NOTE: If the highest count is 5 then have the first 5 elements in the subarray v[i]*5 where v[i] is the largest so far
    sort(counter.rbegin(),counter.rend());

    // Now the highest counts are at the end of our counter
    ll tot = 0;
    for(ll i = 0; i < n; i++){
        tot += v[i] * counter[i]; // multiply max value with highest count
    }

    cout << tot << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
