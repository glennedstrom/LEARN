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


// 0: 1 2 3 4 5
// 1: 1 2 3 5 4
// 2: 1 2 5 3 4
// 3: 1 5 2 3 4
// 4: 5 1 2 3 4
//
// 2: 1 2 4 5 3
// 3: 1 2 5 4 3
// 4: 1 4 5 2 3
// 5: 1 5 4 2 3
// 6: 1 4 5 2 3
//
//
//
//
// REDO: opposite ends to make sure subsegments have minimal inversion values.
// right next to each other if you want maximum
// 0: 1 2 3 4 5
// 4: 1 2 3 5 4
// 4: 2 3 4 5 1
// 0: 1 2 3 4 5
// 0: 1 2 3 4 5
// 0: 1 2 3 4 5
// 0: 1 2 3 4 5
//


// put the 5 at index n-1 - inversions
// put 4 at n-1 - inversions
//
// if you need n-1 or more inversions put 5 at the beginning then move on to the next one


void solve() {
    int n, k; cin >> n >> k;

    vector<int> p(n+1);
    iota(p.begin(),p.end(),0);

    // move the big boys back first then fill in the rest in order after finished


    for(int i = 1; i <= n; i++){
        cout << p[i] << ' ';
    }
    cout << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
