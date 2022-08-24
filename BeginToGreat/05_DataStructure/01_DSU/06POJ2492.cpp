#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 2010;

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
void solve()
{
  memset(d, 0, sizeof d);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    fa[i] = i;
  bool flag = false;
  while (m--)
  {
    int x, y;
    scanf("%d%d", &x, &y);
    int fx = get_fa(x), fy = get_fa(y);
    if (fx != fy)
    {
      fa[fy] = fx;
      d[fy] = d[fx] ^ d[x] ^ d[y] ^ 1;
    }
    else if (d[x] == d[y])
    {

      flag = true;
      // return; 不能retrun，数据要读完……
    }
  }
  if (flag)
    puts("Suspicious bugs found!\n");
  else
    puts("No suspicious bugs found!\n");
}

int main()
{
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int CC = 1; CC <= T; CC++)
  {
    printf("Scenario #%d:\n", CC);
    solve();
  }

  return 0;
}