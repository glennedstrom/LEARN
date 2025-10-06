#include <ranges>
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){
    // optional
}

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(auto& i : a)cin >> i;
    vector<int> b(n); for(auto& i : b)cin >> i;

    auto v = views::zip(a,b);
    vector<pair<int,int>> ab(v.begin(),v.end());

    sort(ab.begin(),ab.end(),[](pair<int,int> a, pair<int,int> b){
        return a.first+a.second < b.first+b.second;
    });
    for(auto& [ai,bi] : ab){
        cout << ai << ' ';
    }
    cout << endl;
    for(auto& [ai,bi] : ab){
        cout << bi << ' ';
    }
    cout << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
