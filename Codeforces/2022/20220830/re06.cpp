#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int dxy[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};
char g[55][55];
bool vis[55][55];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  cin >> T; // scanf("%d", &T);
  while (T--)
  {
    memset(vis, 0, sizeof vis);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      cin >> g[i];
    bool flag = false;
    auto check = [&](int x, int y)
    {
      set<PII> s;
      for (int i = 0; i < 4; i++)
      {
        int j = (i + 1) % 4;
        int x1 = x + dxy[i][0], y1 = y + dxy[i][1];
        int x2 = x + dxy[j][0], y2 = y + dxy[j][1];
        if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)
          continue;
        if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)
          continue;
        if (g[x1][y1] == '*' && !vis[x1][y1] && g[x2][y2] == '*' && !vis[x2][y2])
        {
          vis[x][y] = vis[x1][y1] = vis[x2][y2] = true;
          s.insert({x, y});
          s.insert({x1, y1});
          s.insert({x2, y2});
          break;
        }
      }
      for (auto &p : s)
      {
        for (int i = -1; i <= 1; i++)
          for (int j = -1; j <= 1; j++)
          {
            if (!i && !j)
              continue;
            int x = p.first + i, y = p.second + j;
            if (x < 0 || x >= n || y < 0 || y >= m)
              continue;
            if (g[x][y] == '*' && s.find({x, y}) == s.end())
              return false;
          }
      }
      return true;
    };
    for (int i = 0; i < n; i++)
    {
      if (flag)
        break;
      for (int j = 0; j < m; j++)
        if (g[i][j] == '*' && !vis[i][j] && !check(i, j))
        {
          flag = true;
          break;
        }
    }
    for (int i = 0; i < n; i++)
    {
      if (flag)
        break;
      for (int j = 0; j < m; j++)
        if (g[i][j] == '*' && !vis[i][j])
        {
          flag = true;
          break;
        }
    }
    if (flag)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}