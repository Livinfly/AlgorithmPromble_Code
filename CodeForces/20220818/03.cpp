#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 510;

int dxy[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}; // rdlu
int n, m;
char g[N][N];

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
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      cin >> g[i];
    int cnt = 0, mn = 3;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
      {
        if (g[i][j] == '1')
          cnt++;
        for (int k = 0; k < 4; k++)
        {
          int l = (k + 1) % 4;
          int a1 = i + dxy[k][0], b1 = j + dxy[k][1];
          int a2 = i + dxy[l][0], b2 = j + dxy[l][1];
          if (a1 < 0 || a1 >= n || b1 < 0 || b1 >= m)
            continue;
          if (a2 < 0 || a2 >= n || b2 < 0 || b2 >= m)
            continue;
          int t = g[i][j] - '0' + g[a1][b1] - '0' + g[a2][b2] - '0';
          mn = max(min(mn, t), 1);
        }
      }
    cout << cnt - mn + 1 << '\n';
  }
  return 0;
}