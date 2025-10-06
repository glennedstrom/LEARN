#include <cstdint>
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){ }

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(auto& i : a){cin >> i;}

    int bucket = sqrt(n);
    vector<int> b((n+bucket-1)/bucket, INT32_MAX); // (n+bucket-1)/bucket == ceil(n/bucket)
    for(int i = 0; i < n; i++){
        b[i/bucket] = min(b[i/bucket], a[i]);
    }

    int q; cin >> q;
    while(q--){
        int l,r; cin >> l >> r;
        int ans = INT32_MAX;

        while(l<=r){
            if(l%bucket == 0 && bucket <= r-l+1){ // bucket <= length of remaining array & fits in evenly divisible
                ans = min(ans,b[l/bucket]);
                l += bucket;

            }
            else{
                ans = min(ans,a[l]);
                l++;
            }

        }
        cout << ans << endl;
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
