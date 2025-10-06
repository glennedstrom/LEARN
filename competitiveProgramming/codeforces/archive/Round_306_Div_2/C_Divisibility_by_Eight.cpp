#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/problemset/problem/550/C
* Date:    Thu Oct  2 04:34:54 2025
* Contest: Codeforces Round 306 (Div. 2):
* Problem: C. Divisibility by Eight
* Limits:  2000ms, 256MB
*/

// {{{ data_structures/sparse_table.cpp }}}

#include <vector>
#include <algorithm>

#include <vector>
#include <cassert>

void precalc(){
    // optional
}

void solve() {
    string n; cin >> n;
    if(n.find('8') != string::npos){ cout << "YES\n" << 8 << endl; return; }
    if(n.find('0') != string::npos){ cout << "YES\n" << 0 << endl; return; }

    vector<string> keys(125); for(int i = 0; i < 125; i++){ keys[i] = to_string(i*8); } // all possible prefixes

    for(auto& key : keys){ // loop through keys then check if each one is a subsequence in n

        int i = 0;
        int k = 0;
        for(int j = i; j < n.size(); j++) if(k < key.size()){
            if(key[k] == n[j]){
                k++;
            }
        }
        if(k == key.size()){
            //valid
            cout << "YES" << endl;
            cout << key << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
