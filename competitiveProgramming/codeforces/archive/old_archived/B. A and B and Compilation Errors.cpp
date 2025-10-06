#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int n; cin >> n;
    unordered_map<int,int> errors;
    unordered_map<int,int> errors2;
    int temp;
    for(int i = 0; i < n; ++i){cin >> temp;errors[temp]++;}
    for(int i = 0; i < n-1; ++i){cin >> temp;errors[temp]--;errors2[temp]++;}
    for(auto& [k,v] : errors)if(v != 0){
        cout << k << endl;
        v--;
    }
    for(int i = 0; i < n-2; ++i){cin >> temp;errors2[temp]--;}
    for(auto& [k,v] : errors2)if(v != 0){
        cout << k << endl;
        v--;
    }

}

int main() {solve();}
