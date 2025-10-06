#include <iomanip>
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){
    // optional
}

void solve() {
    double target; cin >> target;


    auto f = [&](double x){
        return x*x + pow(x,0.5);
    };


    double l = 0, r = 1e18;

    while(r-l >= 1e-8){
        double mid = (r-l)/2+l;

        if(f(mid) < target){
            l = mid;
        }
        else{
            r = mid;
        }
    }

    cout << fixed << setprecision(8) << r << endl;

}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
