#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

vector<long long> tab;

long long factorial(long long n){
    if(n > tab.size()){return tab[n];}
    for(int i = tab.size(); i <= n; i++){
        tab.push_back(tab[tab.size()-1]*tab.size());
    }
    return tab[n];
}

long long choose(long long n, long long k){
    long long output = 1;
    for(int i = n; i > n - k; i--){ output *= i; } // to make the formula more stable
    return output / factorial(k);
}

int main()
{
    long long n,h=0,l=INT32_MAX; cin >> n;
    tab.push_back(1);
    tab.push_back(1);

    vector<long long> b(n); // beauty
    for(int i = 0; i < n; i++){ cin >> b[i]; h = max(h,b[i]); l = min(l,b[i]);}

    cout << h - l << " ";

    long long hc = 0, lc = 0;

    for(int i = 0; i < n; i++){
        hc += h == b[i];
        lc += l == b[i];
    }


    if(h == l){
        cout << choose(hc,2) << endl;
    }
    else{
        cout << hc * lc << endl;
    }
}
