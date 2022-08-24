#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 4e4 + 10, M = N << 1;

int idx, h[N], ne[M], ver[M], w[M];
int n, m;
int fa[N], d[N], res[210], st[N];
vector<PII> query[N];

void add(int a, int b, int c)
{
  ver[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u, int f)
{
  for (int i = h[u]; ~i; i = ne[i])
  {
    int v = ver[i];
    if (v != f)
    {
      d[v] = d[u] + w[i];
      dfs(v, u);
    }
  }
}
int get_fa(int x)
{
  return fa[x] == x ? x : fa[x] = get_fa(fa[x]);
}
void tarjan(int u)
{
  st[u] = 1;
  for (int i = h[u]; ~i; i = ne[i])
  {
    int v = ver[i];
    if (!st[v])
    {
      tarjan(v); // 先搜再标记（本身就为子孙关系）
      fa[v] = u;
    }
  }
  for (auto x : query[u])
  {
    int v = x.first, id = x.second;
    if (st[v] == 2) // 遍历完一个再查是为了get_fa(v)是最近公共祖先
    {
      int anc = get_fa(v);
      res[id] = d[u] + d[v] - d[anc] * 2;
    }
  }
  st[u] = 2;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  cin >> T; // scanf("%d", &T);
  while (T--)
  {
    memset(h, -1, sizeof h);
    memset(d, 0, sizeof d);
    memset(st, 0, sizeof st);
    idx = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      fa[i] = i;
    for (int i = 0; i < n - 1; i++)
    {
      int a, b, c;
      cin >> a >> b >> c;
      add(a, b, c), add(b, a, c);
    }
    for (int i = 0; i < m; i++)
    {
      int a, b;
      cin >> a >> b;
      query[a].push_back({b, i});
      query[b].push_back({a, i});
    }
    dfs(1, -1);
    tarjan(1);
    for (int i = 0; i < m; i++)
      cout << res[i] << '\n';
  }
  return 0;
}
/*
  离线LCA 表示真的忘完了
*/