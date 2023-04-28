#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10, M = N<<1;

int idx, h[N], ne[M], ver[M];
int n, m;
int a[N], d[N];

void add(int a, int b) {
    ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
bool ok(int u) {
    set<PII> heap;
    heap.insert({a[u], u});
    int siz = 0;
    while(heap.size()) {
        auto t = *heap.begin();
        int uu = t.se;
        d[uu] = u;
        if(a[uu] > siz) return siz == n;
        heap.erase(heap.begin());
        siz ++;
        for(int i = h[uu]; ~i; i = ne[i]) {
            int v = ver[i];
            if(d[v] < u)
                heap.insert({a[v], v});
        }
    }
    return siz == n;
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        h[i] = -1;
        d[i] = 0;
        cin >> a[i];
    }
    while(m --) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    for(int i = 1; i <= n; i ++)
        if(!a[i] && !d[i] && ok(i)) {
            cout << "YES\n";
            return;
        }
    cout << "NO\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}