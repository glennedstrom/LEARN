#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

int euclid(int a, int b){
    if(b == 0) return a;
    int temp = b;
    b = a % b;
    a = temp;
    return euclid(a,b);
}

void solve() {
    int n; cin >> n;

    int count = 0;
    for(int i = 1; i <= n; ++i){
        if(euclid(i,n) == 1)
            count++;
    }
    cout << count << endl;
}

int main(){solve();}
