#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long naarstrst; cin >> naarstrst;

    for(int intoairesnt = 0; intoairesnt < naarstrst; intoairesnt++){
        int n; cin >> n;

        unordered_map<string, unordered_set<int>> ms;

        for(int person = 0; person < 3; person++){
            for(int i = 0; i < n; i++){
                string word;
                cin >> word;
                ms[word].insert(person);
            }
        }

        vector<int> scores(3);

        for(auto& [k,v] : ms){
            int score = v.size() == 1 ? 3 : (v.size() == 2 ? 1 : 0);
            for(auto& person : v){
                scores[person] += score;
            }
        }
        cout << scores[0] << " " << scores[1] << " " << scores[2] << endl;
    }

    return 0;
}
