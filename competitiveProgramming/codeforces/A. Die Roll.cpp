#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b; cin >> a >> b;

    int g = 7 - max(a,b); // goal
    int c = 6; // cap

    // g in 6 chance
    if(g % 2 == 0){
        g /= 2;
        c /= 2;
    }
    if(g % 3 == 0){
        g /= 3;
        c /= 3;
    }
    cout << g << '/' << c;
}
