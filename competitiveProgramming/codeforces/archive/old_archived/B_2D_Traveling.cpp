#include <cstdint>
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename T>
struct Point {
  T x;
  T y;
  int id;

  // Constructors
  Point() : x(0), y(0), id(-1) {}
  Point(const T& x_, const T& y_) : x(x_), y(y_), id(-1) {}
  Point(const T& x_, const T& y_, int id_) : x(x_), y(y_), id(id_) {}
  Point(const std::pair<T, T>& p) : x(p.first), y(p.second) {}
  template <typename A> explicit Point(const Point<A>& p) : x(p.x), y(p.y) {}

  explicit operator std::pair<T, T> () const { return std::pair<T, T>(x, y); }
  auto as_pair() const { return std::pair<T, T>(*this); }


  static constexpr T eps = static_cast<T>(1e-9);

  friend std::ostream& operator << (std::ostream& o, const Point& p) { return o << '(' << p.x << ',' << p.y << ')'; }
  friend std::istream& operator >> (std::istream& i, Point& p) { return i >> p.x >> p.y; }
  friend bool operator == (const Point& a, const Point& b) { return a.x == b.x && a.y == b.y; }
  friend bool operator != (const Point& a, const Point& b) { return !(a==b); }

  inline Point operator+(const Point& rhs) const { return Point(x + rhs.x, y + rhs.y); }
  inline Point operator-(const Point& rhs) const { return Point(x - rhs.x, y - rhs.y); }
  inline Point operator*(const T& rhs) const { return Point(x * rhs, y * rhs); }
  inline Point operator/(const T& rhs) const { return Point(x / rhs, y / rhs); }

  Point& operator += (const Point& p) { x += p.x, y += p.y; return *this; }
  Point& operator -= (const Point& p) { x -= p.x, y -= p.y; return *this; }
  Point& operator *= (const T& t) { x *= t, y *= t; return *this; }
  Point& operator /= (const T& t) { x /= t, y /= t; return *this; }

  Point operator + () const { return Point(+x, +y); }
  Point operator - () const { return Point(-x, -y); }


  friend T dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
  friend T cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
  friend T cross3(const Point& a, const Point& b, const Point& c) { return (b - a).cross(c - a); }

  inline T dist2() const { return x * x + y * y; }
  inline double dist() const { return sqrt((double)dist2()); }
  
  inline double angle() const { return atan2(y, x); } // angle [-pi, pi]
  inline Point unit() const { return *this/dist(); } // makes dist()=1
  inline Point perp_cw() const { return Point(y, -x); }
  inline Point perp_ccw() const { return Point(-y, x); }
  inline Point normal() const { return perp_cw().unit(); }
  // returns point rotated 'a' radians ccw around the origin
  inline Point rotate(double a) const { return Point(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }

  // shrink ints maintaining direction
  T int_norm() const { return std::gcd(x,y); }
  inline Point int_unit() const { if (!x && !y) return *this; return *this / this->int_norm(); }

  friend auto norm(const Point& a) { return a.dist2(); }
  friend auto abs(const Point& a) { return a.dist(); }
  friend auto unit(const Point& a) { return a.unit(); }
  friend auto arg(const Point& a) { return a.angle(); }
  friend auto int_norm(const Point& a) { return a.int_norm(); }
  friend auto int_unit(const Point& a) { return a.int_unit(); }
   


  // Comparators
  friend bool lex_less(const Point& a, const Point& b) { return std::tie(a.x, a.y) < std::tie(b.x, b.y); }
  inline bool operator<(const Point& rhs) const { return y < rhs.y || y == rhs.y && x < rhs.x; }

  inline bool is_upper() const { return y > eps || abs(y) <= eps && x > eps; }
  friend bool same_dir(const Point& a, const Point& b) { return cross(a,b) == 0 && dot(a,b) > 0; }
  // check if 180 <= s..t < 360
  friend bool is_reflex(const Point& a, const Point& b) { auto c = cross(a,b); return c ? (c < 0) : (dot(a, b) < 0); }


  // operator < (s,t) for angles in [base,base+2pi)
  friend bool angle_less(const Point& base, const Point& s, const Point& t) {
    int r = is_reflex(base, s) - is_reflex(base, t);
    return r ? (r < 0) : (0 < cross(s, t));
  }

  friend auto angle_cmp(const Point& base) { return [base](const Point& s, const Point& t) { return angle_less(base, s, t); }; }
  friend auto angle_cmp_center(const Point& center, const Point& dir) {
    return [center, dir](const Point& s, const Point& t) -> bool { return angle_less(dir, s-center, t-center); };
  }
 
  // is p in [s,t] taken ccw? 1/0/-1 for in/border/out
  friend int angle_between(const Point& s, const Point& t, const Point& p) {
    if (same_dir(p, s) || same_dir(p, t)) return 0;
    return angle_less(s, p, t) ? 1 : -1;
  }


  inline int cmp_polar(const Point& rhs) const {
    assert(abs(x) > eps || abs(y) > eps);
    assert(abs(rhs.x) > eps || abs(rhs.y) > eps);
    bool a = is_upper();
    bool b = rhs.is_upper();
    if (a != b) {
      return (a ? -1 : 1);
    }
    auto v = x * rhs.y - y * rhs.x;
    return (v > eps ? -1 : (v < -eps ? 1 : 0));
  }
};


template <typename T>
std::string to_string(const Point<T>& p) {
  return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}


void precalc(){
    // optional
}

void solve() {
    ll n,k,start,end; cin >> n >> k >> start >> end;

    auto manhat = [](Point<ll> a, Point<ll> b){ return abs(a.x-b.x)+abs(a.y-b.y);};

    vector<Point<ll>> cities(n+1); // fist k are major
    for(ll i = 1; i <= n; i++){ cin >> cities[i]; }

    // 1. go to the closest major city to start (cost) OR GO TO FINISH DIRECTLY (min)
    // 2. go to the closest major city to end (free)
    // 3. go to the end city (cost)

    ll costa = INT64_MAX/2; // cost to the closest major city
    for(ll i = 1; i <= k; i++){ // find closest free city
        costa = min(costa, manhat(cities[start], cities[i]));
    }
    ll costb = INT64_MAX/2; // cost to the closest major city to end
    for(ll i = 1; i <= k; i++){
        costb = min(costb, manhat(cities[end], cities[i]));
    }

    if(start <= k){ costa = 0; }
    if(end <= k){ costb = 0; }

    cout << min(costa + costb, manhat(cities[start], cities[end])) << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
