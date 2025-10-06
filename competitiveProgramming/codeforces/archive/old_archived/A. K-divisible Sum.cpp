#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int n, k;
        cin >> n >> k;

        // Start with: n (1s in all)
        // Then: k - (n % k) gets the offset to the next number // this is wrong but I can't fix it right now
        int prev = n + (k - (n % k));

        // edge case when it divides in evenly
        if(n % k == 0){ prev-=k;}
        // Then: prev // n to know how many array buckets it filled
        int out = prev / n + (prev % n == 0 ? 0 : 1);
        // Plus 1 if a remainder exists
        cout << out << endl;
    }

    return 0;
}
