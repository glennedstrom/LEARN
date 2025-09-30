#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int n; cin >> n;
    bool flag = false;
    while(n--){
        int a,b; cin >> a >> b;

        if(a < b){
            flag = true;
        }
    }
    if(flag){
        cout << "Happy Alex" << endl;
    }
    else{
        cout << "Poor Alex" << endl;
    }
}

int main(){solve();}
