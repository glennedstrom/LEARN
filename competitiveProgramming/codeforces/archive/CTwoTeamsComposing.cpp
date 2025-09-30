#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
// EPS for doubles; do 1e-6 for floats
#define EPS 1e-9
#define INF 1e9

void solve() {
    int n; cin >> n;
    //set<int> group1;
    vector<int> group1;
    unordered_map<int,int> total_counts;
    
    vector<int> nums(n); for(auto& i : nums){
        cin >> i;

        group1.push_back(i);
        total_counts[i]++;
    }
    sort(group1.begin(),group1.end());
    auto g1end = unique(group1.begin(),group1.end()); // REMOVE DUPLICATES O(n+k)
    vector<int> rejects = vector(g1end, group1.end()); // Other kids to pick from

    group1.erase(g1end,group1.end());

    //cout << group1.size() << endl;
    int sum1 = 0; for(auto& num : group1){ sum1 += num; } // sum of group 1
    
    unordered_map<int,int> group1_counts; for(auto& i : group1){ total_counts[i]++; }

    // still don't know how to do much...

    // multimap<int, int> total_count2student;
    // for(auto& [s,c] : total_counts){ // if we have the total count and the counts of them in one group, we can do count[total 5s] - count[g1 5s] == how many we can put in g2; (track each var&cnt)
    //     total_count2student.insert({c,s}); // if there are 5 student A's, then map 5 to A. Repeat for all
    // }
    // TODO: total threes - threes in group 1: how many we can use in group 2

    // INFO: Now we can grab some student of count X easily

    // loop through in order greatest to least.
    // for(auto& [c,s] : total_count2student){
    //     if(c == group1.size()){
    //         if(c*s == sum1){
    //             //cout << c << endl;
    //             return;
    //         }
    //     }
    // }
    // what if we want a smaller group?
    // I need to figure out how to remove elements??

}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
