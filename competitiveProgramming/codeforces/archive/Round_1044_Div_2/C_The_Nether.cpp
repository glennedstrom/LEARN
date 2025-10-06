#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/problemset/problem/2133/C
* Date:    Wed Oct  1 04:28:32 2025
* Contest: Codeforces Round 1044 (Div. 2)
* Problem: C. The Nether
* Limits:  3000ms, 256MB
*/

void precalc(){
    // optional
}

void solve() {
    int n; cin >> n;

    vector<int> longest_paths(n+1); // longest paths starting from node i

    for(int x = 1; x <= n; x++){
        // query for finding each max length path:
        cout << "? " << x << " " << n; for(int x = 1; x <= n; x++){ cout << " " << x; } cout << endl;
        int response; cin >> response; assert(response != -1);
        longest_paths[x] = response;
    }
    // n queries left. delete a node and see if it changes.
    // if it changes, put back the node and try another one.
    // do this for every node (except the start, but doesn't matter.)
    int besti = 1; for(int i = 1; i <= n; i++){ if(longest_paths[i] > longest_paths[besti]){ besti = i; } }

    //vector<int> temp(n); iota(temp.begin(),temp.end(),1);

    set<pair<int,int>> s;
    for(int i = 1; i <= n; i++){
        s.insert({longest_paths[i], i}); // sort by paths, save node index
    }

    for(int x = 1; x <= n; x++) if(x != besti){
        s.erase({longest_paths[x], x});
        // query elements in s without x
        cout << "? " << besti << " " << s.size(); for(auto& i : s){cout << " " << i.second;}cout << endl;
        int response; cin >> response; assert(response != -1);

        // if wrong, insert it back in.
        if(response != longest_paths[besti]){ s.insert({longest_paths[x], x}); }
    }

    // rebuild the path by sorting pairs of longest_paths with their indexes
    cout << "! " << s.size();
    if(besti == s.begin()->second){ // use begin operators
        for(auto& [dist,i] : s){
            cout << " " << i;
        }
    }
    else{ // rbegin
        for(auto& [dist,i] : views::reverse(s)){
            cout << " " << i;
        }
    }
    cout << endl;

}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
