#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;

bool st[N];

void solve() {
    memset(st, 0, sizeof st);
    int m, s;
    cin >> m >> s;
    vector<int> a(m);
    int maxn = 0;
    for(auto &x: a) {
        cin >> x;
        st[x] = true;
        maxn = max(maxn, x);
    }
    int i;
    for(i = 1; s > 0; i ++) {
        if(!st[i]) s -= i, st[i] = true;
    }
    bool flag = true;
    for(int i = 1; i <= maxn; i ++) {
        if(!st[i]) {
            flag = false;
            break;
        }
    }
    if(!s && flag) cout << "YES\n";
    else cout << "NO\n";
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