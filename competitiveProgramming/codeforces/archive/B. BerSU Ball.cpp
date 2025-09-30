#include <bits/stdc++.h>
using namespace std;

int main()
{
    int b, g;

    cin >> b;
    vector<int> boys(b); for(int i = 0; i < b; i++){ cin >> boys[i]; }

    cin >> g;
    vector<int> girls(g); for(int i = 0; i < g; i++){ cin >> girls[i]; }

    sort(boys.begin(),boys.end());
    sort(girls.begin(),girls.end());

    int c = 0;
    g = 0;
    for(b = 0; b < boys.size(); b++){
        while(g < girls.size() && boys[b] > girls[g] + 1){ g++; } // close the gap
        if(g >= girls.size()){
            break;
        }
        //valid pair
        //cout << girls[g] <<  " " << boys[b] << endl;
        if(abs(girls[g] - boys[b]) <= 1){ // count valid pairs
            c++;g++;
        }
    }
    cout << c << endl;
}
