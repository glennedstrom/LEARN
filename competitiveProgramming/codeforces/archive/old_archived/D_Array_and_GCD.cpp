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
ll _sieve_size;
bitset<10000010> bs;
vll p;

void sieve(ll upperbound) {
  _sieve_size = upperbound+1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    p.push_back(i);
  }
}

void solve() {
    int n; cin >> n;
    vector<ll> nums(n+1);
    for (int i = 1; i <= n; i++){ cin >> nums[i]; } sort(nums.rbegin(), nums.rend()-1);

    // needs left,right pointers for the PFS to check for the maximum array size X that can be less than the sum of the first X primes
    vector<ll> ppfs(p.begin(),p.begin() + n);
    ppfs.insert(ppfs.begin(),0); for(int i = 1; i < n+1; i++){ ppfs[i] += ppfs[i-1]; }


    ll acc = 0;
    int best = 0;

    // very similar to 2 pointers; because we sorted, 2 pointers isn't needed & greedy works. (NOTE: The sort takes nlogn)
    for(int r = 1; r <= n; r++){
        acc += nums[r];
        //maximum size that meets the condition
        if(acc >= ppfs[r]){ // keep acc ge sum(primes to r)
            best = max(best, r); // length of valid
        }
        else break; // can't make primes anymore with our sum
    }

    cout << n - best << endl; // deleted is n - length of valid
}

int main(){
    sieve(bs.size()-1); // to get the length of the primes to be bigger than 4e5
    ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
