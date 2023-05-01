#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e4 + 10;

int n, m;
int fa[N], siz[N], cnt[N];

int get_fa(int x)
{
  if (fa[x] == x)
    return x;
  int r = get_fa(fa[x]);
  cnt[x] += cnt[fa[x]];
  return fa[x] = r;
}

int main()
{
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T, CCC = 0;
  scanf("%d", &T);
  while (T--)
  {
    printf("Case %d:\n", ++CCC);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
      fa[i] = i, siz[i] = 1, cnt[i] = 0;
    while (m--)
    {
      char op;
      scanf(" %c", &op);
      if (op == 'T') // x->y
      {
        int x, y;
        scanf("%d%d", &x, &y);
        int fx = get_fa(x), fy = get_fa(y);
        fa[fx] = fy;
        cnt[fx] = 1;
        siz[fy] += siz[fx];
      }
      else
      {
        int x;
        scanf("%d", &x);
        int fx = get_fa(x);
        printf("%d %d %d\n", fa[fx], siz[fx], cnt[x]);
      }
    }
  }
  return 0;
}