#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

bool shapeDraw(double a){ // unit side lengths
    double direction=0;
    double x=0, y=0;
    double eps = 1e-6;
    bool xneg = false;

    while(true){
        x += cos(direction);
        y += sin(direction);
        direction += M_PI-a;
        //cout << "(" << x << ", " << y <<  ") : " << direction << endl;

        //check if it collides
        if(xneg && abs(x) < eps && abs(y) < eps){
            return true;
        }
        if(x < 0){ xneg = true; }

        if(xneg && x > 0){
            break;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int angle;
        cin >> angle;
        if(angle == 60 || angle == 90 || shapeDraw(M_PI*angle/180.0)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}

// example shapes starting from sides=3 triangle
// 60 90 108 120 [decimal] 135 [decimal] 144
// 3  4  5   6   7         8   9         10
