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

bool canFormTriangle(int a, int b, int c) {
  return (a+b > c) && (a+c > b) && (b+c > a);
}

void solve() {
    int n; cin >> n;

    vector<int> nums(n+1);
    vector<pair<int,int>> mx;
    vector<pair<int,int>> mn;
    for(int i = 1; i <= n; i++){ 
        cin >> nums[i]; 
        mx.push_back({nums[i],i});
        mn.push_back({nums[i],i});
        sort(mx.rbegin(),mx.rend());
        sort(mn.begin(),mn.end());
        if(mx.size() > 3){
            mx.pop_back();
            mn.pop_back();
        }
    }


    int a = mn[0].first, b = mn[1].first, c = mx[0].first;
    if(!canFormTriangle(a,b,c)){
        vector<int> indexes = {mn[0].second,mn[1].second,mx[0].second};
        sort(indexes.begin(),indexes.end());
        for(auto& i : indexes)cout << i << ' ';
        cout << endl;
        return;
    }
    cout << -1 << endl;
}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
