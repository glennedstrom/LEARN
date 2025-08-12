#include <bits/stdc++.h>
#include <cmath>
using namespace std;

pair<long long,long long> quad(long long a, long long b, long long c){
    pair<long long,long long> out;
    /*out.first = (-b + sqrt(b*b-4*a*c))/(2*a);*/
    /*out.second = (-b - sqrt(b*b-4*a*c))/(2*a);*/
    out.first = ((long double)(-b)/(2*a) + b*sqrt((long double)1/(4*a*a)-(long double)c/(a*b*b)));
    out.second = ((long double)(-b)/(2*a) - b*sqrt((long double)1/(4*a*a)-(long double)c/(a*b*b)));
    //out.second = ((long double)(-b)/(2*a) - sqrt((long double)b*b/(4*a*a)-(long double)c/a));

    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        long long n,c; cin >> n >> c;

        long long temp;
        long long pssum = 0; for(long long i = 0; i < n; i++){cin >> temp; pssum += temp;}

        long long a = 4*n, b = 4*pssum, d = -c;

        //cout << a << " " << b << " " << d << endl;

        auto[p,m] = quad(a,b,d);
        //cout << p << ", " << m << endl;

        cout << max(p,m) << endl;

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
