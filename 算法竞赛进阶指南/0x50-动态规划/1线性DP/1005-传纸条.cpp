#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 55;

int n, m;
int g[N][N], f[N<<1][N][N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	  for(int j = 1; j <= m; j ++)
	    cin >> g[i][j];
  memset(f, -0x3f, sizeof f);
  f[2][1][1] = 0;
	for(int i = 3; i <= n+m; i ++)
	  for(int x1 = 1; x1 < i; x1 ++)
	    for(int x2 = 1; x2 < i; x2 ++)
	    {
	      int &t = f[i][x1][x2];
	      int y1 = i-x1, y2 = i-x2;
	      t = max(t, f[i-1][x1][x2] + g[x1][y1-1] + g[x2][y2-1]);
	      t = max(t, f[i-1][x1][x2-1] + g[x1][y1-1] + g[x2-1][y2]);
	      t = max(t, f[i-1][x1-1][x2] + g[x1-1][y1] + g[x2][y2-1]);
	      t = max(t, f[i-1][x1-1][x2-1] + g[x1-1][y1] + g[x2-1][y2]);
	      if(x1 == x2) f[i][x1][x2] -= g[x1][y1];
	    }
  cout << f[n+m][n][n] << endl;
	return 0;
}
/*
https://www.acwing.com/activity/content/code/content/1671123/
*/