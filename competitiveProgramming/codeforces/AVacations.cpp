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

    vector<int> nums(n); for(int i=0;i<n;i++){cin >> nums[i];}

    bool prevgym = false;
    bool prevcontest = false;

    int count = 0;

    for(int i = 0; i < n; i++){
        switch (nums[i]) {
            case 0:
                prevgym = false;
                prevcontest = false;
            break;

            case 1:
                prevgym = false;
                prevcontest = !prevcontest;
            break;

            case 2:
                prevgym = !prevgym;
                prevcontest = false;
            break;

            case 3: // invert because if you did it yesterday, don't today
                if(!prevgym && !prevcontest && i < n-1){ // counted the previous state
                    //look forward and do the opposite of that.
                    int next = i+1;
                    int count = 0;
                    while(next < n && nums[next] == 3){ next++; count++; }
                    if(next == n){prevgym = !prevgym; break;} //if next == n; doesn't matter.

                    if(nums[next] == 1){
                        if(count % 2 == 0){ prevgym = 1; } // try to save it for this one
                        else{ prevcontest = 1; } // save it for the other one or it's hopeless
                    }
                    else if(nums[next] == 2){
                        if(count % 2 == 1){ prevgym = 1; } // try to save it for this one
                        else{ prevcontest = 1; }       // save it for the other one or it's hopeless
                    }
                    else prevgym = !prevgym;  // doesn't matter which
                }
                else{
                    prevgym = !prevgym;
                    prevcontest = !prevcontest;
                }
            break;
        
        }
        if(!prevgym && !prevcontest){
            count++; // rest day
        }
    }
    cout << count << endl;
}

int main(){solve();}
