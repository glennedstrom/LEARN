#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// EPS for doubles; do 1e-6 for floats
#define EPS 1e-9
#define INF 1e9

void solve() {
    ll target,n; cin >> target >> n; // target balloons inflated

    vector<ll> inflate_time(n); // inflate time balloon
    vector<ll> endurance(n);
    vector<ll> rest_mins(n);
    for(ll i = 0; i < n; i++){ cin >> inflate_time[i] >> endurance[i] >> rest_mins[i]; }

    auto balloon_per_employee = [&](ll elapsed, ll i){
        if(elapsed <= 0) return 0ll;
        assert(0 <= i && i < n);
        ll epoch = inflate_time[i] * endurance[i] + rest_mins[i]; // time per endurance[i] balloons in one cycle

        ll cur = elapsed / epoch * endurance[i]; // how many balloons we can inflate (lower bound) {how many epochs * balloons per epoch}
        ll remainder = elapsed % epoch; // time remaining after all epochs
        cur += min(remainder / inflate_time[i], endurance[i]); // remaining balloons = minimum of how many you can inflate nonstop, and max before getting tired
        assert(cur >= 0);
        return cur;
    };

    auto f = [&](ll elapsed){
        ll inflated = 0;
        for(ll i = 0; i < n; i++){ 
            inflated += balloon_per_employee(elapsed, i);
        }
        return inflated;
    }; // all employees inflate [endurance] balloons (inflate_time*endurance) then rest +rest_mins minutes

    // ll l=-1, r=1e18; // -1 because L has to be -1 for the upper bound to be 0

    // while(l+1 < r){
    //     ll mid = (r-l)/2+l;

    //     if(f(mid) < target){
    //         l = mid;
    //     }
    //     else{
    //         r = mid;
    //     }
    // }
    ll l=0, r=1e18; // -1 because L has to be -1 for the upper bound to be 0

    while(l < r){
        ll mid = (r-l)/2+l;

        if(f(mid) < target){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }

    // NOTE: OUTPUT AT MOST target BALLOONS; I fixed this, but I'm still having issues
    cout << r << endl;

    ll predicted = 0;
    for(ll i = 0; i < n; i++){ predicted += balloon_per_employee(r, i); }

    ll extras = predicted - target; // predicted too many; make some workers not work (extra times)

    // cout << predicted << ", " << target << ", " << r << ", " << f(r)  << ", "<< f(0)<< endl;

    for(ll i = 0; i < n; i++){ // we need to get each employee's balloon counts
        if (extras && balloon_per_employee(r, i) != balloon_per_employee(r-1, i)){ // if an employee recently finished and we made too many balloons: stop this balloon
            cout << balloon_per_employee(r-1, i) << ' ';
            // assert(balloon_per_employee(r-1, i) == balloon_per_employee(r, i)-1);
            extras--;
        }
        else{
            cout << balloon_per_employee(r, i) << ' ';
        }
    }
    cout << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
