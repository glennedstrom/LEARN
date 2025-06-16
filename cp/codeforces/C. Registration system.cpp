#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    long long n; cin >> n;
    unordered_map<string, int> m;

    for(int i = 0; i < n; i++){
        string name;
        cin >> name;

        if(m[name] == 0){
            m[name]++;
            cout << "OK" << endl;
        }
        else{
            cout << name + to_string(m[name]++) << endl;
        }

    }

    return 0;
}
