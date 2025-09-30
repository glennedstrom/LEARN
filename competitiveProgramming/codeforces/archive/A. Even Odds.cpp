#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k; cin >> n >> k;
    long long oddn = n / 2 + n % 2; // number of odd numbers
    long long output;
    //cout << (k <= oddn) << endl;
    if(k <= oddn){ // if odd
        output = (k-1)*2+1;
    }
    else{
        output = (k-oddn)*2;
    }
    cout << output << endl;
}
