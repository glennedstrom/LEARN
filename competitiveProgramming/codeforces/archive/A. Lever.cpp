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
        vector<int> a(n);
        vector<int> b(n);

        int maxdiff = 0;

        for(int i = 0; i < n; i++){cin >> a[i];}
        for(int i = 0; i < n; i++){cin >> b[i]; maxdiff = max(maxdiff,abs(b[i]-a[i]));}

        int count = maxdiff;

        bool changed = true;
        do {
            
        
        }while (changed)


        count += count == 0;
        cout << count << endl;
    }

    return 0;
}
