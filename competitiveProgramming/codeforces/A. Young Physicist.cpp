#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vectors; cin >> vectors;

    int xt=0,yt=0,zt=0;
    for(int vi = 0; vi < vectors; vi++){
        int x,y,z;
        cin >> x >> y >> z;
        xt += x;
        yt += y;
        zt += z;
    }

    cout << (xt == 0 && yt == 0 && zt == 0 ? "YES" : "NO") << endl;

    return 0;
}
