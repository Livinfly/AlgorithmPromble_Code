#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> vis(n);
    for(auto &x : a) cin >> x;
    int cur = 0;
    for(int i = 0; i < min(31, n); i ++) {
        int p = -1, tcur = 0;
        for(int j = 0; j < n; j ++) {
            if(!vis[j] && (!~p || tcur < (cur|a[j])))
                tcur = cur | a[j], p = j;
        }
        vis[p] = true;
        cur = tcur;
        cout << a[p] << ' ';
    }
    for(int i = 0; i < n; i ++)
        if(!vis[i]) cout << a[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int Tcase;
    cin >> Tcase;  // scanf("%d", &Tcase);
    while (Tcase--) solve();
    return 0;
}
/*
选少量的数，暴力时间复杂度符合
*/