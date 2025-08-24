#include <bits/stdc++.h>
using namespace std;

// just a pair hash function
template <typename T>
inline void hash_combine(std::size_t& seed, const T& val) {
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

struct pair_hash {
    template <typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        std::size_t seed = 0;
        hash_combine(seed, p.first);
        hash_combine(seed, p.second);
        return seed;
    }
};

// get primes
// prime factors for x
// grouping the prime factors into 2 groups
// repeat for all possible groups
// if perfect square; add one
// if not perfect square; add two

int main()
{
    long long n, x; cin >> n >> x; // long long because of the i*i

    // get n+1 primes
    vector<bool> prime(n+1,true); // prime until proven not prime
    prime[0] = prime[1] = false;
    for(long long i = 2; i < n+1; i++){
        if(prime[i]){
            for(long long j = i*i; j < n+1; j+=i){
                prime[j] = false;
            }
        }
    }

    //get prime factors for x
    vector<long long> prime_factors;
    long long x2 = x;
    for(long long i = 2; i*i <= x; i++) if (prime[i]){
        while(x2 % i == 0){
            x2 /= i;
            prime_factors.push_back(i);
        }
    }
    if(x2 != 1){
        prime_factors.push_back(x2); 
    }

    // generate all factor pairs algorithm: BFS through composite numbers starting from the source X until you reach 1
    unordered_set<long long> unique_prime_factors(prime_factors.begin(), prime_factors.end());
    queue<long long> q;
    q.push(x); // starting number to divide up into factors
    unordered_set<pair<long long,long long>, pair_hash> factors;
    factors.insert({1, x});

    while(!q.empty()){
        long long cur = q.front();
        q.pop();

        for(auto& fact : unique_prime_factors){
            long long minfact = min(cur / fact, x / (cur / fact));
            if(cur % fact == 0 && cur / fact != 1 && factors.find({minfact, x / minfact}) == factors.end()){ // making sure you don't re-visit visited cells is KEY for TLE
                q.push(cur / fact);
                factors.insert({minfact, x / minfact});
            }
        }
    }

    int count = 0;
    for(auto& fact : factors){
        if(fact.first <= n && fact.second <= n)
            count += 1 + (fact.first != fact.second);
    }
    cout << count << endl;
}
