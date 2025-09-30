#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int n; cin >> n;
        
        for(int i = 0; i < n; i++){
            cout << (i+1)%n + 1 << ' ';
        }
        cout << endl;
    }

    return 0;
}
