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
// EPS for long doubles; do 1e-6 for floats
#define EPS 1e-10
#define INF 1e9

long double DEG_to_RAD(long double d) { return d*M_PI/180.0; }
long double RAD_to_DEG(long double r) { return r*180.0/M_PI; }

struct point {
  long double x, y;
  point() { x = y = 0.0; }
  point(long double _x, long double _y) : x(_x), y(_y) {}
  bool operator < (point other) const {
    if (fabs(x-other.x) > EPS)
      return x < other.x;
    return y < other.y;
  }
  bool operator == (point other) const {
    return (fabs(x-other.x) < EPS && (fabs(y-other.y) < EPS));
  }
};
point rotate(point p, long double theta) {
  long double rad = DEG_to_RAD(theta);
  return point(p.x*cos(rad) - p.y*sin(rad),
               p.x*sin(rad) + p.y*cos(rad));
}

void solve() {
    long double n; cin >> n; // work but we need a faster solution

    long double int_ang = 180*(n-2)/n;
    
    point start(1,0);
    point i(1,0);
    do
    {
        //cout << abs(start.x * i.x + start.y * i.y) << endl;
        if(abs(start.x * i.x + start.y * i.y) < 1e-7){
            YES;
            return;
        }
        i = rotate(i,int_ang);
    } while(!(i == start));
    NO;
}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
