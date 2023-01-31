#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
const double PI = 3.1415926535897932384;

struct P {
    double x, y, z, r;
} p[N];

int n;

double GetDist2(P a, P b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
double GetVol(P a, P b) {
    double dist2 = GetDist2(a, b);
    if(dist2 >= a.r+b.r) return 0;
    
    if(dist2+a.r <= b.r) return 4.0/3.0*PI*a.r*a.r*a.r;
    if(dist2+b.r <= a.r) return 4.0/3.0*PI*b.r*b.r*b.r;

    /*
    double dx = (a.r*a.r-b.r*b.r)/dist2;
    double L = (dist2+dx)/2.0, l = dist2-L;
    double x1 = a.r - L, x2 = b.r - l;
    double res = PI*x1*x1*(a.r - x1 / 3.0);
    res += PI*x2*x2*(b.r - x2 / 3.0);
    */
    
    double cosA = (a.r*a.r+dist2*dist2-b.r*b.r)/(2.0*dist2*a.r);
    double hA = a.r*(1.0-cosA);
    double res = PI*hA*hA*(3.0*a.r-hA)/3.0;
 
    double cosB = (b.r*b.r+dist2*dist2-a.r*a.r)/(2.0*dist2*b.r);
    double hB = b.r*(1.0-cosB);
    res += PI*hB*hB*(3.0*b.r-hB)/3.0;

    return res;
}
void solve(int TTT) {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        double x, y, z, r;
        scanf("%lf%lf%lf%lf", &x, &y, &z, &r);
        p[i] = {x, y, z, r};
    }
    double x, y, z, r;
    scanf("%lf%lf%lf%lf", &x, &y, &z, &r);
    p[0] = {x, y, z, r};

    double res = 0;
    for(int i = 1; i <= n; i ++) {
        res += GetVol(p[0], p[i]);
        // printf("%.20f\n", GetVol(p[0], p[i]));
    }
    printf("Case #%d: %.20f\n", TTT, res);
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int Tcase;
    scanf("%d", &Tcase);
    for(int i = 1; i <= Tcase; i ++)
        solve(i);
    return 0;
}