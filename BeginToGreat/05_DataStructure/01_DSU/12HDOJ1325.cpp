#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n, vcnt, ecnt;
int fa[N], nums[N], indeg[N];
bool flag, vis[N];

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
  for (int i = 1; i < N; i++)
    fa[i] = i;
  int x, y, CCC = 0;
  while (cin >> x >> y, x >= 0 || y >= 0) // 两个负数结束
  {
    if (!x && !y)
    {
      bool tflag = false;
      for (int i = 1; i < N; i++)
      {
        if (vis[i] && !indeg[i])
        {
          if (tflag)
          {
            flag = true;
            break;
          }
          tflag = true;
        }
      }
      if (flag || ecnt && ecnt != vcnt - 1)
        cout << "Case " << ++CCC << " is not a tree." << endl;
      else
        cout << "Case " << ++CCC << " is a tree." << endl;
      memset(vis, 0, sizeof vis);
      n = vcnt = ecnt = 0;
      flag = false;
      for (int i = 1; i < N; i++)
        fa[i] = i, indeg[i] = 0;
      continue;
    }
    if (!vis[x])
      vis[x] = true, vcnt++;
    if (!vis[y])
      vis[y] = true, vcnt++;
    indeg[y]++;
    ecnt++;
    int fx = get_fa(x), fy = get_fa(y);
    if (fx != fy)
      fa[fy] = fx;
    else
      flag = true;
  }
  return 0;
}