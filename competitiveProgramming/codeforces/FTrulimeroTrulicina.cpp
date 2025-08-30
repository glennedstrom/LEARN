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
    int n,m,k; cin >> n >> m >> k;

    int time = n*m / k; // how many times each number must be placed

    // just start with the first two numbers alternating.
    //
    // split it into two queues and distribute them alternating from each queue.
    //
    // even/odd edge case needs to be handled when moving to new rows.

    
    int count = 0; // count by incrementing to time, then dequeue elements from the queue when you reset count
    deque<int> q1;
    deque<int> q2;
    for(int i = 1; i <= k; i ++){
        if(i % 2 == 1){
            q1.push_back(i);
        }
        else{
            q2.push_back(i);
        }
    }

    // TODO: odd counter is off. trying to distribute them in without messing up the pattern if it is odd

    int extra_count = time;

    for(int i = 0; i < n; ++i){
        if(q2.empty())break;
        for(int j = 0; j < m; ++j){
            if(q2.empty())break;
            if(count == time*2){
                q1.pop_front();q2.pop_front();
                count = 0;
            }
            //every other j swap
            if(extra_count){
                cout << q1.back() << ' ';
                ++j;
                extra_count--;
            }

            if(i % 2 == 0){ // need to swap the order
                if(j % 2 != 0){
                    cout << q1.front() << ' ';
                }
                else{
                    cout << q2.front() << ' ';
                }
            }
            else{
                if(j % 2 == 0){
                    cout << q1.front() << ' ';
                }
                else{
                    cout << q2.front() << ' ';
                }
            }
            count++;
        }
        cout << endl;
    }
}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
