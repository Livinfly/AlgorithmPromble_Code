#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 2510;

// A->K  urdl -> 0000
int op[11] = {9, 12, 3, 6, 10, 5, 13, 11, 7, 14, 15};
int n, m;
int fa[N], mp[50][50];
char g[50][50];

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
  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
      mp[i][j] = i * 50 + j;
  while (cin >> n >> m, n >= 0 || m >= 0)
  {
    for (int i = 0; i < N; i++)
      fa[i] = i;
    int res = n * m;
    for (int i = 0; i < n; i++)
      cin >> g[i];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
      {
        int t1 = op[g[i][j] - 'A'];
        if (t1 >> 2 & 1) // r
        {
          int a = i, b = j + 1;
          if (b < m)
          {
            int t2 = op[g[a][b] - 'A'];
            if (t2 & 1)
            {
              int fx = get_fa(mp[i][j]), fy = get_fa(mp[a][b]);
              if (fx != fy)
              {
                fa[fy] = fx;
                res--;
              }
            }
          }
        }
        if (t1 >> 1 & 1) // d
        {
          int a = i + 1, b = j;
          if (a < n)
          {
            int t2 = op[g[a][b] - 'A'];
            if (t2 >> 3 & 1)
            {
              int fx = get_fa(mp[i][j]), fy = get_fa(mp[a][b]);
              if (fx != fy)
              {
                fa[fy] = fx;
                res--;
              }
            }
          }
        }
      }
    cout << res << endl;
  }
  return 0;
}
/*
  二进制存每个type pipe的状态
*/