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

bool isPrime(ll N) {
  if (N < _sieve_size) return bs[N];
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    if (N%p[i] == 0)
      return false;
  return true;
}

void solve() {
    int n; cin >> n;
    ll nums[400001];
    ll sumn = 0;
    for (int i = 0; i < n; i++){ cin >> nums[i]; sumn += nums[i]; }

    sort(nums,nums+n,greater<ll>());
    int remainder = 0;
    int best = 0;
    for(int i = 0; i < n; i++){
        best = i;
        if(remainder + nums[i] - p[i] >= 0 && nums[i] + remainder >= p[i]){ // if it is legal and you can afford it
            remainder += nums[i] - p[i];
            nums[i] -= nums[i] - p[i];
            // cout << "AAA: " << nums[i]  << " : " << remainder <<endl;
        }
        else{
            // i-=1;
            break;
        }
    }
    cout << n - best -1 << endl;

    return;

    // TODO: Our sum has to be greater than the sum of the first n primes.
    // TODO: find the index of the first sum of primes less than or equal to our value
    // IF IT IS LESS, you need 2*x for every x that you deleted. x == n - i + 1

    int i = 0; // count
    sumn -= 2*n; // must have at least 2 in each spot; when subtracting I removed every 2 from added primes too to compensate
    while(i < n && sumn - (p[i] - 2) >= 0){ // stay above zero
        sumn -= (p[i] - 2);
        // cout << p[i] << ' ';
        i++;
    }
    // cout << endl;

    // cout << sumn << endl;

    cout << n - i  << endl; // how many I need to delete to make it work
}

int main(){
    sieve(400001);
    ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
