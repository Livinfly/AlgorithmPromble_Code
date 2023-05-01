#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int cnt, maxv;
int fa[N], res[N];
bool flag;
set<int> edges[N];

void init()
{
  flag = false;
  for (int i = 1; i < N; i++)
    fa[i] = i;
  for (int i = 1; i <= maxv; i++)
    edges[i].clear();
  cnt++, maxv = -1;
}
int get_fa(int x)
{
  return fa[x] == x ? x : fa[x] = get_fa(fa[x]);
}
bool Union(int p, int q)
{
  if (p != q)
  {
    if (edges[p].size() > edges[q].size())
      swap(p, q);
    for (auto it : edges[p])
    {
      if (it == q)
        return false;
      edges[it].erase(p);
      edges[it].insert(q);
      edges[q].insert(it);
    }
  }
  fa[p] = q;
  return true;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  init();
  int T;
  cin >> T; // scanf("%d", &T);
  for (int CC = 1; CC <= T; CC++)
  {
    int x, y, op;
    cin >> x >> y >> op;
    maxv = max({maxv, x, y});
    int fx = get_fa(x), fy = get_fa(y);
    if (!op) // diff
    {
      if (fx == fy)
        res[cnt] = CC, flag = true;
      else
      {
        edges[fx].insert(fy);
        edges[fy].insert(fx);
      }
    }
    else if (!Union(fx, fy)) // same
      res[cnt] = CC, flag = true;
    if (flag)
      init();
  }
  cnt--;
  cout << cnt << endl;
  for (int i = 1; i <= cnt; i++)
    cout << res[i] - res[i - 1] << endl;
  return 0;
}
/*
  大概原理已经清楚了，因为不是一类一类的，不能用加权并查集。
  需要另外弄一个记录“不同”的边
  用set来改边，采用思想启发式合并（小合到大的里面去）
  set不能直接修改所以原本的pair<int,int> 方案 错误qwq
*/