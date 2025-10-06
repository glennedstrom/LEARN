#include <algorithm>
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/problemset/problem/1914/D
* Date:    Thu Oct  2 02:08:31 2025
* Contest: Codeforces Round 916 (Div. 3):
* Problem: D. Three Activities
* Limits:  2000ms, 256MB
*/

void precalc(){
    // optional
}

void solve() {
    int n; cin >> n;

    int temp;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> temp;
        a[i] = {temp,i};
    }
    vector<pair<int,int>> b(n); 
    for(int i = 0; i < n; i++){
        cin >> temp;
        b[i] = {temp,i};
    }
    vector<pair<int,int>> c(n); 
    for(int i = 0; i < n; i++){
        cin >> temp;
        c[i] = {temp,i};
    }
    //ranges::sort(a, greater<pair<int,int>>());
    //ranges::sort(b, greater<pair<int,int>>());
    //ranges::sort(c, greater<pair<int,int>>());
    partial_sort(a.begin(),a.begin()+3, a.end(),greater<pair<int,int>>());
    partial_sort(b.begin(),b.begin()+3, b.end(),greater<pair<int,int>>());
    partial_sort(c.begin(),c.begin()+3, c.end(),greater<pair<int,int>>());

    // tuples of top 3 elements in each. Sort this to know urgencies for duplicates: first then second if tie then third if tie
    vector<tuple<pair<int,int>,pair<int,int>,pair<int,int>>> v = {{a[0], a[1], a[2]},{b[0], b[1], b[2]},{c[0], c[1], c[2]},};
    ranges::sort(v, [](auto& a, auto& b){
        return tie(get<0>(a).first, get<1>(a).first, get<2>(a).first) > tie(get<0>(a).first, get<1>(a).first, get<2>(a).first);
    });
    // greatest to least

    //int tot = get<0>(v[0]).first;
    //if(get<0>(v[0]).second == get<0>(v[1]).second){

    //}
    //tot = get<0>(v[0]).first + get<0>(v[1]).first + get<0>(v[2]).first;


    int tot = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)if(a[i].second != b[j].second){
            for(int k = 0; k < 3; k++)if(a[i].second != c[k].second && b[j].second != c[k].second){
                tot = max(tot, a[i].first+b[j].first+c[k].first);
            }
        }
    }
    cout << tot << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
