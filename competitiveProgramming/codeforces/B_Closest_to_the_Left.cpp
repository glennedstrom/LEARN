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
    int n,k; cin >> n >> k;
    vector<int> v(n); for(auto& i : v)cin >> i;
    v.insert(v.begin(),0);
    vector<int> q(k); for(auto& i : q)cin >> i;

    for(auto& target : q){
        int l = 1, r = n+1;

        while (l < r){
            int mid = (r-l)/2+l;

            if(v[mid] <= target){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }

        // GOAL: UPPER BOUND: equal or less

        // Equal to target case:
        //if(l != n+1 && v[l] == target){
        //    cout << l << endl; // one indexed, equal
        //}
        //// Too high; Doesn't exist case: go back one
        //else {
        //    cout << l-1 << endl; // one indexed, too large
        //}

        // All cases I'm one too high: sub one
        cout << l-1 << endl; // one indexed, too large
    }

}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
