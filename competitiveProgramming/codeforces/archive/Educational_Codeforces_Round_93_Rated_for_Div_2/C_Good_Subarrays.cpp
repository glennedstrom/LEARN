#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/problemset/problem/1398/C
* Date:    Thu Oct  2 06:29:37 2025
* Contest: Educational Codeforces Round 93 (Rated for Div. 2):
* Problem: C. Good Subarrays
* Limits:  2000ms, 256MB
*/

void precalc(){
    // optional
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    // two pointers, but also keep track of how many extra subarrays could be made?
    //
    // a bunch of 1's can all be subarrays made.
    // a bunch of 0s shrinks the sum relative to the size
    // everything else grows the sum
    //
    // Any group of 1's can be valid groups on their own.
    // Any 0's need to be grouped with 2 or higher
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
