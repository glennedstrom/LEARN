#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//vector<ll> factorial;
void precalc(){
    //factorial.assign(4,1);
    //for(ll i = 2; i < factorial.size(); i++){
    //    factorial[i] = factorial[i-1] * i;
    //}
}

// ll choose(ll n, ll k){
//     if(n <= 0 || k > n) return 0; // make sure you choose at least something
//     ll res = 1;
//     for(int i = n; i > n-k; i--){ res *= i; } // n!/(n-k)!
//     return res / factorial[k]; // /k!
//     //return factorial[n]/factorial[k]/factorial[n-k];
// }

void solve() {
    int n; cin >> n;
    vector<int> k(n); for(auto& i : k)cin >> i; // k values


    vector<ll> counts(n+1,0); //counts[k] = count of length 2^k
    for(int i = 0; i < n; i++){ counts[k[i]]++; }
    vector<ll> lt(counts); // less than or equal to count
    for(int i = 1; i <= n; i++){lt[i] += lt[i-1];}
    // right shift
    for(int i = n-1; i >= 0; i--){lt[i+1] = lt[i];}
    lt[0] = 0;


    // it is a triangle iff you choose two from the upper number and choose one from anything less than or equal to the current number
    //
    // take 3 length c[i]        take 2 length ci and 1 less than ci
    // choose(ci,3)         +   (choose(ci,2) * choose(lt,1))

    ll tot = 0;
    for(int i = 0; i <= n; i++){
        ll ci = counts[i];
        tot += ci*(ci-1)*(ci-2)/6; // ci choose 3
        tot += ci*(ci-1)/2 * lt[i]; // (ci choose 2) * (lt choose 1)
    }
    cout << tot << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
