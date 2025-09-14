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
#include <ranges>

void solve() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    for (int x : v 
    | views::filter([](int n){ return n % 2 == 0; })
    | views::transform([](int n){ return n * n; })) {
        cout << x << " "; // Output: 4 16 36
    }


}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
