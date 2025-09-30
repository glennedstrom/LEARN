#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int n,m; cin >> n >> m;

    vector<int> nums(n+1); for(int i=0; i<n;++i){cin >> nums[i+1];}
    unordered_set<int> bin;

    vector<int> pfs(n+1);
    for(int i = n; i >= 1; i--){
        bin.insert(nums[i]);
        pfs[i] = bin.size();
    }

    while(m--){
        int i;cin >> i;
        cout << pfs[i] << endl;
    }
}

int main() {solve();}
