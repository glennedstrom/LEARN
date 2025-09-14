#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
// EPS for doubles; do 1e-6 for floats
#define EPS 1e-9
#define INF 1e9

void solve() {
    long long n; cin >> n;

    cout << (n % 2 == 0 ? 1ll<<n/2 : 0) << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
