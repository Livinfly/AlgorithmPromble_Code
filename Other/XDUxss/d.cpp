#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6+10;

int n, m;
int a[N], b[N];
int f[N], q[N];

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        b[i] = min(n, i+a[i]);
    }
    for(int i = n; i > 0; i --) 
        b[i] = max(b[i], b[b[i]]);
//    for(int i = 1; i <= n; i ++)
//        cout << b[i] << ' ';
//    cout << '\n';
    memset(f, 0xcf, sizeof f);
    f[0] = 0;
    q[0] = 0;
    int hh = 0, tt = 0;
    for(int i = 1; i <= n; i ++) {
        f[b[i]] = max(f[b[i]], f[q[hh]]+1);
        while(hh <= tt && i-m+1 > q[hh]) hh ++;
        while(hh <= tt && f[i] >= f[q[tt]]) tt --;
        q[++ tt] = i;
    }
    // for(int i = 1; i <= n; i ++)
    //     cout << i << ':' << f[i] << '\n';
    cout << f[n] << ' ';
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    hh = 0, tt = 0;
    q[0] = 0;
    for(int i = 1; i <= n; i ++) {
        f[b[i]] = min(f[b[i]], f[q[hh]]+1);
        while(hh <= tt && i-m+1 > q[hh]) hh ++;
        while(hh <= tt && f[i] <= f[q[tt]]) tt --;
        q[++ tt] = i;
    }
    // for(int i = 1; i <= n; i ++)
    //     cout << i << ':' << f[i] << '\n';
    cout << f[n] << '\n';
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