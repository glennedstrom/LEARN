#include <unordered_set>
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

unordered_multiset<int> prime_factors(int n){
    unordered_multiset<int> factors;

    for(int i = 2; i*i <= n; i++){
        if(n == 1)break;
        while(n % i == 0){
            n /= i;
            factors.insert(i);
        }
    }

    return factors;
}

void solve() {
    int n; cin >> n;

    unordered_multiset<int> pf = prime_factors(n);

    cout << n << ": ";
    for(auto& factor : pf){
        cout << factor << ' ';
    }
    cout << endl;

}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
