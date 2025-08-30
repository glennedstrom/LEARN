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
    string a,b; cin >> a >> b;
    int n = a.size(); // equal len

    //rightmost 0 and leftmost 1
    int zero_max = 0;
    int one_min = n-1;
    // loop through flagging issues: a[i] != b[i]; then if you can fix the issue, update the zero_max (ONLY IF THERE WAS AN ISSUE)
    // Do the same for the ones
    // If there is a gap between these, it seems fixable. If there is overlap, you can't fix both sides of the issues UNLESS one side goes far enough to fix ALL issues.
    //
    // Let's flag issues first

    vector<bool> issues(n);
    int issue_count = 0;
    int zeros_count = 0;
    int ones_count = 0;
    vector<bool> zeros(n);
    vector<bool> ones(n);

    for(int i = 0; i < n; i++){
        issues[i] = a[i] != b[i];
        issue_count += issues[i];

        zeros[i] = a[i] == '0' && b[i] == '0';
        zeros_count += zeros[i];

        ones[i] = a[i] == '1' && b[i] == '1';
        ones_count += ones[i];
    }
    // There MUST be a non-overlapping combination of a and b that can fix all issues. You can only fix issues if both are equal!!! KEY
    //
    // start from the right on zeros, and see if ones can fit. If not, then shrink zeros to the next zeros and then push ones forward to see if they fit.
    // sum of both need to be equal to issue_count when they are non-overlapping


    int ic = 0;
    int zi = n-1;
    int oi = n-1;
    do {
        while(!ones[oi] && oi >= 0){ic -= issues[oi];oi--;} 
        while((!zeros[zi] || zi > oi) && zi >= 0){ic += issues[zi];zi--;} // shift zi to the next valid zero index that is past oi

        //cout << "zi:" << zi << " oi:" << oi  << " ic:" << ic << endl;
        //if((oi < 0 || zi < 0) || ic == 0){break;}
        ic -= issues[oi];
        oi--; // try to find the next one
        //cout << "zi:" << zi << " oi:" << oi  << " ic:" << ic << endl;
    }while (ic != 0 && oi >= 0 && zi >= 0);
    if(ic == 0 && !(oi == -1 || zi == -1)){
        YES;
    }
    else{
        NO;
    }
    // add issues when zeros passes something, subtract when ones pass something.
    //
    
    // now both are far enough. if they can't meet each other or pass each other, it's likely impossible.
    //
    // Check the pass each other case.
    
    // if(zero_max > one_min)YES;
    // else NO;
}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
