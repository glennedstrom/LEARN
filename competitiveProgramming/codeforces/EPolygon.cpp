#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int n;
        vector<vector<int>> in(n+1, vector<int>(n+1,false));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; ++j){
                cin >> in[i][j];
            }
        }

        // bfs with valid directions only. (shoot to the wall or be on the top or left of the outermost ones in a row or col)
        // keep track of this with the left cannons and top cannons and how far they can shoot at the moment
        
        // cannons can only shoot to n in both directions (until shots fired)
        vector<int> left(n,n);
        vector<int> top(n,n);

        // WHILE: valid options exist (that intersect with the original one)
        // Can you do it greedy doing the furthest away shots every time? it always grows closer to the front

        queue<int> q;
        for(int i = 1; i < left.size(); i++){
            if(in[i][left[i]]){
                //Not sure; Could do search, could do DP, could do whatever. I want more DP practice first because I have no clue how to do 2d array dp? no easy rememberable states
            }
        }
    }

    return 0;
}
