#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

int euclid(int a, int b){
    if(b == 0) return a;
    int temp = b;
    b = a % b;
    a = temp;
    
    return euclid(a,b);
}

void solve() {
    
    bitset<1001> isPrime; isPrime.set();
    isPrime[0] = 0; isPrime[1] = 0;
    for(int i = 4; i < isPrime.size(); i+=2) isPrime[i] = 0;
    for(int i = 3; i*i < isPrime.size(); i+=2){
        if(!isPrime[i])continue;
        for(int j = i*i; j < isPrime.size(); j += 2*i) isPrime[j] = 0;
    }

    for(int i = 0; i < 1001; i++)if(isPrime[i]){cout << i << ' ';}
    cout << endl << endl;
    return;

    int n; cin >> n;

    vector<int> nums(n+1); for(int i = 1; i <= n; i++){ cin >> nums[i]; }

    //memo.assign(1001, vector<int>(1001,-1));

    // SOLUTION: Something to do with precomputation because a_i <= 1000. like primes or something
    // maybe a version of the primes algorithm for this problem
    //
    // prime factorization? get the primes, then get the prime factors for a number checking if they mod each other, then you can have a much 

    

    int o = -1;
    for(int i = n; i >= 1; i--){
        for(int j = i; j <= n; j++){
            if(euclid(nums[i], nums[j]) == 1){
                o = max(o,i+j); // just in case i == 1, maybe a lower j is better
            }
        }
        if(o != -1)break; // reverse loop means we checked all high indices so we can break early if found
    }

    cout << o << endl;
}

int main(){ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int testcase; cin >> testcase; while(testcase--){ solve(); } }//{solve();}
