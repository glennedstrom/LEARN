#include <bits/stdc++.h>
using namespace std;

int main()
{
    int rides,mrides,price1,pricem; cin >> rides >> mrides >> price1 >> pricem;
    float eps = 1e-6;
    float diff = (float)pricem/mrides - (float)price1;

    if(abs(diff) < eps){
        //equal, just do rides
        // cout << "A: ";
        cout << price1 * rides << endl;
        return 0;
    }
    if(diff < 0){
        //better to do m until you can't then either 1 more m or fill the rest with singles (depending on price)
        int current = (rides/mrides)*mrides;
        //compute remainder and compare to know which to do.
        int remainder = rides - current;
        int singlesPrice = remainder * price1;

        if(singlesPrice < pricem){
            //buy the rest with singles
            // cout << "B: ";
            cout << (rides/mrides)*pricem + singlesPrice << endl;
        }
        else{
            // buy one more in bulk
            // cout << "C: ";
            cout << (rides/mrides+1)*pricem << endl;
        }

    }
    else{
        //just do singles
        // cout << "D: ";
        cout << price1 * rides << endl;
    }
}
