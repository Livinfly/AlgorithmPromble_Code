#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e7 + 10;

int fa[N], siz[N];

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
  int T;
  while (cin >> T)
  {
    for (int i = 1; i < N; i++)
      fa[i] = i, siz[i] = 1;
    int res = 1;
    while (T--)
    {
      int x, y;
      cin >> x >> y;
      int fx = get_fa(x), fy = get_fa(y);
      if (fx != fy)
      {
        fa[fy] = fx, siz[fx] += siz[fy];
        res = max(res, siz[fx]);
      }
    }
    cout << res << endl;
  }
  return 0;
}