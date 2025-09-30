#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){
    // optional
}

void solve() {
    int n; cin >> n;

    vector<int> factors(n+1,0);

    int almost_prime = 0;
    for(int i = 2; i <= n; i++){
        if(factors[i] == 2){
            almost_prime++;
        }
        if(!factors[i]){
            for(int j = i+i; j <= n; j += i){
                factors[j]++;
            }
        }
    }
    cout << almost_prime << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
