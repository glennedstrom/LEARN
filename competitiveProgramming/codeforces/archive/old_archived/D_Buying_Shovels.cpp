#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){
    // optional
}

void solve() {
    int n,k; cin >> n >> k;

    int best = 1;
    for(int i = 1; i <= k && i*i <= n; i++){
        if(n % i == 0 && i <= k){
            best = max(best,i);
        }
        if(n % i == 0 && n/i <= k){
            best = max(best,n/i);
        }
    }

    cout << n/best << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
