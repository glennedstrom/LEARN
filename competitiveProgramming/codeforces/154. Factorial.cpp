#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

/*
 *
 * Does it require prime factors that multiply up to ten to have a trailing zero?
 *
 * 10 = 2*5
 * 2,4,8,16,32,64,128,256
 *
 * Yes I think so
*/


vector<int> fact = {1,1};
int factorial(int n){
    for(int i = fact.size(); i <= n; i++)
        fact.push_back(fact[i-1]*i);
    return fact[n];
}

// make twos by computing powers of twos
// for one two, sum every i*2^1 (2)
// then for two, sum every i*2^2 (4)
// for three, sum every i*2^3    (8)
//
//                             index mod 2 == 0 means two 2s. index mod 3 means 3 2s?
//                             ALWAYS ENOUGH 2s. 5S ALWAYS INCREASE 0S
//
// for one five, sum every i*5^1 (5)
// then for two, sum every i*5^2 (25)
// for three, sum every i*5^3    (125)

long long test(long long n){
    long long o = 0;
    long long i = 5;
    while(n / i > 0){
        o += n / i;
        i *= 5;
    }
    return o;
}

void solve() {
    int twos = 0; int fives = 0;

    // compute how many twos and fives in each number instead of primes?

    int zero_count; cin >> zero_count;
    twos = zero_count;
    fives = zero_count;

    // I need twos and fives to be at least zero_count in our factorial.
    //
    // let's view the factorial numbers:
    // divide index by five to compress the array more
    //cout << factorial(5) << endl;
    long long fact = 400'000'015; // this factorial has 1e8 leading zeros

    //zeros: 249999998
        //   100000000
//    zeros: 24999999
//    zeros: 99999997
    // fastest answer: binary search with checking with math.
    //cout << "zeros: " << test(fact) << endl;

    long long h = fact, l = 1;
    while(h - l > 0){
        long long mid = (h-l)/2+l;

        long long out = test(mid);
        if(out == zero_count){
            h = mid;
        }
        else if(out < zero_count){
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }
    if(test(h) == zero_count){
        cout << h << endl;
    }
    else{
        cout << "No solution" << endl;
    }
    return;
    



    int target = 1e8; // do it for 1-20 factorial
    vector<int> counts(target/5+1);
    for(int i = 1; pow(5,i) <= target; i++){         // 5,25,125,... powers of 5^i
        for(int j = 1; pow(5,i)*j <= target; j++){   // 5,10,15 ; 25,50,75 ; incrementing by += powers of i
            //cout << pow(5,i) << "*" << j << "/5 : " << pow(5,i)*j << endl;
            counts[(pow(5,i)*j)/5]++;

        }
    }
    cout << counts[counts.size()-1] << endl;

    vector<int> countSum(target/5+1);
    for(int i = 1; i < countSum.size(); ++i){ countSum[i] = countSum[i-1] + counts[i]; }


    // leading zeros
    cout << countSum[countSum.size()-1] << endl;

    // PRECOMPUTE A TON FIRST THEN BINARY SEARCH ON THE ARRAY TO FIND THE ANSWERS!!!

}

int main(){solve();}
