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

    // 5*1 + 5*2 + ... 5 * n : time to complete the problems

    int solved = 0;
    int time = 0;
    for(int i = 1; i <= n; i++){
        time += 5*i;
        if(60*4 - time - k >= 0){
            solved++;
        }
    }
    cout << solved << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
