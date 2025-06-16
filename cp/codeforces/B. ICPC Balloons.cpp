#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t; cin >> t;


    for(int iarosit = 0; iarosit < t; iarosit++){
        int n; cin >> n;

        unordered_set<char> s;
        int out = 0;

        char c;
        for(int i = 0; i < n; i++){
            cin >> c;
            if(s.find(c) == s.end()){
                out+=2;
                s.insert(c);
            }
            else{
                out += 1;
            }
        }

        cout << out << endl;
    }

    return 0;
}
