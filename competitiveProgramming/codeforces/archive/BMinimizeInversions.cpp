#include <algorithm>
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
    int n; cin >> n; 
    int temp;
    vector<pair<int,int>> nums(n); for(int i = 0; i < n; i++){
        cin >> temp;
        nums[i] = {temp, i};
    }
    vector<pair<int,int>> nums2(n); for(int i = 0; i < n; i++){
        cin >> temp;
        nums2[i] = {temp, i};
    }

    // auto [i1,i2] = minmax_element(nums.begin(),nums.end());
    // cout << *i1 << ' ' << *i2 << endl;
    sort(nums.begin(),nums.end(),[](pair<int,int> a, pair<int,int> b){
        return a.i < b.first && ;
    });
    for(int i = 0; i < n; i++){
        // minimize the cost each iteration until you can't better it.
        cout << nums[i] << ' ';
    }
    cout << endl;
}

// ISSUE: NO CLUE HOW TO SOLVE AT ALL!

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
