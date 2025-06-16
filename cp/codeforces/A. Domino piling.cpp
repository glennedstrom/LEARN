#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y; cin >> x >> y;
    int out = 0;
    cout << x*y/2 << endl;
    return 0;

    //if(x % 2 == 0 || y % 2 == 0){
    //    // easy case: lay m/2 dominos down over n rows
    //    out = y*x/2;
    //}
    //else {
    //    // both are odd
    //    out = (y/2)*x+(x/2);
    //}

    //cout << out << endl;

    //return 0;
}


/*

y = 5
x = 3

____
____|
____|


(y/2)*x+(x/2)

3 across
5 up

__
|||
|||
|||
|||

 * */
