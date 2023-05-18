#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const double PI = acos(-1.0);

void solve() {
    double a, b;
    cin >> a >> b;
    if(a < b) swap(a, b);
    if(b * 2 <= a * sqrt(3.0)) {
    	cout << b*2/sqrt(3.0) << '\n';
    	return;
    }
    double l = b, r = b*2/sqrt(3.0);
    while(r-l > 1e-12) {
    	double mid = (l+r) / 2;
    	double alpha = acos(b / mid);
    	alpha = PI/6 - alpha;
    	if(mid*cos(alpha) <= a) l = mid;
    	else r = mid;
    }
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20); // double
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