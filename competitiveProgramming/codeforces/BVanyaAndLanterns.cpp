#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long num_lantern, len_street;
    cin >> num_lantern >> len_street;

    vector<long long> lantern(num_lantern);
    for(long long i = 0; i < num_lantern; i++){
        cin >> lantern[i];
    }

    sort(lantern.begin(), lantern.end()); // sort the lanterns.

    long long dist = 2*max(lantern[0], len_street-lantern[lantern.size()-1]);

    for(long long i = 0; i < lantern.size()-1; i++){
        dist = max(dist, lantern[i+1]-lantern[i]);
    }

    double out = (double)dist/2.0f;

    cout << fixed << setprecision(10);
    cout << out << endl;

}
