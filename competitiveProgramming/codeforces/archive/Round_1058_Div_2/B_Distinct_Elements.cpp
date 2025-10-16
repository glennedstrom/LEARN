#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/contest/2160/problem/B
* Date:    Sun 12 Oct 2025 09:41:14 AM CDT
* Contest: Codeforces Round 1058 (Div. 2):
* Problem: B. Distinct Elements
* Limits:  1500ms, 256MB
*/

void precalc(){
    // optional
}

void solve() {
    int n; cin >> n;
    vector<ll> b(n); for(auto& i : b) cin >> i;

    // moving from i to i+1 you can:
    // let acc be the running total
    // +distinct for repeating the same element
    // +distinct+1 for a new element
    set<int> distinct;
    distinct.insert(1);
    //cout << 1 << ' ';
    ll acc = 1;

    // if it's one higher then it's a repeat of the previous value
    // if it's two higher it's back two.
    // go back n to find out
    vector<int> out;
    out.push_back(1);

    for(int i = 1; i < n; i++){
        if(b[i] - b[i-1] > out.size()){
            out.push_back(i+1); // new value
        }
        else{
            out.push_back(out[i-(b[i]-b[i-1])]); // look back
        }
    }


    for(int i = 0; i < n; i++){
        cout << out[i] << ' ';
    }
    cout << endl;




}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
