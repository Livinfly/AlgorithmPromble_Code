#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;

struct rec {
    LL a;
    int id;
    bool operator < (const rec &o) const {
        return a < o.a;
    }
} f[100010];


void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> f[i].a;
        f[i].id = i;
    }
    sort(f+1, f+n+1);
    LL mx = f[1].a;
    vector<PIL> ans;
    for(int i = 2; i <= n; i ++) {
        LL t = f[i].a%mx;
        if(t) {
            t = mx-t;
            // cout << f[i].id << ' ' << t << '\n';
            ans.push_back(mkp(f[i].id, t));
        }
        mx = max(mx, f[i].a+t);
        // cout << mx << '\n';
    }
    cout << ans.size() << '\n';
    for(auto x : ans)
        cout << x.first << ' ' << x.second << '\n';
    // cout << "----\n";
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