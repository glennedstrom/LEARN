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
    int n,x,y; cin >> n >> x >> y;

    auto f = [&](int elapsed){
        if(elapsed < min(x,y)) return 0; // not enough for any copies
        elapsed -= min(x,y); // must do the first copy before doing other copies
        return elapsed / x + elapsed / y + 1; // updated elapsed time plus the first copy
    }; // returns copies per unit time

    int l=0,r=2e9;
    while(l+1 < r){
        int mid = (r-l)/2+l;

        // IF GOOD (too many copies), shift right end
        // IF BAD (too few copies), shift left end to get closer
        if(f(mid) < n){ // guess is too few
            l = mid;
        }
        else{ // guess is greater than or equal to our answer
            r = mid;
        }
    }

    // l is the most copies that are not enough
    // r is the fewest copies that is good enough
    cout << r << endl;
}






/*
*
*
*
*
*
*|1|1|1|1|1|1
* 0|0 0 0 0 1
* 1 2 3 4 5 7
*
*
*
*/




































int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
