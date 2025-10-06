#include <cstdint>
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
// EPS for doubles; do 1e-6 for floats
#define EPS 1e-9
#define INF 1e9

void solve() {
    int n; cin >> n;
    string s; cin >> s;


    int a = 0;
    int b = 0;

    // count how many initially
    for(int i = 0; i < n; i++){
        if(s[i] == 'a'){ a++; }
        else{ b++; }
    }

    // try to remove a's
    //int ai = a;
    //for(int i = 0; i < n; i++){
    //    if(ai = 0){
    //        best = min(best, )
    //    }
    //    if(s[i] == 'a'){ ai--; }
    //    else{ ai++; }
    //}












    int best = INT32_MAX; // minimize r-l+1
    if(a == b){
        cout << 0 << endl;
        return;
    }

    // either remove A's or B's is our goal
    if(a > b){
        int score = abs(a - b);
        int offset = 0;
        int l = 0;
        for(int r = 0; r < n; r++){
            if(a > b){
                if(s[r] == 'a'){ score--;offset--; }
                else{ score++;offset++; }
            }
            else{
                if(s[r] == 'b'){ score--;offset--; }
                else{ score++;offset++; }
            }

            while(offset > 0){ // shrink if we grow in the wrong direction
                if(r-l+1 >= 1 && score == 0){
                    best = min(best,r-l+1);
                }
                if(a > b){
                    if(s[l] == 'a'){ score++;offset++;}
                    else{ score--;offset--;}
                }
                else{
                    if(s[l] == 'b'){ score++;offset++;}
                    else{ score--;offset--;}
                }
                l++;
            }

            if(r-l+1 >= 1 && score == 0){
                best = min(best,r-l+1);
            }
        }
    }
    //int l = 0;
    //for(int r = 0; r < n; r++){
    //    if(s[r] == 'a'){ a--; }
    //    else{ b--; }
    //    //cout << l << " ";
    //    //cout << r << " ";
    //    //cout << best << " ";
    //    //cout << s << " ";
    //    //cout << endl;

    //    while(r-l+1 >= 1 && a == b){ // i need to expand until I find a match, then this loop shrinks it if it is a match
    //        best = min(best,r-l+1);
    //        if(s[l] == 'a'){ a++; }
    //        else{ b++; }
    //        l++;
    //    }
    //}
    //int r = n-1;
    //while(l <= r){ // i need to expand until I find a match, then this loop shrinks it if it is a match
    //    if(r-l+1 < best && a == b){
    //        best = r-l+1;
    //    }
    //    if(s[l] == 'a'){ a++; }
    //    else{ b++; }
    //    l++;
    //}

    if(best == n){
        cout << -1 << endl;
    }
    else{
        cout << best << endl;
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
