#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int N = 3e5 + 10;

LL idx, h[N], ne[N * 3], ver[N * 3], w[N * 3];
LL n, m, p, q;
LL d[N];
char g[N];
bool vis[N];

bool ok(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m) return false;
  return true;
}
void add(int x, int y, int u, int c) {
  if (!ok(x, y)) return;
  int v = x * m + y;
  ver[idx] = u, w[idx] = c, ne[idx] = h[v], h[v] = idx++;
}
void dijkstra(int S) {
  priority_queue<PLL, vector<PLL>, greater<PLL> > heap;
  heap.push({0, S});
  while (heap.size()) {
    auto t = heap.top();
    heap.pop();
    LL tc = t.fi, tu = t.se;
    if (vis[tu]) continue;
    vis[tu] = true;
    d[tu] = tc;
    for (int i = h[tu]; ~i; i = ne[i]) {
      int v = ver[i];
      if (!vis[v] && d[v] > d[tu] + w[i]) heap.push({d[tu] + w[i], v});
    }
  }
}
void solve() {
  memset(h, -1, sizeof h);
  memset(d, 0x3f, sizeof d);
  cin >> n >> m >> p >> q;
  for (int i = 0; i < n; i++) cin >> g + i* m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int u = i * m + j;
      if (g[u] == 'L')
        add(i - 1, j + 1, u, p), add(i + 1, j + 1, u, p), add(i, j + 2, u, q);
      else if (g[u] == 'R')
        add(i - 1, j - 1, u, p), add(i + 1, j - 1, u, p), add(i, j - 2, u, q);
      else if (g[u] == 'U')
        add(i + 1, j - 1, u, p), add(i + 1, j + 1, u, p), add(i + 2, j, u, q);
      else if (g[u] == 'D')
        add(i - 1, j - 1, u, p), add(i - 1, j + 1, u, p), add(i - 2, j, u, q);
      else if (g[u] == '.')
        ver[idx] = u, ne[idx] = h[n * m], h[n * m] = idx++;
    }
  dijkstra(n * m);
  // for (int i = 0; i < n; i++)
  //   for (int j = 0; j < m; j++) cout << d[i * m + j] << " \n"[j == m - 1];
  LL res = 0x3f3f3f3f3f3f3f3f;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int u = i * m + j;
      if (j < m - 1) res = min(res, d[u] + d[u + 1]);
      if (i < n - 1) res = min(res, d[u] + d[u + m]);
    }
  if (res == (LL)0x3f3f3f3f3f3f3f3f) res = -1;
  cout << res << '\n';
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
/*
  虚拟原点，转化建图
*/