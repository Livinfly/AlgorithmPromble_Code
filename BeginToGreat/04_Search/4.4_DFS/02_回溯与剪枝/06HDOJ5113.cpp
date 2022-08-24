#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 6;

int n, m, k;
int dxy[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};
int g[N][N], ans[N][N], color_cnt[30];
bool flag;

bool check(int x, int y)
{
  for (int i = 0; i < 4; i++)
  {
    int a = x + dxy[i][0], b = y + dxy[i][1];
    if (a < 0 || a >= n || b < 0 || b >= m)
      continue;
    if (g[x][y] == g[a][b])
      return false;
  }
  return true;
}
bool dfs(int x, int y, int type, int cnt)
{
  g[x][y] = type;
  color_cnt[type]--;
  if (!check(x, y))
  {
    g[x][y] = 0;
    color_cnt[type]++;
    return false;
  }
  for (int i = 1; i <= k; i++)
  {
    if (color_cnt[i] * 2 - 1 > n * m - cnt)
    {
      g[x][y] = 0;
      color_cnt[type]++;
      return false;
    }
  }
  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < m; j++)
  //     cout << g[i][j] << ' ';
  //   cout << endl;
  // }
  // cout << endl;
  if (cnt == n * m)
  {
    memcpy(ans, g, sizeof g);
    g[x][y] = 0;
    color_cnt[type]++;
    return true;
  }

  for (int i = 0; i < 4; i++)
  {
    int a = x + dxy[i][0], b = y + dxy[i][1];
    if (a < 0 || a >= n || b < 0 || b >= m || g[a][b])
      continue;
    for (int j = 1; j <= k; j++)
    {
      if (color_cnt[j])
      {
        if (dfs(a, b, j, cnt + 1))
        {
          g[x][y] = 0;
          color_cnt[type]++;
          return true;
        }
      }
    }
  }
  g[x][y] = 0;
  color_cnt[type]++;
  return false;
}

int main()
{
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int CC = 1; CC <= T; CC++)
  {
    flag = false;
    scanf("%d%d%d", &n, &m, &k);
    int maxv = -1;
    for (int i = 1; i <= k; i++)
    {
      scanf("%d", &color_cnt[i]);
      if (color_cnt[i] > maxv)
        maxv = color_cnt[i];
    }
    if (maxv * 2 - 1 > n * m)
    {
      printf("Case #%d:\nNO\n", CC);
      continue;
    }

    printf("Case #%d:\n", CC);
    for (int i = 1; i <= k; i++)
      if (dfs(0, 0, i, 1))
      {
        puts("YES");
        for (int a = 0; a < n; a++)
        {
          printf("%d", ans[a][0]);
          for (int b = 1; b < m; b++)
            printf(" %d", ans[a][b]);
          puts("");
        }
        flag = true;
        break;
      }
    if (!flag)
      puts("NO");
  }
  return 0;
}
