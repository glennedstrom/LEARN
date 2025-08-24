#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        long long n; cin >> n;
        while(n % 2 == 0 && n != 1){
            n /= 2;
        }
        cout << (n == 1 ? "NO" : "YES") << endl;
    }

    return 0;
}
