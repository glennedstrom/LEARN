#include <bits/stdc++.h>
using namespace std;

/*int rec(int step, unordered_map<int,int>& points, unordered_map<int,bool>& deleted, vector<int>& memo){*/
/**/
/*}*/

int main()
{
    int n;
    cin >> n;
    string s;

    vector<int> seq(n+1); 
    //unordered_map<int,bool> deleted; // 
    unordered_map<int,int> points(n,0); // vector instead of map so that you can loop though everything easier?
    unordered_set<int> seqset(n);
    int mv = 0;
    for(int i = 1; i < n+1; i++){
        cin >> seq[i];
        seqset.insert(seq[i]);
        points[seq[i]] += seq[i]; // store points at the number index
        mv = max(mv,seq[i]);
    }
    int rows, cols;
    vector<vector<char>> grid(rows, vector<int>(cols, '.'))


    //vector<int> keys; for(auto& [k,v] : points){ keys.push_back(k); }

    //either do one jump or two jumps each time through the keys IF SORTED
    //sort(keys.begin(), keys.end());

    //vector<int> memo(mv+1);

    //int out = max(rec(0, points, deleted, memo), rec(1, points, deleted, memo));
    // RECURRANCE RELATION
    // dp[i] = max(dp[i-2]+score[i], dp[i-3]+score[i], dp[i])


    vector<int> tab(mv+1, -1);
    tab[0] = 0; // start at tab[1] = 1st element or tab[2] = max(1st,2nd) element
    tab[1] = *seqset.find(1);
    tab[2] = *seqset.find(2); // tab[3] = seq[1] + seq[2] // NOTE: MAKE SURE THE INDICES ARE CORRECT ON EVERYTHING // MIGHT BE SWAPPING BETWEEN 1 AND 0 INDEXED
    for(int i = 3; i <= mv; i++){ // NOTE: must loop through the (possibly unique) vals sorted; not all vals
        auto ii = seqset.find(i);
        if(ii == seqset.end()){continue;}
        if(tab[i-2] != -1){
            tab[i] = max(tab[i], tab[i-2]+*ii);
        }
        if(tab[i-3] != -1){
            tab[i] = max(tab[i], tab[i-3]+*ii);
        }
        //tab[i] = max(tab[i], max(tab[i-2]+seq[i], tab[i-3]+seq[i]));
    }
    cout << tab[mv] << endl;

    // only move forwards 1 or 2 if it exists in the original points array. if it doesn't exist then no need to go to it.
    // do max of each value as we build out

    //loop through keys and if the next two values are +2 or +3 then you move forwards




}
