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
    int n,m; cin >> n >> m;

    unordered_set<int> visited; // NOTE: visited might not even be needed, not many repeated subproblems and all cases decrease fast towards zero?
                                // Seemed to use more memory because the queue fills more, and was slower (but both always vary and are hard to compare)
    queue<int> q;
    q.push(n);

    while(!q.empty()){
        n = q.front();
        //cout << n << endl;
        q.pop();
        if(visited.find(n) != visited.end()){ continue; } visited.insert(n); // skip already visited
        if(n == m){ YES; return; }
        if(n < m || n % 3 != 0) continue; // skip if impossible

        int a = n/3;
        int b = a*2;

        q.push(a);
        q.push(b);
    }
    NO;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
