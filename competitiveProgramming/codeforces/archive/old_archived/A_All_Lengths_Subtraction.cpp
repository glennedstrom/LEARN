#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){
    // optional
}

void solve() {
    int n; cin >> n;
    vector<int> v(n); for(auto& i : v)cin >> i;

    auto mei = max_element(v.begin(),v.end());

    int target = *mei - 1;
    // expand from me on both ends
    int l = (mei - v.begin()) - 1;
    int r = (mei - v.begin()) + 1;
    while(true){
        // cout << l << ", " << r  << ": " << target << endl;
        if(l != -1 ){
            if(v[l] == target){
                //cout << "L: " << *l << " : " << me << endl;
                target--;
                l--;
                continue;
            }
        }
        if(r < v.size()){
            if(v[r] == target){
                //cout << "R: " << *r << " : " << me << endl;
                target--;
                r++;
                continue;
            }
        }
        //cout << "END LR: " << v.begin() - l << ", " << v.begin() - r << " : " << me << endl;
        cout << (l <= - 1 && r >= v.size() ? "YES" : "NO") << endl;
        return;
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
