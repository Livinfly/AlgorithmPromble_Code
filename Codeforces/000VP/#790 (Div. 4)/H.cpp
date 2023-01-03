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

int tr[N];
int n;
int b[N];
PII a[N];

int lowbit(int x) {
    return x & -x;
}
void add(int x, int c) {
    for(;x <= n; x += lowbit(x)) 
        tr[x] += c;
}
LL sum(int x) {
    LL ans = 0;
    for(;x; x -= lowbit(x)) 
        ans += tr[x];
    return ans;
}
void solve() {
    memset(tr, 0, sizeof tr);
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        a[i] = mkp(x, -i);
    }
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i ++) {
        b[-a[i].second] = i;
    }
    LL res = 0;
    for(int i = n; i; i --) {
        res += sum(b[i]);
        // cout << i << ' ' << b[i] << ' ' << sum(b[i]) <<'\n';
        add(b[i], 1);
    }
    cout << res << '\n';
    // cout << "---------\n";
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