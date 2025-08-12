#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test_cases; cin >> test_cases;

    int out = 0;
    for(int i = 0; i < test_cases; i++){
        char s,b;
        cin >> s >> s >> b;
        out += (s == '+' ? 1 : -1);
    }
    cout << out << endl;

    return 0;
}
