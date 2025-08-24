#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;



vector<long long> fact = {1,1};
long long factorial(long long n){
    while(fact.size() <= n){
        fact.push_back(fact.size()*fact[fact.size()-1]);
    }
    return fact[n];
}

long double choose(long long n, long long k){
    return factorial(n) / factorial(n - k) / ((long double)factorial(k)); // factorial(k) could have integer division.
}

void solve() {
    long double p,pheads,q,qheads; cin >>p>>pheads>>q>>qheads;

    long double heads1 = pheads/p;
    long double heads2 = qheads/q;
    cout << qheads << " / " << q << " : " << heads2 << endl;

    //cout << heads1 << " " << heads2 << endl;

    long double prob1 =  choose(p,pheads) / pow(2,p);
    // prob1 = (heads1 > 0.5 ? 1-prob1 : prob1);
    long double prob2 =  choose(q,qheads) / pow(2,q); // NOTE: I left it off with a working choose function for small factorials; no plan at all on the logic yet.
    // prob2 = (heads2 > 0.5 ? 1-prob2 : prob2);
    cout << "p1,h1: " << prob1 << " " << heads1 << endl;
    cout << "p2,h2: " << prob2 << " " << heads2 << endl;
    //for(int i = 0; i <= p; i++){
    //    cout << choose(p,i) << endl;
    //}
    // denominator = pow(2,p);

    betal
    cout << endl;
    cout << endl;

    // output: probability p < q
}

//
//
// 2 0 2 1
// 
// 0/2 = 0% coint chance of heads; 1/2 = 0.5 coin chance of heads
// 1/4 * p^2 * (1-p)^0
// 2/4 * p^1 * (1-p)^1
// 1/4 * p^0 * (1-p)^2
//
// for 0/2 on coin p:
// 1/4*0*1 = 0
// ALL:
// 1/4 * 0^2 * (1-0)^0
// 2/4 * 0^1 * (1-0)^1
// 1/4 * 0^0 * (1-0)^2
//
// for 1/2 on coin q:
// 2/4 * .5 * .5 =  0.5^3 = .125
// 1/4 * 0.5^2 * (1-0.5)^0 == .25 * .25 * 1 == .125
// 2/4 * 0.5^1 * (1-0.5)^1 == .5 *  .5 * .5 == .125
// 1/4 * 0.5^0 * (1-0.5)^2 == .25 * 1 * .25 == .125
//
//
// MAYBE do the math on each of them and count all cases where the output satisfies p < q?
//
// the p that I subbed in is what I'm trying to calculate!
//
//
//
//
//
//
//
//
int main(){ int testcase; cin >> testcase; while(testcase--){ solve(); } }//{solve();}
