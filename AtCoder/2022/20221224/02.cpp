#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int a[100010];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    int q;
    cin >> q;
    while(q --) {
        int op;
        cin >> op;
        if(op == 1) {
            int k, x;
            cin >> k >> x;
            a[k] = x;
        }
        else {
            int k;
            cin >> k;
            cout << a[k] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    solve();
    return 0;
}