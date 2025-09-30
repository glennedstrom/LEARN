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
    int tvs,strength; cin >> tvs >> strength;


    multiset<int> carrying;
    for(int i = 0; i < tvs; i++){
        int temp; cin >> temp;
        if(temp < 0){
            carrying.insert(-temp);
        }
        if(carrying.size() > strength){
            //drop
            carrying.erase(carrying.begin());
        }
    }
    int sum = 0;
    for(auto& moolah : carrying){
        sum += moolah;
    }
    cout << sum << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
