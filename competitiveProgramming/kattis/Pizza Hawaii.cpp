#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int pizzas; cin >> pizzas;
        string pizza_name; cin >> pizza_name;

        int fn; cin >> fn;
        vector<string> fnvec(fn);
        for(int i = 0; i < fn; i++){ cin >> fnvec[i]; }


        int rn; cin >> rn;
        vector<string> rnvec(rn);
        for(int i = 0; i < rn; i++){ cin >> rnvec[i]; }

    }

    return 0;
}


