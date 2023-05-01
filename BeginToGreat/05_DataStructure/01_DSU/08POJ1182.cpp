#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 5e4 + 10;

int fa[N], d[N];

int pMod(int x)
{
  return (x % 3 + 3) % 3;
}
int get_fa(int x)
{
  if (fa[x] == x)
    return x;
  int r = get_fa(fa[x]);
  d[x] = (d[x] + d[fa[x]]) % 3;
  return fa[x] = r;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int n, T;
  cin >> n >> T;
  for (int i = 1; i <= n; i++)
    fa[i] = i;
  int res = 0;
  while (T--)
  {
    int op, x, y;
    cin >> op >> x >> y;
    if (x > n || y > n || op == 2 && x == y)
    {
      res++;
      continue;
    }
    int fx = get_fa(x), fy = get_fa(y);
    if (op == 1)
    {
      if (fx != fy)
      {
        fa[fy] = fx;
        d[fy] = pMod(d[fx] + d[x] - d[y]); // x = y
      }
      else if (d[x] != d[y])
        res++;
    }
    else
    {
      if (fx != fy)
      {
        fa[fy] = fx;
        d[fy] = pMod(d[fx] + d[x] - d[y] + 1); // x = y-1
      }
      else if ((d[x] + 1) % 3 != d[y])
        res++;
    }
  }
  cout << res << endl;
  return 0;
}