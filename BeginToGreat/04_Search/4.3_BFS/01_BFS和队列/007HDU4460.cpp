#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

const int N = 1010, M = int(1e5 + 10), INF = 0x3f3f3f3f;

int idx, h[N], ne[M << 1], ver[M << 1];
int n, m;
int f[N];
map<string, int> nameIdx;

void add(int a, int b)
{
  ver[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int bfs(int A)
{
  memset(f, 0x3f, sizeof f);
  queue<int> q;
  q.push(A);
  f[A] = 0;
  while (q.size())
  {
    int t = q.front();
    q.pop();
    for (int i = h[t]; ~i; i = ne[i])
    {
      int v = ver[i];
      if (f[v] == INF)
      {
        f[v] = f[t] + 1;
        q.push(v);
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++)
    res = max(res, f[i]);
  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  while (cin >> n, n)
  {
    memset(h, -1, sizeof h);
    nameIdx.clear();
    idx = 0;
    for (int i = 0; i < n; i++)
    {
      string str;
      cin >> str;
      nameIdx[str] = i;
    }
    cin >> m;
    if (m < n - 1)
    {
      cout << -1 << '\n';
      continue;
    }
    while (m--)
    {
      string s1, s2;
      cin >> s1 >> s2;
      int a = nameIdx[s1], b = nameIdx[s2];
      add(a, b), add(b, a);
    }
    int res = -1;
    for (int i = 0; i < n; i++)
      res = max(res, bfs(i));
    if (res == INF)
      res = -1;
    cout << res << '\n';
  }
  return 0;
}