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

auto comp = [](int target, int x){return target < x*x;};
//bool func(int target, int mid){ // for square root
//    return target < mid*mid;
//}

int upper_vector_func(vector<int>& nums, int target, bool (*comp)(int x, int target)){
    int l=0, h=nums.size();

    while(l != h){
        int mid = (h-l)/2 + l;

        if(comp(target, nums[mid])) // push the left side to the right end first
            h = mid;
        else // bring the right end closer
            l = mid + 1;
    }

    return h == nums.size() ? 0 : nums[h]; // usually dereferenc
}

int upper_vector(vector<int>& nums, int target){
    int l=0, h=nums.size();

    while(l != h){
        int mid = (h-l)/2 + l;

        if(target < nums[mid]) // push the left side to the right end first
            h = mid;
        else // bring the right end closer
            l = mid + 1;
    }

    return h == nums.size() ? 0 : nums[h];
}

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for(auto& n : nums){ cin >> n; }

    auto [l,h] = minmax_element(nums.begin(),nums.end());
    cout << *l << ' ' << *h << endl;

    int target = (h-l)/2 + n/4;
    cout << "Target: " << target << endl;

    cout << upper_vector(nums, target) << endl;
    cout << *upper_bound(nums.begin(),nums.end(),target) << endl;

    cout << upper_vector_func(nums, target, comp) << "^2" << endl; // returns the first number above num where num == num^2
    cout << *upper_bound(nums.begin(),nums.end(),target, comp) << endl;


    cout << endl << "NORMAL VERSION: " << endl;
    for(auto& n : nums){
        if(upper_vector(nums, n) != *upper_bound(nums.begin(),nums.end(),n)){
            cout << n << " == target; WRONG: " << upper_vector(nums, n) << " != " << *upper_bound(nums.begin(),nums.end(),n) << " (ans)" << endl;
        }
    }


    cout << endl << "FUNC VERSION: " << endl;
    for(auto& n : nums){
        if(upper_vector_func(nums, n, comp) != *upper_bound(nums.begin(),nums.end(),n, comp)){
            cout << n << " == target; WRONG: " << upper_vector_func(nums, n, comp) << " != " << *upper_bound(nums.begin(),nums.end(),n, comp) << " (ans)" << endl;
        }
        else{
            cout << n << " == target; CORRECT: " << upper_vector_func(nums, n, comp) << " == " << *upper_bound(nums.begin(),nums.end(),n, comp) << " (ans)" << endl;
        }
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
