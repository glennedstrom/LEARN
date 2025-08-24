#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int ai,bi; cin >> ai >> bi;
    long double a = ai, b = bi;

    // a^b - b^a
    // (a^{b/2})^2 - (b^{a/2})^2
    long double c = powl(a,bi/2) * (bi % 2 == 1 ? sqrtl(ai) : 1);
    long double d = powl(b,ai/2) * (ai % 2 == 1 ? sqrtl(bi) : 1);

    //c = powl(a,b/2);
    //d = powl(b,a/2);

    cout << (long long)round((c+d) * (c-d)) << endl;

}

int main(){solve();}



// a^b - b^a = X
// from X can you get back our numbers?
// X + b^a = a^b


