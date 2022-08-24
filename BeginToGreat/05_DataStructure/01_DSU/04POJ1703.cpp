#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n, m;
int fa[N], d[N];

int get_fa(int x)
{
  if (fa[x] == x)
    return x;
  int root = get_fa(fa[x]);
  d[x] ^= d[fa[x]];
  return fa[x] = root;
}

int main()
{
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  scanf("%d", &T);
  while (T--)
  {
    memset(d, 0, sizeof d);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
      fa[i] = i;
    while (m--)
    {
      char op[2];
      int a, b;
      scanf(" %s%d%d", op, &a, &b);
      int ta = get_fa(a), tb = get_fa(b);
      if (*op == 'D')
      {
        if (ta != tb)
        {
          fa[tb] = ta;
          d[tb] = d[ta] ^ d[a] ^ d[b] ^ 1;
        }
      }
      else
      {
        if (ta != tb)
          puts("Not sure yet.");
        else if (d[a] == d[b])
          puts("In the same gang.");
        else
          puts("In different gangs.");
      }
    }
  }
  return 0;
}