#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){
    // optional
}

void solve() {
    int n; cin >> n;
    set<int> remaining;
    vector<int> p(n); for(auto& i : p){cin >> i;remaining.insert(i);}

    int l = 0;
    int r = n-1;
    while(l <= r && (p[l] == *remaining.begin() || p[l] == *remaining.rbegin() || p[r] == *remaining.begin() || p[r] == *remaining.rbegin())){
        while(l <= r && (p[l] == *remaining.begin() || p[l] == *remaining.rbegin())){
            remaining.erase(p[l]);
            l++;
        }
        while(l <= r && (p[r] == *remaining.begin() || p[r] == *remaining.rbegin())){
            remaining.erase(p[r]);
            r--;
        }
    }
    //assert(r-l+1 == remaining.size());
    if(remaining.size() == 0){
        cout << -1 << endl;
    }
    else{
        //for(auto& i : remaining)cout << i << ' ';
        cout << l+1 << ' ' << r+1 << endl;
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
