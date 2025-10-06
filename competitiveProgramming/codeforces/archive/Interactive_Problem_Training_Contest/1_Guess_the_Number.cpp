#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* Wed Oct  1 03:51:57 2025
* Interactive Problem Training Contest: 1. Guess the Number; https://codeforces.com/gym/101021/problem/1
* 1000ms, 256MB
*/

void precalc(){
    // optional
}

void solve() {
    int l = 0, r = 1000001; 

    while(l+1<r){
        int mid = (r+l)/2;

        cout << mid << endl; // query
        string response; cin >> response;
        if(response == "<"){ // target < guess ; guess lower.
            r = mid;
        }
        else{
            l = mid;
        }
    }

    cout << "! " << l << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
