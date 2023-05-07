#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const double eps = 1e-8;
const double PI = acos(-1);

// Remind: LL in Point/dot/cross?
int sign(double a) {
    return (a < -eps ? -1 : (a > eps));
}
int dcmp(double a, double b) {
    return sign(a-b);
}
// Point
struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    Point operator - (const Point &p) {
        return Point(-p.x, -p.y);
    }
    friend Point operator + (const Point &a, const Point &b) {
        return Point(a.x+b.x, a.y+b.y);
    }
    friend Point operator - (const Point &a, const Point &b) {
        return Point(a.x-b.x, a.y-b.y);
    }
    Point operator * (const int &v) const {
        return Point(x*v, y*v);
    }
    Point operator / (const int &v) const {
        assert(v != 0);
        return Point(x/v, y/v);
    }
    bool operator < (const Point &o) const {
        int c = dcmp(x, o.x);
        if(c) return c == -1;
        return dcmp(y, o.y) == -1;
    }
    bool operator == (const Point &o) const {
        return dcmp(x, o.x) == 0 && dcmp(y, o.y) == 0;
    }
    double Dist(const Point &o) {
        return (*this-o).abs();
    }
    double alpha() {
        return atan2(y, x);
    }
    void read() {
        cin >> x >> y;
    }
    void write() {
        cout << '(' << x << ',' << y << ')' << '\n';
    }
    double abs() {
        return sqrt(abs2());
    }
    double abs2() {
        return x*x+y*y;
    }
    Point rot90() {
        return Point(-y, x);
    }
    Point unit() {
        return *this/abs();
    }
};
LL dot(const Point &a, const Point &b) {
    return 1LL*a.x*b.x + 1LL*a.y*b.y;
}
LL cross(const Point &a, const Point &b) {
    return 1LL*a.x*b.y - 1LL*a.y*b.x;
}
// Line
struct Line {
    // a -> b
    Point a, b;
    Line(Point _a = Point(), Point _b = Point()) : a(_a), b(_b) {}
};
bool PointOnLineLeft(const Point &p, const Line &l) {
    return cross(l.b-l.a, p-l.a) > 0;
}
Point LineIntersection(const Line &l1, const Line &l2) {
    return l1.a + (l1.b-l1.a) * (cross(l2.b-l2.a, l1.a-l2.a) / cross(l2.b-l2.a, l1.a-l1.b));
}
bool PointOnSegment(const Point &p, const Line &l) {
    return sign(cross(p-l.a, l.b-l.a)) == 0 && min(l.a.x, l.b.x) <= p.x && p.x <= max(l.a.x, l.b.x)
        && min(l.a.y, l.b.y) <= p.y && p.y <= max(l.a.y, l.b.y);
}
// Polygon
double area(const vector<Point> &poly) {
    double res = 0;
    int n = poly.size();
    for(int i = 0; i < n; i ++) {
        res += cross(poly[i], poly[(i+1)%n]);
    }
    return res / 2;
}
// 射线法
int PointInPolygonLine(const Point &p, const vector<Point> &poly) {
    // -1: out, 0: on, 1: in
    int n = poly.size(), res = 0;
    for(int i = 0; i < n; i ++) {
        Point u = poly[i], v = poly[(i+1)%n];
        if(PointOnSegment(p, Line(u, v))) {
            return 0;
        }
        if(dcmp(u.y, v.y) <= 0) {
            swap(u, v);
        }
        if(dcmp(p.y, u.y) > 0 || dcmp(p.y, v.y) <= 0) {
            continue;
        }
        res ^= PointOnLineLeft(p, Line(u, v));
    }
    if(res == 1) return 1;
    return -1;
}
// 转角法（优化）
int PointInPolygonAngle(const Point &p, const vector<Point> &poly) {
    // -1: out, 0: on, 1: in
    int n = poly.size(), wn = 0;
    for(int i = 0; i < n; i++) {
        Point u = poly[i], v = poly[(i+1)%n];
        if(PointOnSegment(p, Line(u, v))) {
            return 0;
        }
        int k = PointOnLineLeft(p, Line(u, v));
        int d1 = sign(u.y - p.y);
        int d2 = sign(v.y - p.y);
        if(k == 0 && d1 > 0 && d2 <= 0) wn ++;
        if(k > 0 && d1 <= 0 && d2 > 0) wn --;
    }
    if(wn != 0) return 1;
    return -1;
}
int PointInConvex(const Point &p, const vector<Point> &poly) {
    // counter-clockwise
    // -1: out, 0: on, 1: in
    if(PointOnLineLeft(p, Line(poly[1], poly[0])) ||
        PointOnLineLeft(p, Line(poly[0], poly.back())))
        return -1;
    if(PointOnSegment(p, Line(poly[0], poly.back()))) return 0;
    int n = poly.size();
    int l = 1, r = n-1;
    while(l < r) {
        int mid = l+r >> 1;
        if(PointOnLineLeft(p, Line(poly[0], poly[mid]))) l = mid+1;
        else r = mid;
    }
    if(PointOnSegment(p, Line(poly[r-1], poly[r]))) return 0;
    if(PointOnLineLeft(p, Line(poly[r-1], poly[r]))) return 1;
    return -1;
}


void solve() {
    int n;
    cin >> n;
    vector<Point> polygon(n);
    for(auto &p : polygon) {
        p.read();
    }
    int m;
    cin >> m;
    while(m --) {
        Point t;
        t.read();
        int r = PointInConvex(t, polygon);
        if(r == 0) {
            cout << "ON\n";
        }
        else if(r == 1) {
            cout << "IN\n";
        }
        else {
            cout << "OUT\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}