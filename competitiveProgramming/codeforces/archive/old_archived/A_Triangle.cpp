#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void precalc(){
    // optional
}

void solve() {
    vector<int> edge(4);
    for(auto& i : edge) cin >> i;
    sort(edge.begin(),edge.end());

    bool degen = false;
    for(int i = 0; i <= 1; i++){
        if(edge[i] + edge[i+1] > edge[i+2]){
            cout << "TRIANGLE" << endl;
            return;
        }
        if(edge[i] + edge[i+1] == edge[i+2]){
            degen = true;
        }
    }

    cout << (degen ? "SEGMENT" : "IMPOSSIBLE") << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
