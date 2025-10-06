#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){
    // optional
}


void solve() {
    int n; cin >> n;

    vector<int> statements(n); for(auto& i : statements) cin >> i;
    sort(statements.begin(),statements.end());

    for(int target_liars = 0; target_liars <= n; target_liars++){
        // brute force
        int liar_counta = n-(upper_bound(statements.begin(),statements.end(),target_liars)-statements.begin());
        int liar_countb = 0;
        liar_countb = 0;
        for(int i = 0; i < n; i++){
            if(target_liars < statements[i]){
                liar_countb++;
            }
        }
        if(liar_countb == target_liars){
            cout << liar_countb << endl;
            return;
        }
    }
    cout << -1 << endl;;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
