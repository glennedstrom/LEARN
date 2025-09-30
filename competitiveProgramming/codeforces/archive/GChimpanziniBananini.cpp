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
    int q; cin >> q;

    deque<int> nums;
    bool forward = true;

    while(q--){
        int s; cin >> s;

        if(s == 1){
            if(forward){
                nums.push_front(nums.back()); nums.pop_back();
            }
            else{
                nums.push_back(nums.front()); nums.pop_front();
            }
            // or an index counter mod s.size();
        }
        else if(s == 2){
            forward = !forward;
        }
        else if(s == 3){
            int k;
            if(forward){
                nums.push_back(k);
            }
            else{
                nums.push_front(k);
            }
        }

        //calculate rizzness.
        int tot = 0;
        if(forward){
            for(int i = 1; i <= nums.size(); i++){
                tot += *(nums.begin() + i-1)*i;
            }
        }
        else{
            for(int i = 1; i <= nums.size(); i++){
                tot += *(nums.rbegin() + i-1)*i;
            }
        }
        cout << tot << endl;
    }
}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
