#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int n; cin >> n;

        bool imp = false;
        int moves = 0;
        while(n > 1 && !imp){
            if(n % 3 != 0){ imp = true; break;} // impossible cases
            if(n % 6 == 0){n /= 6;}
            else{n *= 2;}
            moves++;
        }

        cout << (imp ? -1 : moves) << endl;
    }

    return 0;
}
