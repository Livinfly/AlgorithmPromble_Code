#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const double eps = 1e-9;

vector<double> num;

double f(double x) {
    double res = 0;
    double t = 1;
    for(int i = 0; i < num.size(); i ++, t *= x) {
        res += t*num[i];
    }
    return res;
}
void solve() {
    LL n;
    double l, r;
    cin >> n >> l >> r;
    for(int i = 0; i <= n; i ++) {
        double x;
        cin >> x;
        num.push_back(x);
    }
    reverse(all(num));
    while(r-l > eps*3) {
        double mid = (l+r)/2;
        double midl = mid-eps, midr = mid+eps;
        if(f(midl)<f(midr)) l = midl;
        else r = midr;
        // cout << l << ' ' << r << endl;
    }
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}