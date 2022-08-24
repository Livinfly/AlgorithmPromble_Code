#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 210, M = 1010, INF = 0x3f3f3f3f;

int n, m;
int a[M], g[N][N], f[2][N][N];

int main()
{
  ios::sync_with_stdio(0);
	cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i ++)
    for(int j = 1; j <= n; j ++)
      cin >> g[i][j];
  a[0] = 3;
  for(int i = 1; i <= m; i ++) cin >> a[i];
  memset(f, 0x3f, sizeof f);
  f[0][1][2] = 0;
  int cur = 0;
  for(int i = 1; i <= m; i ++)
  {
    cur ^= 1;
    int z = a[i-1];
    for(int x = 1; x <= n; x ++)
      for(int y = 1; y <= n; y ++)
      {
        if(f[cur^1][x][y] != INF)
        {
          int t = f[cur^1][x][y];
          if(y != a[i] && z != a[i]) f[cur][y][z] = min(f[cur][y][z], t + g[x][a[i]]);
          if(x != a[i] && z != a[i]) f[cur][x][z] = min(f[cur][x][z], t + g[y][a[i]]);
          if(x != a[i] && y != a[i]) f[cur][x][y] = min(f[cur][x][y], t + g[z][a[i]]);
          f[cur^1][x][y] = INF;
        }
      }
  }
  int res = INF;
  for(int x = 1; x <= n; x ++)
      for(int y = 1; y <= n; y ++)
        res = min(res, f[cur][x][y]);
  cout << res << endl;
  return 0;
}

/*
https://www.acwing.com/activity/content/code/content/1667975/
*/