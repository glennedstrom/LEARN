#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

long long f(long long n){
    long long o = (n-1)*n/2;
    return o ;
}

void solve() {
    long long x; cin >> x;

    // sum of all below i:
    
    //long long h=1e10,l=1;
    cout << x*2+1 << endl;

    // while(h-l != 0){
    //     long long mid = (h-l)/2+l;
    //     //for(int mid = 1; mid < 10; mid++){ // REPLACE ME WITH BINARY SEARCH
    //     long long o = f(mid);
    //     //cout << o << " " << i << endl;
    //     if(o / x == mid && o % x == 0){
    //         //cout << f(mid) / x << endl;
    //         h = mid;
    //         l = mid; // not needed
    //         break;
    //     }
    //     else if(o / x > mid){ // NOT SURE WHAT TO DO WITH REMAINDERS
    //         h = mid - 1;
    //     }
    //     else{
    //         l = mid + 1;
    //     }
    // }
    // cout << f(h) / x << endl;
}

int main(){solve();}
