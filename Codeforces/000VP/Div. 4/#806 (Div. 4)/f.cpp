#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10;

int n;
int tr[N];

int lowbit(int x) {
    return x & -x;
}
void add(int x, int c) {
    for(; x <= n; x += lowbit(x))
        tr[x] += c;
}
LL sum(int x) {
    LL res = 0;
    for(; x > 0; x -= lowbit(x))
        res += tr[x];
    return res;
}
void solve() {
    memset(tr, 0, sizeof tr);
    cin >> n;
    LL res = 0;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        if(x < i) {
            add(i, 1);
            if(x)
                res += sum(x-1);
            // cout << x-1 << ' ' << sum(x-1) << '\n';
        }
    }
    cout << res << '\n';
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