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

// primes up to root n first; then using the primes, 
// multiply them with each other to generate primes within your range using two pointers? 
// the product of any two unique primes is a "four divisor"
//
// primes up to root root n
// because if we have primes up to root root n, then we can use them to find the other primes up to root n, then each of these pairs can be multiplied to create 4 divisors
//
// use math on the length of this list to compute number of 4 divisors
//
// because these are all primes, they are guaranteed to be unique when multiplied
//
// TODO: compute primes up to root n
// Use this to get the pairs above root n

typedef long long ll;
typedef vector<ll> vll;

ll _sieve_size;
bitset<10000010> bs;
vll p;

// TODO: call sieve in the main method
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
    ll n; cin >> n;

    vector<ll> primes; // only compute up to but not including sqrt(n)

    ll rootn = pow(n,0.5); // NOTE: If truncation, how does it affect numbers right before root n? make it slightly bigger just in case, then exclude some?
    vector<bool> is_prime(rootn+1, true); // only compute up to but not including sqrt(n)
    is_prime[0] = is_prime[1] = false;

    //cout << n << ' ' << rootn << endl;
    for(ll i = 2; i <= rootn; i++) if (is_prime[i]){
        //cout << i << ' ';
        primes.push_back(i);
        for(ll j = i*i; j <= rootn; j += i){
            is_prime[j] = false;
        }
    }
    //cout << endl;
    //
    // n / prime (integer divide)
    // then from the answer, do n / prime
    // keep checking if each is prime?
    // NOTE: I think this is pretty good.
    // Will it actually visit every prime though? probably not.
    ll cnt = 0;
    for(auto& p : primes){ // TODO: Figure out how this is so fast. // sqrt n times log n times primes
                            // MAYBE IT IS: primes * log(sqrt(n))
        ll a = n/p;
        while(a > p){
            if(a != p && isPrime(a)){
                cnt+=1;
            }
            a = a-=p;
        }
    }
    for (auto& p : primes) if(p*p*p <= n){ cnt++; }
    cout << cnt << endl;
    return;
    // for(auto& p : primes){
    //     for(int i = n/p){
    //     }
    // }

    //cout << "COUNT: " << cnt << endl; 

    // cout << "PRIMES: ";
    // for(auto& p : primes) cout << p << ' ';
    // cout << endl;
    ll preprimepairs = primes.size() * (primes.size() + 1)/2; // pairs of all existing primes below root n
    for (auto& p : primes) if(p*p*p <= n){ preprimepairs++; }
    // cout << preprimepairs << endl;
    // multiply by all primes less than sqrt(n/2)? because 2*n/2 is n so nothing can be higher than that. NO
    
    //ll cnt = 0;
    for(int i = 0; i < primes.size(); i++){
        if(is_prime[n / primes[i]] && primes[i] != n / primes[i]){ // find opposite prime pair?
            cnt++;
        }
        for(int j = i+1; j < primes.size(); j++){
            if(primes[i] * primes[j] <= n){
                cnt += 2;
            }
        }
    }


    // NOTE: JUST COUNT THE PRIMES UP TO ROOT N, any divisors will be 
    // nevermind, not sure
    //
    // for(auto& p : primes){
    //     if(n % p == 0 && is_prime[n/p]){
    //         cnt++;
    //     }
    // }

    cout << cnt << endl;
}
// INFO: Ground truths:
// Prime * prime IF prime != otherprime: 
// COUNT == REAL PRIMES UNDER N/2 
// IF N / PRIME < sqrt(N) THEN IT HAS something? at N / PRIME, check if that is valid?
//
// Maybe check if the number's prime is itself? otherwise don't
//
//
//
//
//
// Primes: 2 3 5 7
// any prime pairs that multiply to le 10
// 2 3
// 2 5
// 2 4 // EDGE CASE: prime^3 is also a unique case. primes to any odd power could count. 2^5 has 2^1,2^4 and 2^2,2^3. primes to even powers too 2^8 == 2^ 
//
//
//
//
//
//
//
//
//
//
//

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
