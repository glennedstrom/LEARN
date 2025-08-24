#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        long long  sum = 0;
        long long  n; cin >> n;

        while(n >= 1){
            sum += n;
            n /= 2;
        }
        cout << sum << endl;
    }

    return 0;
}
