#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int ff[3][3] = {
    {2, 2, 3},
    {2, 3, 2},
    {3, 2, 2}
};

void solve() {
    LL n, h, cnt1 = 2, cnt2 = 1;
    cin >> n >> h;
    vector<LL> a(n);
    for(auto &x: a) cin >> x;
    sort(all(a));
    int res = 0;
    auto work = [&](int op) {
        LL th = h;
        int p = 0, tres = 0;
        for(auto x : a) {
            if(th > x) th += x/2;
            else {
                while(th <= x && p < 3) th *= ff[op][p ++];
                if(th <= x && p == 3) break;
                th += x/2;
            }
            tres ++;
        }
        return tres;
    };
    for(int i = 0; i < 3; i ++)
        res = max(res, work(i));
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int T;
    cin >> T;  // scanf("%d", &T);
    while (T--) solve();
    return 0;
}