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
        int count[3] = {0,0,0};
        int temp;
        for(int i = 0; i < n; i++){cin >> temp;count[temp]++;}
        bool o = false;

        if(count[2] % 2 == 0){
            o = count[1] % 2 == 0;
        }
        else{
            count[1]-=2;
            if(count[1] >= 0 && count[1] % 2 == 0){o = true;}
        }

        cout << (o ? "YES" : "NO") << endl;
    }

    return 0;
}
