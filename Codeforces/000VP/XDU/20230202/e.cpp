#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 65;

struct rec {
    LL c, w;
    bool operator <(const rec &o)const {
        return w < o.w || w == o.w && c < o.c;
    }
} a[N];
int n, k;
LL p, res, mn = 1e18, mx = 0;
bool ok = false;

bool dfs(int u, int last, LL sum, LL ans, bool op) {
    // cout << u << ' ' << last << endl;
    if(u == k) {
        if(sum == p) {
            res = ans;
            return true;
        }
        return false;
    }
    if(last > n) return false;
    if(mn > (p-sum)/(k-u) || mx < (p-sum)/(k-u)) 
        return false;
    if(op) {
        for(LL i = u+1; i <= k; i ++) {
            if(a[last].c > (p-sum)/(i-u)) continue;
            if(dfs(i, last+1, sum+a[last].c*(i-u), ans+a[last].w*(i-u), op)) {
                // cout << a[last].c << ' ' << a[last].w << ' ' << i-u << '\n';
                return true;
            }
        }
    }
    else {
        for(LL i = k; i > u; i --) {
            if(a[last].c > (p-sum)/(i-u)) continue;
            if(dfs(i, last+1, sum+a[last].c*(i-u), ans+a[last].w*(i-u), op)) {
                // cout << a[last].c << ' ' << a[last].w << ' ' << i-u << '\n';
                return true;
            }
        }
    }
    return dfs(u, last+1, sum, ans+a[last].w, op);
}
void solve() {
    // 4 5 36
    cin >> n >> k >> p;
    for(int i = 0; i < n; i ++) {
        cin >> a[i].c >> a[i].w;
        mn = min(mn, a[i].c);
        mx = max(mx, a[i].c);
    }
    res = -1;
    sort(a, a+n);
    dfs(0, 0, 0, 0, false);
    if(res == -1) {
        cout << "-1\n";
        return;
    }
    cout << res << ' ';
    res = 0;
    dfs(0, 0, 0, 0, true);
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
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