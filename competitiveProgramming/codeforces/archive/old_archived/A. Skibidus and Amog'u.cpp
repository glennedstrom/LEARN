#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        string s;
        cin >> s;
        s.pop_back();
        s.pop_back();
        s.push_back('i');
        cout << s << endl;
    }

    return 0;
}
