#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n; cin >> n; // number of shops that sell beecola
    vector<long long> prices(n);

    for(int i = 0; i < n; i++){cin >> prices[i];}
    sort(prices.begin(),prices.end());
    // for(int i = 0; i < prices.size(); i++){cout << prices[i] << ", ";}
    // cout << endl;

    int q; cin >> q; // number of days we plan on buying the drink for
    vector<int> daily_wallet(q);
    for(int i = 0; i < q; i++){ cin >> daily_wallet[i];}

    //BINARY SEARCH IT
    //Find the upper bound of the prices we can afford
    for(auto& money : daily_wallet){

        // int l=0,h=prices.size()-1;

        // while(h>=l){
        //     int mid = (h-l)/2+l;
        //     if(prices[mid] <= money){ // less than or equal: raise the lower to finish finding solutions on the upper bound
        //         l = mid + 1;
        //     }
        //     else{ 
        //         h = mid - 1;
        //     }
        // }
        //cout << l << endl;
        cout << (upper_bound(prices.begin(), prices.end(), money) - prices.begin()) << endl;



        // old
        // int count = 0;
        // for(int i = 0; i < prices.size(); i++){
        //     if (money >= prices[i]){
        //         count++;
        //     }
        // }
        // cout << count << endl;
    }
}
