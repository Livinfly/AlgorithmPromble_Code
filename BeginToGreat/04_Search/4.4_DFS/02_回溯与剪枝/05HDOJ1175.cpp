#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 1010;

int dxy[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};
int n, m;
int xx, yy, x2, y2;
int g[N][N];
bool vis[N][N];

bool dfs(int x, int y, int prev_dir, int change_cnt)
{
  for (int i = 0; i < 4; i++)
  {
    int a = x + dxy[i][0], b = y + dxy[i][1];
    int t;
    prev_dir == i || prev_dir == -1 ? t = 0 : t = 1;
    if (a == x2 && b == y2 && change_cnt + t <= 2) // 也需要考虑变向次数
      return true;
    if (a >= n || a < 0 || b >= m || b < 0 || g[a][b] || vis[a][b])
      continue;
    vis[a][b] = true;
    if (change_cnt + t <= 2)
      if (dfs(a, b, i, change_cnt + t))
      {
        vis[a][b] = false;
        return true;
      }
    vis[a][b] = false;
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  while (cin >> n >> m, n || m)
  {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> g[i][j];
    int Q;
    cin >> Q;
    while (Q--)
    {
      cin >> xx >> yy >> x2 >> y2;
      xx--, yy--, x2--, y2--;
      if (g[xx][yy] != g[x2][y2] || !g[xx][yy] || !g[x2][y2] || xx == x2 && yy == y2) // 不存在两个棋子为同个棋子
      {
        cout << "NO" << '\n';
        continue;
      }
      if (dfs(xx, yy, -1, 0))
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
  return 0;
}