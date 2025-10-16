#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/problemset/problem/1742/D
* Date:    Sun 12 Oct 2025 12:32:54 PM CDT
* Contest: Codeforces Round 827 (Div. 4):
* Problem: D. Coprime
* Limits:  3000ms, 256MB
*/



vector<vector<int>> prime_factors(1001); // unique prime factors, no duplicates
vector<vector<int>> gcd_table(1001, vector<int>(1001, 0));
void precalc(){
    // optional
    for(int i = 2; i < 1001; i++){
        if(prime_factors[i].size() == 0){ //is prime
            for(int j = i; j < 1001; j+= i){
                prime_factors[j].push_back(i); // add the current prime factor to all like sieve
            }
        }
    }

    for(int i = 0; i < 1001; i++){
        for(int j = 0; j < 1001; j++){
            gcd_table[i][j] = gcd(i,j);
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<int> v(n); for(auto& i : v) cin >> i;

    vector<int> cnt(1001); // count of all the prime factors so far

    auto insert_factors = [&](int num){
        bool unique = true;
        for(auto& factor : prime_factors[num]){
            if(cnt[factor]){ unique = false; }

            ++cnt[factor];
        }
        return unique;
    };
    // throw in the first prime factors manually:
    insert_factors(v[n-1]);

    // then loop through the rest and try to find one that matches


    //vector<int> post(v);
    //post.push_back(post.back()); // to allow me to check the last element with itself
    int running_gcd = v.back();
    for(int i = n-1; i >= 0; i--){
        running_gcd = gcd(running_gcd, v[i]);
        if(running_gcd == 1){
            for(int j = n-1; j >= i; j--){
                if(gcd(v[i],v[j]) == 1){
                    cout << i+j+2 << endl; 
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
    //return;
    //for(int i = 0; i < n; i++){ cout << v[i] << ' '; } cout << endl;
    ////for(int i = 0; i < n; i++){ cout << post[i] << ' '; } cout << endl;
    //cout << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
