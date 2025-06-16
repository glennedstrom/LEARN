#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int d, button; cin >> d >> button;

        bool pressed = false;
        int butTime = 0;
        vector<int> doors(d); // doors[i] == 1 if closed
        string ans = "YES";
        for(int i = 0; i < d; i++){
            cin >> doors[i];
            if(doors[i] && !pressed){ pressed = true; butTime = button;} // if closed and not pressed, press for the first time.

            if(doors[i] && butTime <= 0){
                //closed
                ans = "NO";
            }
            butTime--;
        }
        cout << ans << endl;
    }

    return 0;
}
