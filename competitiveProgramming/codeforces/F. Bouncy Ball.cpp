#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

// 1. find next collision
// 2. check if our target is on this path
// mark node+direction as visited (either the 1st or reflection, doesn't matter, both are only possible with the other there)

vector<vector<vector<int>>> visited;
// DR, DL, UR, UL

int dist(int start, int limit, int dir){
    int o;
    if(dir == 1){
        o = limit - start;
    }
    else{
        o = start-1;

    }
    return o;
}

void solve() {
    string d;
    int n,m,i,j,i2,j2; cin >> n >> m >> i >> j >> i2 >> j2 >> d; 
    visited = vector<vector<vector<int>>>(n+1, vector<vector<int>>(m+1,vector<int>(4,0)));
    int down = d[0] == 'D';
    int right = d[1] == 'R';
    int bounces = 0;

    while(!visited[i][j][down + right*2]++){
        // print state
        // if(true){
        //     //cout << visited[i][j][down + right*2] << endl;
        //     for(int a = 0; a < n; a++){
        //         for(int b = 0; b < m; b++){
        //             if(a+1 == i && b+1 == j){
        //                 cout << "O";
        //             }
        //             else {
        //                 cout << ".";
        //             }
        //         }
        //         cout << endl;
        //     }
        //     cout << endl << endl;
        // }
        // cout << i << " " << j << endl;
        int nextFloor = dist(i,n,down);
        int nextWall = dist(j,m,right);
        int move = min(nextFloor,nextWall);

        //COLLISION DETECTION HERE:
        // calculate if it will hit. It will be final - initial then figure out which directions it should be (probably *= direction*2-1) then if you hit, it will be like 5,5 
        // or something even
        int a1 = (i2-i)*(2*down-1);
        int a2 = (j2-j)*(2*right-1);
        if(a1 == a2 && a1 >= 0){
            // HIT
            cout << bounces << endl;
            return;
        }

        // move
        //cout << move << endl;
        i = i + move * (2*down-1);
        j = j + move * (2*right-1);

        // if(n == 2) {
        //     cout << "DIRECTION : " << down << right << endl;
        //     cout << visited[i][j][down + right*2] << endl;
        // }
        // bounce if on a wall if your next step is off the map
        if(i + (down * 2 - 1) < 1 || i + (down * 2 -1) > n){ down = !down; }
        if(j + (right * 2 - 1) < 1 || j + (right * 2 - 1) > m){ right = !right; }
        bounces++;
    }
    cout << -1 << endl;
}

int main() { int testcase; cin >> testcase; while(testcase--){ solve(); } }// {solve();}
