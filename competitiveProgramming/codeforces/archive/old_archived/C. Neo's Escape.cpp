#include <bits/stdc++.h>
using namespace std;


int main()
{

    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int n; cin >> n;

        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq; // <weight, index>

        vector<int> v(n);
        unordered_map<int,bool> visited(n); // index to t/f visited
        for(int i = 0; i < n; i++){
            cin >> v[i];
            pq.push(make_pair(v[i],i));
        }
        int botcount = 0;


        while(!pq.empty()){
            auto [weight, index] = pq.top();
            pq.pop();
            
            if(visited[index]){ continue; } //visited weight already
            if((index - 1 >= 0 && visited[index-1]) || (index + 1 < n && visited[index+1])){// neighbors visited already, move and don't count
                visited[index] = true;
                continue;
            }

            // add to counter if neighbors are not visited
            visited[index] = true;
            botcount++;
        }
        cout << botcount << endl;
    }

    return 0;
}
