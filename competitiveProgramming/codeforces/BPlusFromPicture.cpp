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
    int h,w; cin >> h >> w;

    vector<string> vs(h);
    for(int i = 0; i < h; i++){ cin >> vs[i]; }

    vector<int> idxh(max(h,w));
    vector<int> idxw(max(h,w));
    int star_count = 0;
    int start_x, start_y;
    for(int i = 0; i<h;i++){
        for(int j=0;j<w;j++){
            if(vs[i][j] == '*'){
                idxh[i]++;
                idxw[j]++;
                star_count++;
                start_x = i;
                start_y = j;
            }
        }
    }
    if(star_count < 5){ NO; return; } // likely not needed
    // CENTER MUST HAVE 1 ON EACH SIDE
    int cross_height = *max_element(idxh.begin(),idxh.end());
    int cross_width = *max_element(idxw.begin(),idxw.end());
    int cross_height_index = max_element(idxh.begin(),idxh.end()) - idxh.begin();
    int cross_width_index = max_element(idxw.begin(),idxw.end()) - idxw.begin();
    int chi=cross_height_index;
    int cwi=cross_width_index;
    if(cross_height_index >= 1 && cross_height_index < h-1 && cross_width_index >= 1 && cross_width_index < w-1){
        if(vs[chi-1][cwi] == '*' && vs[chi+1][cwi] == '*' && vs[chi][cwi-1] == '*' && vs[chi][cwi+1] == '*'){ }
        else{
            NO;
            return;
        }
    }
    else{
        NO;
        return;
    }

    bool connected = true;
    queue<pair<int,int>> q;
    vector visited(h, vector<bool>(w,false));
    q.push({start_x,start_y});
    vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    int cnt = 0;
    while(!q.empty()){
        auto [ch, cw] = q.front();
        //cout << ch << " : " << cw << " " << vs[ch][cw] << endl;
        q.pop();
        visited[ch][cw] = true;
        cnt++;

        for(auto& [hoff,woff] : dirs){
            if(ch + hoff >= 0 && ch + hoff < h && cw + woff >= 0 && cw + woff < w && !visited[ch + hoff][cw + woff] && vs[ch+hoff][cw+woff] == '*'){
                //if in bounds & unvisited
                q.push({ch + hoff, cw + woff});
            }
        }
    }


    // cout << star_count << " " << cnt << endl;
    if(cross_height + cross_width - 1 == star_count && star_count == cnt) YES;
    else NO;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
