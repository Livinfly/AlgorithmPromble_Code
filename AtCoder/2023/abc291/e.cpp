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

int idx, h[N], ne[N], ver[N];
int n, m;
int degIn[N], ans[N];

void add(int a, int b) {
    // cout << "edge - " << a << ' ' << b << '\n';
    ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
bool bfs() {
    queue<int> q;
    for(int i = 1; i <= n; i ++) {
        if(!degIn[i]) {
            if(q.empty())
                q.push(i);
            else {
                return false;
            }
        }
    }
    int p = 1;
    while(q.size()) {
        int u = q.front(); q.pop();
        ans[u] = p ++;
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = ver[i];
            // cout << "edge - - " << u << ' ' << v << '\n';
            if(-- degIn[v] == 0) {
                if(q.empty())
                    q.push(v);
                else {
                    return false;
                }
            }
        }
    }
    return true;
}
void solve() {
    cin >> n >> m;
    idx = 0;
    // 先更新成-1
    for(int i = 1; i <= n; i ++)
        h[i] = -1, ans[i] = 0, degIn[i] = 0;
    while(m --) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        degIn[b] ++;
    }
    if(bfs()) {
        cout << "Yes\n";
        for(int i = 1; i <= n; i ++)
            cout << ans[i] << " \n"[i == n];
    }
    else {
        cout << "No\n";
    }
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