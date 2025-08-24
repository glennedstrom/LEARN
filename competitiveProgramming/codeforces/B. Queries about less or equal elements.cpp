#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int n,m; cin >> n >> m;
    map<int,int> numCount;
    vector<int> a(n);for(int i = 0; i < n; i++){cin >> a[i];numCount[a[i]]++;}
    vector<int> b(m);for(int i = 0; i < m; i++)cin >> b[i];
    // prefix sum on the numCount shows how many numbers are less than the number

    // array a needs to be a max num range query
    // array b is the queries

    int prev = 0;
    for(auto& [k,v] : numCount){ // prefix map
        v += prev;
        prev = v;
    }

    for(int i = 0; i < b.size(); i++){
        auto it = numCount.upper_bound(b[i]);
        if(it == numCount.begin()){
            cout << 0 << ' ';
        }
        else{
            cout << (--it)->second << ' ';
        }
    }
    cout << endl;
}

int main()  {solve();}
