#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int n; cin >> n;
        string s; cin >> s;
        deque<char> dq(s.begin(),s.end());

        while(dq.front() - '0' + dq.back() - '0' == 1 && dq.size() >= 2){
            dq.pop_back();
            dq.pop_front();
        }

        cout << dq.size() << endl;
    }

    return 0;
}
