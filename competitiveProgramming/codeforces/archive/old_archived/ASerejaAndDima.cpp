#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long numlength; cin >> numlength;

    deque<int> dq;

    for(int testcase = 0; testcase < numlength; testcase++){
        int temp; cin >> temp;
        dq.push_back(temp);
    }

    int score[2] = {0,0};

    while(!dq.empty()){
        for(int turn = 0; turn <= 1; turn++){
            if(dq.empty()){ break; }
            if(dq.front() > dq.back()){
                score[turn] += dq.front();
                dq.pop_front();
            }
            else{
                score[turn] += dq.back();
                dq.pop_back();
            }
        }
    }

    cout << score[0] << " " << score[1] << endl;

    return 0;
}
