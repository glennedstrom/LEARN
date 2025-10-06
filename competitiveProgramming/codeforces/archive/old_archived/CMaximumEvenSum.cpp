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

vector<ll> greatest_factors(ll x){
    vector<ll> factors;
    for(int i = 1; i*i <= x; i++){
        if(x % i == 0){
            factors.push_back(x/i);
            factors.push_back(i);
        }
    }
    return factors;
}
 
void solve() {
    long long a,b; cin >> a >> b;
 
    unordered_set<ll> visited(b+1);
 
    ll ans = -1;
    queue<pair<ll,ll>> q; q.push({a,b});
 
    while(!q.empty()){
        auto [a,b] = q.front();
        q.pop();
        if(visited.find(b) != visited.end())continue;
        visited.insert(b);
 
        if((a+b) % 2 == 0){
            ans = max(ans,a+b);
        }
 
        vector<ll> c = greatest_factors(b);
 
        //cout << b << ": "; for(int i = 0; i < c.size(); i++){ cout << c[i] << ' '; } cout << endl;
        for(int i = 0; i < c.size(); i++){
            ll a2 = a*c[i], b2 = b / c[i];
            if(visited.find(b2) == visited.end())
                q.emplace(a2,b2);
        }
    }
    cout << ans << endl;
}


// vector<ll> greatest_factors(ll x){
//     vector<ll> factors;
//     for(int i = 2; i*i <= x; i++){
//         if(x % i == 0){
//             factors.push_back(i);
//             factors.push_back(x/i);
//         }
//     }
//     return factors;
// }
// ll next_factor(ll x){
//     for(int i = 2; i*i <= x; i++){
//         if(x % i == 0){
//             return i;
//         }
//     }
//     return x;
// }
// 
// void solve() {
//     long long a,b; cin >> a >> b;
// 
//     ll ans = -1;
//     //vector<pair<ll,ll>> dp(b+1, {-1,-1});
//     //dp[b] = {a,b};
// 
//     if((a+b)%2==0){ans = a+b;}
// 
//     pair<ll,ll> next = {a,b};
//     for(int i = b; i >= 1; i--){
//         pair<ll,ll> cur = next;
//         if(cur.second == -1){continue;}
// 
//         if((cur.first+cur.second) % 2 == 0){
//             ans = max(ans,cur.first+cur.second);
//         }
// 
//         //vector<ll> c = greatest_factors(cur.second);
//         ll c = next_factor(b);
//         next = {a*c, b/c};
//         continue;
// 
//         int x = cur.second;
//         for(int i = 1; i*i <= x; i++){
//             if(x % i == 0){
//                 int num = i;
//                 ll a2 = cur.first*num, b2 = cur.second / num;
//                 if(a2%2 == b2 % 2) // both even or both odd sums to even.
//                     next = {a2,b2};
//             }
//         }
//     }
//     cout << ans << endl;
// 
//     // cout << ans << endl;
//     // return;
// 
//     // //vector<bool> visited(b+1);
// 
//     // queue<pair<ll,ll>> q; q.push({a,b});
// 
//     // while(!q.empty()){
//     //     auto [a,b] = q.front();
//     //     q.pop();
//     //     if(visited[b])continue;
//     //     visited[b] = true;
// 
//     //     if((a+b) % 2 == 0){
//     //         ans = max(ans,a+b);
//     //     }
// 
//     //     vector<ll> c = greatest_factors(b);
// 
//     //     //cout << b << ": "; for(int i = 0; i < c.size(); i++){ cout << c[i] << ' '; } cout << endl;
//     //     for(int i = 0; i < c.size(); i++){
//     //         ll a2 = a*c[i], b2 = b / c[i];
//     //         if(!visited[b2])
//     //             q.emplace(a2,b2);
//     //     }
//     // }
// }

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
