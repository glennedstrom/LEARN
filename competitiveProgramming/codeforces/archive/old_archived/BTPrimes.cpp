#include <bits/stdc++.h>
using namespace std;

int main()
{
    // pre-compute primes
    vector<bool> is_prime(1000001,true);
    is_prime[0] = is_prime[1] = false;
    for(long long i = 2; i < is_prime.size(); i++){ // maybe limit to root n to skip second factor terms
        if(is_prime[i]){
            for(long long j = i*i; j < is_prime.size(); j += i){
                is_prime[j] = false;
            }
        }
    }

    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        long long n; cin >> n; // 10**12
        long long rootn = sqrt(n); // sqrt(10**2)

        if(rootn * rootn == n){
            // Then check if rootn is prime because that implies n is prime
            cout << (is_prime[rootn] ? "YES" : "NO") << endl;
        }
        else{ // impossible
            cout << "NO" << endl;
        }
    }

    return 0;
}
