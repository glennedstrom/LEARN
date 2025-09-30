#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){
    // optional
}

void solve() {
    int n,q; cin >> n >> q;

    vector<int> a(n); for(auto& i : a) cin >> i;
    
    int bucket = sqrt(n); // bucket size
    vector<int> b((n-1)/bucket+1, -1); // size is bucket ceiled
    for(int i = 0; i < n; i++){ b[i/bucket] = max(b[i/bucket], a[i]); } // put all i vals into their buckets

    int deliveries = 0;
    while(q--){
        int l,r; cin >> l >> r;
        l--;r--;r--; // INFO: One indexed, and you don't have to be taller than your destination, only crash into it or over it.
        int highest = -1;
        int start = a[l];

        while(l<=r){
            if(l % bucket == 0 && bucket <= r-l+1){ // move a bucket at a time
                highest = max(highest, b[l/bucket]);
                l += bucket;
            }
            else{ // not in bucket
                highest = max(highest,a[l]);
                l++;
            }
        }

        if(highest == start || highest == -1){
            deliveries++;
        }
    }
    cout << deliveries << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
