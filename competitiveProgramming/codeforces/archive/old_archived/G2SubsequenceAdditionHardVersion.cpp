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
    int n; cin >> n;
    vector<int> sol(n); for(int i = 0; i < n; i++)cin >> sol[i];
    sort(sol.begin(),sol.end());
    //count how many 1s, then we can always move forward at most that many. move forward however far we can go and move there
    //see if every number is reachable from the original 

    int sum = sol[0] == 1; // base case
    bool possible = true;
    for(int i = 1; i < n; i++){
        if(sol[i] <= sum){
            sum += sol[i];
        }
        else{
            possible = false;
            break;
        }
    }
    

    if(possible && sum > 0)YES;
    else NO;
}

// 1 1 2 4 8
// no matter how hard you try, you can jump from the lowest value to the highest value
// as long as the next number is lower than the sum, it is possible.
//
// go on this assumption because time is out


int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
