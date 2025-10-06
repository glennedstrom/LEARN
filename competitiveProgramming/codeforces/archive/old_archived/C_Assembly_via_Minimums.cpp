#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){
    // optional
}

void solve() {
    int n; cin >> n;
    int n2 = n*(n-1)/2;
    vector<int> v(n2);

    int max_n = INT32_MIN;
    for(int i = 0; i < n2; i++){ cin >> v[i]; max_n = max(v[i],max_n);}
    ranges::sort(v);

    // for(auto& i : v) cout << i << ' ';
    // cout << endl;

    vector<int> c_to_num(n2+1, 1e9+1); // Ties are impossible. The number is the location in the array it needs to go. Print them in greatest to least order of indexes(counts) and last x2

    // if it is sorted, just loop through and count how many until it changes, then insert it into the count vector at the correct spot.
    // (pow(8*c_to_num[cnt]+1, 0.5))/2
    int cnt = 1;
    for(int i = 1; i <= v.size(); i++){
        if(i == v.size() || v[i] != v[i-1]){
            c_to_num[cnt] = v[i-1];
            cnt = 1;
        }
        else{
            cnt++;
        }
    }
    auto count_to_pos = [&](int n){
        return n*(n-1)/2;
    };
    vector<int> out(n,max_n);//1e9+1);

    // ISSUE: This is so bad, you need help

    for(int i = 0; i < c_to_num.size(); i++){
        if(c_to_num[i] != 1e9+1){
            int cur = c_to_num[i];
            // i == count

            int l=0,r=n2+1;

            while(l<r){
                int mid = (r-l)/2+l;

                if(count_to_pos(mid) < i){
                    l = mid + 1;
                }
                else{
                    r = mid;
                }
            }
            // cout << cur << " is at: " << n-r << endl;
            out[n-r] = cur;

            // binary search from 0 to 5 for a value of n that satisfies n*(n-1)/2 == count
            //cout << "count " << i << ": " << c_to_num[i] << endl;
        }
    }
    // cout << endl;
    for(auto& i : out){cout << i << ' ';}
    cout << endl;
    // x*(x-1)/2 = count
    //
    // if count is 10 in the case 2 2 2 2 2 2 2 2 2 2; then n - x is the array spot. fill in other values with the max of the array


    // for 1 3 1; there are two ones, and one three.
    // This means 1 needs to be 3 places from the end to be paired with the next 2 as mins
    // the next has to be 3 and something ge 3
    // ex:
    // 1 3 3

    // ISSUE: from left to right, pairs do mean how many nums are to the right, BUT if you have two of your number, then it is right+right-1 because there are two now that pair with everything to the right
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
