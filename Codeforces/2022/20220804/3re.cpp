
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

int m, res;
// MAX _ mx1 - (i,j)->(i,m-1), mx2 - (i,m-1)->(i,j) {j->y}
int a[2][N], mx1[2][N], mx2[2][N];

int main()
{
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  scanf("%d", &T);
  while (T--)
  {
    res = INF;
    scanf("%d", &m);
    for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < m; j++)
        scanf("%d", &a[i][j]);
      a[0][0] = -1; // on the (0,0) -> 0 for the line 45 mx1[x][y]
      mx1[i][m] = mx2[i][m] = -INF;
      for (int j = m - 1; j >= 0; j--)
      {
        mx1[i][j] = max(mx1[i][j + 1], a[i][j] + 1 + m - 1 - j);
        mx2[i][j] = max(mx2[i][j + 1], a[i][j] + 1 + j); // add "- y" (to go)
      }
    }
    int cur = 0, x = 0, y = 0, Tii = 0, res = INF;
    while (1)
    {
      if (!cur) // the other line is empty
      {
        int to_right = max(Tii + m - 1 - y, mx1[x][y]);
        res = min(res, max(to_right + m - 1 - y + 1, mx2[x ^ 1][y] - y));
        x ^= 1;
      }
      else
        y++;
      if (y == m)
        break;
      Tii = max(Tii + 1, a[x][y] + 1);
      cur ^= 1;
    }
    res = min(res, Tii);
    printf("%d\n", res);
  }
  return 0;
}