#include <bits/stdc++.h>
//#include <bits/extc++.h>
using namespace std;
/*
 *
 *
 * CODE WORKS: BUT NOT FOR LARGE E VALUES FOR SOME REASON; MAYBE IT DOESN'T WORK THEN? can't find why it doesn't work just yet.
 *
 *
 *
 *
 *
 *
 *
 *
 * */

// How do you remember which walls are visited? // recursively set and unset a visited boolean array? note: you also might want this in your states
//
// memo[E][x][l][r] with expanding l&r but to go from l to r you have to calculate all the way from l to r
//
//

// keep track of the cost of used walls too so you know how to get from l to r?

// memo[E][x];
vector<unordered_map<int,int>> memo;
vector<bool> visited; // set bools as visited if visiting for the first time then unset after recursive call

bool first = false;
int rec(vector<pair<float,int>>& walls, int E, int X, int l, int r) {
    cout << (int)walls[l].first << " < X=" << X  << " < " << (int)walls[l].first + 1 << ", " << (int)walls[r].first << " < X=" << X  << " < " << (int)walls[r].first + 1 << endl;
    if(!first){
        first = true;
    }
    else{
        assert((X == (int)walls[l].first || X == (int)walls[l].first) || (X == (int)walls[l].first+1 || X == (int)walls[l].first+1));
    }
    //energy base case
    if(E <= 0){return 0;}
    //cout << E << ", " << X << endl;
    if(memo[E].find(X) != memo[E].end()){ return memo[E][X]; } // MEMO base case MAKE SURE TO SET MEMO EVERYWHERE IN CODE
    // negative l base case (go right)
    if(l < 0){
        assert(r == 0);
        int totalcost = ((int)walls[r].first - X) + walls[r].second; // cost to go to right wall
        int XFinalPos = ((int)walls[r].first - X) + X + 1;
        if(E - totalcost >= 0){ // enough to visit
            if(!visited[r]){
                visited[r] = true;
                memo[E][X] = rec(walls, E-totalcost, XFinalPos, l+1, r+1) + 1; // VISITING A NEW ONE; +1
                visited[r] = false;
                return memo[E][X];
            }
            else{
                memo[E][X] = rec(walls, E-totalcost, XFinalPos, l+1, r+1);
                return memo[E][X];
            }
        }
        else{
            memo[E][X] = 0; // not enough to go anywhere
            return memo[E][X];
        }
        //go right
    }
    // too large r base case (go left)
    if(r >= (int)walls.size()){
        assert(l == (int)walls.size()-1);
        //go left
        int totalcost = (X - (int)walls[l].first) + walls[l].second; // cost to go to left wall
        int XFinalPos = (X - (int)walls[l].first) + X - 1;
        if(E - totalcost >= 0){ // enough to visit
            if(!visited[l]){
                visited[l] = true;
                memo[E][X] = rec(walls, E-totalcost, XFinalPos, l-1, r-1) + 1; // VISITING A NEW ONE; +1
                visited[l] = false;
                return memo[E][X];
            }
            else{
                memo[E][X] = rec(walls, E-totalcost, XFinalPos, l-1, r-1);
                return memo[E][X];
            }
        }
        else{
            memo[E][X] = 0; // not enough to go anywhere
            return memo[E][X];
        }
    }

    // HIDING FOR DEBUGGING TOP
    // you are between l and r
    //auto [leftX, leftCost] = walls[l];
    //auto [rightX, rightCost] = walls[r];

    int leftAns;
    int rightAns;

    // GO both directions recursively, add to memo
    // GO RIGHT GO RIGHT GO RIGHT GO RIGHT GO RIGHT GO RIGHT GO RIGHT GO RIGHT GO RIGHT GO RIGHT GO RIGHT           
    int totalcost = ((int)walls[r].first - X) + walls[r].second; // cost to go to right wall
    int XFinalPos = ((int)walls[r].first - X) + X + 1;
    if(E - totalcost >= 0){ // enough to visit
        if(!visited[r]){
            visited[r] = true;
            rightAns = rec(walls, E-totalcost, XFinalPos, l+1, r+1) + 1; // VISITING A NEW ONE; +1
            visited[r] = false;
        }
        else{
            rightAns = rec(walls, E-totalcost, XFinalPos, l+1, r+1);
        }
    }
    else{
        rightAns = 0; // not enough to go anywhere
    }

    //go right
    //
    //
    //
    //
    //
    //go left
    // GO LEFT GO LEFT GO LEFT GO LEFT GO LEFT GO LEFT GO LEFT GO LEFT GO LEFT GO LEFT GO LEFT           
    totalcost = (X - (int)walls[l].first) + walls[l].second; // cost to go to left wall
    XFinalPos = (X - (int)walls[l].first) + X- 1;
    if(E - totalcost >= 0){ // enough to visit
        if(!visited[l]){
            visited[l] = true;
            leftAns = rec(walls, E-totalcost, XFinalPos, l-1, r-1) + 1; // VISITING A NEW ONE; +1
            visited[l] = false;
        }
        else{
            leftAns = rec(walls, E-totalcost, XFinalPos, l-1, r-1);
        }
    }
    else{
        leftAns = 0; // not enough to go anywhere
    }
    //
    //
    //
    //
    //
    //
    memo[E][X] = max(leftAns, rightAns);

    return memo[E][X];
}






int runThroughWalls(vector<float>wallXValues, vector<int> wallCosts, int E) {

    vector<pair<float,int>> walls(wallXValues.size());
    memo = vector<unordered_map<int,int>>(E+1); // init indices up to E
    visited = vector<bool>(walls.size());

    int i = 0;
    for(auto& [x, cost] : walls){
        x = wallXValues[i];
        cost = wallCosts[i];
        i++;
    }
    sort(walls.begin(), walls.end());
    //walls are sorted now


    //find first value below 0 for l
    int l = 0;
    for(int i = 0; i < (int)walls.size(); i++){
        if(walls[i].first < 0){
            l = i;
        }
    }
    int r;
    if(walls[l].first < 0){ // set r 
        r = l + 1;
    }
    else{ // all positive nums case (always go right: easy)
        r = 0;
        l = -1;
    }
    //cout << "L,R = ";
    //cout << l << ", " << r << endl;
    return rec(walls, E, 0, l, r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    int E; cin >> E; //int E = 38;
    vector<float> wallXValues(n); // {-5.5,2.5,-3.5,29.5,38.5,2.5};
    for(int i = 0; i < n; i++){cin >> wallXValues[i];}
    vector<int> wallCosts(n); //  = {2, 5, 3, 1, 8, 4};
    for(int i = 0; i < n; i++){cin >> wallCosts[i];}

    cout << "Answer: " << runThroughWalls(wallXValues, wallCosts, E) << endl;
    return 0;
}
