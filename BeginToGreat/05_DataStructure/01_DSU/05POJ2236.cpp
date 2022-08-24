#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int N = 1010;

int idx, h[N], ne[N * N], ver[N * N]; // 最大边数为N*N/2*2
int n, fa[N];
int maxd;
bool st[N];
PII p[N];

void add(int a, int b)
{
  ver[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int get_dist(PII a, PII b)
{
  int dx = a.first - b.first, dy = a.second - b.second;
  return dx * dx + dy * dy;
}
int get_fa(int x)
{
  return fa[x] == x ? x : fa[x] = get_fa(fa[x]);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  memset(h, -1, sizeof h);
  cin >> n >> maxd;
  maxd *= maxd;
  for (int i = 1; i <= n; i++)
  {
    cin >> p[i].first >> p[i].second;
    fa[i] = i;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (get_dist(p[i], p[j]) <= maxd)
        add(i, j), add(j, i);

  char op[2];
  while (cin >> op)
  {
    if (op[0] == 'O')
    {
      int x;
      cin >> x;
      st[x] = true;
      int a = get_fa(x);
      for (int i = h[x]; ~i; i = ne[i])
      {
        int v = ver[i];
        if (st[v])
        {
          int b = get_fa(v);
          if (a != b)
            fa[b] = a;
        }
      }
    }
    else
    {
      int x, y;
      cin >> x >> y;
      if (get_fa(x) == get_fa(y))
        cout << "SUCCESS" << '\n';
      else
        cout << "FAIL" << '\n';
    }
  }
  return 0;
}