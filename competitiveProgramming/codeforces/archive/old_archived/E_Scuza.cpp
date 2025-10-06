#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){ 
} // optional

void solve() {
    int n,q; cin >> n >> q;

    vector<ll> pfs(n+1); for(int i = 1; i <= n; i++)cin >> pfs[i];
    vector<int> steps(pfs.begin(),pfs.end()); 
    for(int i = 1; i <= n; i++){
        pfs[i] += pfs[i-1]; // for finding your height
        steps[i] = max(steps[i],steps[i-1]); // for finding which step to binary search to
    }

    while(q--){
        int query; cin >> query;

        auto guess = upper_bound(steps.begin(),steps.end(),query)-1;
        int guessi = guess - steps.begin();
        cout << pfs[guessi] << ' ';
    }
    cout << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
