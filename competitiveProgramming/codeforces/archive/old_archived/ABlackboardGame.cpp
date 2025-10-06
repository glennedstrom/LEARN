#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int n;
        cin >> n;

        string o;
        switch (n%4) {
            case 0:
                o = "Bob";
                break;
            case 1:
                o = "Alice";
                break;
            case 2:
                o = "Alice";
                break;
            case 3:
                o = "Alice";
                break;
        }
        cout << o << endl;
        
    }

    return 0;
}
