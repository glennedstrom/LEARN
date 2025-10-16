#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/contest/2160/problem/C
* Date:    Sun 12 Oct 2025 10:35:13 AM CDT
* Contest: Codeforces Round 1058 (Div. 2):
* Problem: C. Reverse XOR
* Limits:  2000ms, 256MB
*/

void precalc(){
    // optional
}

void solve() {
    ll n; cin >> n;
    if(n == 0){ cout << "YES" << endl; return; }


    ll o1 = 0;
    ll o2 = 0;

    for(int i = 1; i <= n; i <<= 1){
        bool on = (n & i) != 0;

        if(on){
            o1 |= i;
        }
        else{
            o1 |= i;
            o2 |= i;
        }
    }
    auto sxor = [](string a, string b){
        string o = "";
        for(int i = 0; i < a.size(); i++){
            o.push_back(to_string(a[i] != b[i])[0]);
        }
        cout << o << endl;
        return stoll(o);
    };
    string o1s = to_string(o1);
    string o2s(o1s);
    reverse(o2s.begin(),o2s.end());

    for(int i = 0; i < 3; i++){
        if(sxor(o1s,o2s) == n){
            cout << "YES" << endl;
            return;
        }
        o1s = '1' + o1s;
        o2s = o2s + '1';
    }
    cout << "NO" << endl;
    return;
    if((o1 ^ o2) == n){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return;
    cout << endl;

    ll temp = n;
    string s;

    auto num_to_bin = [](ll temp){
        string s;
        while(temp){
            s = to_string(temp & 1) + s;
            temp >>= 1;
        }
        return s;
    };
    s = num_to_bin(n);

    // different kind of burte force: try with the current length, then try with a 1 on the left then 11 on the left and so on
    //
    // CREATE BOTH x0 and x0rev at the same time
    // DOESN'T MATTER WHICH YOU ASSIGN THE 'on' BIT TO! xor is the same either way

    string x;
    string xrev;

    for(int i = n-1; i >= 0; i--){

    }








    return;
    //brute force
    for(int i = 0; i < n*2; i++){
        string stemp = num_to_bin(i);
        string stemprev(stemp.rbegin(),stemp.rend());

        if((bitset<32>(stemp) ^ bitset<32>(stemprev)) == n){
            cout << i << ": " << stemp << endl;
            return;
        }
    }
    cout << "n/a: " << s << endl;

}

// X ^ X' = N(110)

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
