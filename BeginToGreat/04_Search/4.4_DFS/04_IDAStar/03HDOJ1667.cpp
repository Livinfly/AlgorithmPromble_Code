#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 27;
/*
        0     1
        2     3
  4  5  6  7  8  9  10
        11    12
  13 14 15 16 17 18 19
        20    21
        22    23
  0 - A
*/
int unop[10] = {5, 4, 7, 6, 1, 0, 3, 2};
int op[8][7] = {
    {0, 2, 6, 11, 15, 20, 22},
    {1, 3, 8, 12, 17, 21, 23},
    {10, 9, 8, 7, 6, 5, 4},
    {19, 18, 17, 16, 15, 14, 13},
    {23, 21, 17, 12, 8, 3, 1},
    {22, 20, 15, 11, 6, 2, 0},
    {13, 14, 15, 16, 17, 18, 19},
    {4, 5, 6, 7, 8, 9, 10},
};
int center[8] = {6, 7, 8, 12, 17, 16, 15, 11};
int depth;
int a[N], path[110], cnt[4];

int f()
{
  memset(cnt, 0, sizeof cnt);
  int res = 0;
  for (int i = 0; i < 8; i++)
    cnt[a[center[i]]]++;
  for (int i = 1; i <= 3; i++)
    res = max(res, cnt[i]);
  return 8 - res;
}
void work(int x)
{
  int t = a[op[x][0]];
  for (int i = 1; i < 7; i++)
    a[op[x][i - 1]] = a[op[x][i]];
  a[op[x][6]] = t;
}
bool dfs(int u)
{
  if (u + f() > depth)
    return false;
  if (!f())
    return true;
  for (int i = 0; i < 8; i++)
  {
    if (u && unop[path[u - 1]] == i)
      continue;
    work(i);
    path[u] = i;
    if (dfs(u + 1))
      return true;
    work(unop[i]);
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  //  freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  while (cin >> a[0], a[0])
  {
    for (int i = 1; i < 24; i++)
      cin >> a[i];
    depth = 0;
    while (!dfs(0))
      depth++;
    if (!depth)
      cout << "No moves needed";
    else
      for (int i = 0; i < depth; i++)
        cout << (char)('A' + path[i]);
    cout << '\n'
         << a[6] << endl;
  }
  return 0;
}