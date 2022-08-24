#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;

typedef long long LL;

const int N = 3e4 + 10;

int fa[N], siz[N], cnt[N];

int get_fa(int x)
{
  if (fa[x] == x)
    return x;
  int t = fa[x];
  fa[x] = get_fa(fa[x]);
  cnt[x] += cnt[t];
  return fa[x];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  for (int i = 1; i < N; i++)
    fa[i] = i, siz[i] = 1;
  int T;
  cin >> T;
  while (T--)
  {
    char op[2];
    cin >> op;
    if (*op == 'M')
    {
      int x, y;
      cin >> x >> y;
      int fx = get_fa(x), fy = get_fa(y);
      if (fx != fy)
      {
        fa[fx] = fy;
        cnt[fx] = siz[fy]; // cnt加过的，都不会再成为祖宗
        siz[fy] += siz[fx];
      }
    }
    else
    {
      int a;
      cin >> a;
      get_fa(a);
      cout << cnt[a] << endl;
    }
  }
  return 0;
}
/*
  做类似树形前缀和的优化
*/