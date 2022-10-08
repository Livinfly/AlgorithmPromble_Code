#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 510;

struct Node {
  int u, v, w;
};

LL d[N][N];

void solve() {
  memset(d, 0x3f, sizeof d);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) d[i][i] = 0;
  vector<Node> e(m);
  for (auto &x : e) {
    cin >> x.u >> x.v >> x.w;
    d[x.u][x.v] = d[x.v][x.u] = 1;
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  LL res = 1e18;
  for (auto ee : e) {
    int u = ee.u, v = ee.v;
    LL w = ee.w;
    res = min(res, w * (d[1][u] + d[v][n] + 1));
    res = min(res, w * (d[1][v] + d[u][n] + 1));
    for (int i = 1; i <= n; i++) {
      res = min(res, w * (d[1][i] + d[i][n] + d[i][u] + 2));
      res = min(res, w * (d[1][i] + d[i][n] + d[i][v] + 2));
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
  int T;
  cin >> T;  // scanf("%d", &T);
  while (T--) solve();
  return 0;
}
/*
  分两种情况，
  1. 选择的边，两个点u,v都在[1,n]的路径中
  2. 选择的边，只有u,v其中一个点在[1,n]的路径中
*/