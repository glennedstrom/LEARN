#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
        double p1,p2;

        double a,b,c,d; cin >> a >> b >> c >> d;
        p1 = a/b; p2 = c/d;

        double epsilon = 1e-12;
        double val = 1-p1;
        double cur = p1;
        double prev = 1;

        while(abs(cur - prev) >= epsilon){ // shot and previous shot differ by less than epsilon
            prev = cur;
            val *= 1-p2; // they miss
            cur += val*p1;
            val *= 1-p1; // i lose
        }

        cout << fixed << setprecision(12) << cur << endl;

}

// .5 .5
// if lose: .5 .5
//
