#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p;
    cin >> p;

    vector<int> piles(p);
    cin >> piles[0];
    int temp;
    for(int i = 1; i < p; i++){ cin >> temp; piles[i] = piles[i-1] + temp; }

    int yum;
    cin >> yum;

    vector<int> yummy(yum);
    for(int i = 0; i < yum; i++){cin >> yummy[i];}

    /*for(int i = 0; i < p; i++){*/
    /*    cout << piles[i] << " ";*/
    /*}*/
    /*cout << endl;*/
    /*for(int i = 0; i < yum; i++){*/
    /*    cout << yummy[i] << " ";*/
    /*}*/
    /*cout << endl;*/
    /**/

    /*cout << "Total piles: " << p << endl;*/
    for(int i = 0; i < yum; i++){
        int outi = lower_bound(piles.begin(),piles.end(),yummy[i]) - piles.begin();

        //cout << yummy[i] << " " << (outi == piles.end()) << ": ";
        //cout << 
        //cout << *outi << endl;
        cout << 1 + outi << endl;
    }
}
