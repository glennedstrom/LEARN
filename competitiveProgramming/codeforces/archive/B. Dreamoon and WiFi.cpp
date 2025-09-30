#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

vector<long long> tab; 
long long factorial(long long n){
    if(n < tab.size()){ return tab[n]; }
    while(tab.size() <= n){
        tab.push_back(tab[tab.size()-1]*tab.size());
    }
    return tab[n];
}

long long choose(long long n, long long k){
    return factorial(n)/factorial(n-k)/factorial(k); // div by fact(k) might cause flooring error
}


int main()
{
    string ans, out; cin >> ans >> out;

    cout << fixed << setprecision(12);
    int a = 0;
    int o = 0;
    int qcount = 0;
    for(auto& c : ans){ a += c == '+'; a -= c == '-'; }
    for(auto& c : out){ o += c == '+'; o -= c == '-'; qcount += c == '?'; }
    tab.push_back(1); tab.push_back(1);

    // NOTE: USE COMBINATORICS WITH PASCALS TRIANGLE TO COMPUTE EVERYTHING YOU NEED
    double prob = 0;
    if(!(qcount - abs(o - a) >= 0 && (qcount - abs(o-a)) % 2 == 0 )){ cout << prob << endl; return 0; } // if it is impossible
     
    // steps away CHOOSE (half==0; offset +- 2)
    // Denominator: 2^n
    long long n = qcount;
    long long k = (qcount+abs(o-a))/2;
    long double numerator = choose(n,k);
    long double denominator = pow(2,n);

    cout << numerator/denominator << endl;
    return 0;

}
/*
-2: 1 ; 2c0
0: 2  ; 2c1
2: 1  ; 2c2
1/4 ---------
--
-+
+-
    ++

-3: 1 ; 3c0
-1: 3 ; 3c1
1 : 3 ; 3c2
3 : 1 ; 3c3
3/8
---
    --+
    -+-
-++
    +--
+-+
++-
+++

-4: 1 ; 4c0
-2: 4 ; 4c1
0: 6  ; 4c2
2: 4  ; 4c3
4: 1  ; 4c4

// you can walk over then add each or just compute it from the beginning

0
6/16 
----
---+
--+-
    --++
-+--
    -+-+
    -++-
-+++
+---
    +--+
    +-+-
+-++
    ++--
++-+
+++-
++++
*/
