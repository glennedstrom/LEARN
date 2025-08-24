#include <bits/stdc++.h>
#include <cmath>
using namespace std;

long double quad(long double a, long double b, long double c){
    return (-b + 2*sqrtl((b*b/4-a*c)))/(2*a);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        long double n,c; cin >> n >> c;

        vector<long double> nums(n);
        long double pssum = 0; for(long long i = 0; i < n; i++){cin >> nums[i]; pssum += nums[i];}

        long double a = 4*n, b = 4*pssum, d = -c;

        long double p = quad(a,b,d);

        cout << (long long)p << endl;

    }

    return 0;
}


// (s1+2x)^2+(s2+2x)^2+(s3+2x)^2 - s1^2 - s2^2 - s3^2 = c
// (s1+2x)^2+(s2+2x)^2 - s1^2 - s2^2 = c
// s^2 + 4x*s + 4x^2 - s^2 = c
// s1^2 + 4x*s1 + 4x^2 - s1^2 = c
// s1^2 + s2^2 + 4x*s1 + 4x*s2 + n*4x^2 - s1^2 - s2^2  = c
// 4x*s + 4x^2 = c
// 4x(s+x)=c
// 4x^2 + 4s*x -c = 0
// a = 4
// b = 4s
// c = -c
//
// [-b +- sqrt(b^2-4ac)]/2a
// x = [-(4s) +- sqrt((4s)^2-4(4)(-c))]/(2*4)
// x = [-4s +- sqrt(s^2+c)]/2
// x = [-4s +- sqrt(s_i^2+c)]/2
//
//
// (s1+2x)^2+(s2+2x)^2 - s1^2 - s2^2 = c
// s1^2 + s2^2 + 4x*s1 + 4x*s2 + n*4x^2 - s1^2 - s2^2  = c
// 4x*s1 + 4x*s2 + n*4x^2 = c
// 4x*(s1 + s2) + n*4x^2 = c
// c = 4x*(SUM: s1 + s2 + ...) + n*4x^2
// 0 = 4n*x^2 + 4(SUM: s1 + s2 + ...)*x - c
// a = 4n
// b = 4*(SUM: s1 + s2 + ...)
// c = -c
// quadratic formula for +- x!
//
// 1
// 1 10000
// 4

// 48
