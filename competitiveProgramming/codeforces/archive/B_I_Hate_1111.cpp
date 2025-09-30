#include <string>
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

bitset<1100> dp;

// NOTE: The chicken mcnugget theorem states that if a,b are coprime, then they can sum to any numbers greater than a*b - a - b
//
void solve() {
    int n; cin >> n;
    cout << (n > 111*11-111-11 || dp[n] ? "YES" : "NO") << endl;
}


int main(){
    dp.reset();
    dp.set(0);
    vector<int> ones = {11,111}; // all numbers above 1099 can be made up of 11 and 11 per the Chicken McNugget Theorem because 11 and 111 are coprime
    int upper = 111*11-111-11;
    for(int x = 0; x <= upper; x += 1) if(dp[x]){
        for (auto& jump : ones) if(x+jump < upper){
            dp.set(x+jump);
        }
    }
    ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}
}
