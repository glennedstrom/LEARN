#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

/*
NAME was walking through the park then he heard on the radio that there was a MONSTREE on the loose
in the same park he was in! The sidewalks in the park is a tree with n vertices and n-1 edges.

NAME starts at node 1 and he needs your help to get home safely. His house is located at node n.

On the radio, they reported that the MONSTREE was last seen in node m in the park. The MONSTREE
moves at the same speed as you (one edge per move), but the MONSTREE can also stand still and choose not to move on a turn.

The MONSTREE must be on the same node as you to catch you; this means you can dodge the MONSTREE
if you are on vertex 1 and it is on vertex 2, then it moves to vertex 1 and you move to vertex 2.

Help NAME find out what the probability that she will survive is.

inputs:
the first line of input data contains a single integers t (1 <= t <= 10^4) -- the number of test cases
the second line of input data contains two integers n (1 <= n <= 10^5), and m (2 <= m <= n)
the next n-1 lines contain two integers u, v (1 <= u,v <= n), a sidewalk from u to v

outputs:
For each test case, print the probability that you will survive if you sprint straight home.
*/

vector<vector<int>> g;

void solve() {
    int n,m; cin >> n >> m;
    g.assign(n,vector<int>());

    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // MONSTREE is at m
    

}


/*
 * 5 nodes, monster at 5
 *
1 2
2 3
2 4
4 5

5
4,5
4,2,5,5,4




*/

int main(){ int testcase; cin >> testcase; while(testcase--){ solve(); } }//{solve();}
//
//another problem could be that we have a MONSTREE that runs between the two furthest points on the tree and we want to see if we can safely get home to our target node. To get home safely, you would need to run along the main path, then hide in the edge as you wait for the MONSTREE to run past. after it passes, you can get back out and keep running until you get home.
//
// MONSTREE IN THIS CASE CAN RUN TWO TILES AT A TIME
// Goal: either see if you can get home (easy problem) or see what's the shortest path(medium)? or you can have an energy E and a max energy capacity C where you can regain 1 energy for every tile you stand still in
// instead of move. You'll have to see if you can use your energy to make it to the next safe spot before regaining energy to move on and waiting for the right time to move too.
//
//
