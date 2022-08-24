#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 35, M = 5010;

struct rec
{
  int i, j;
} pre[N][M];
int n, m;
int g[N], c[N], s[N], f[N][M], ans[N];

inline bool cmp(const int &a, const int &b)
{
  return g[a] > g[b];
}
inline void Schprint(rec t)
{
  if(!t.i) return;
  Schprint(pre[t.i][t.j]);
  if(pre[t.i][t.j].i == t.i) // 操作为集体减1
  {
    for(int i = 1; i <= n; i ++) ans[c[i]] ++;
  }
  else // 操作为从k->i是1
  {
    for(int i = pre[t.i][t.j].i+1; i <= n; i ++) ans[c[i]] = 1;
  }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) 
	{
	  cin >> g[i];
	  c[i] = i;
	}
	sort(c+1, c+n+1, cmp);
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	for(int i = 1; i <= n; i ++)
	{
	  s[i] = s[i-1] + g[c[i]];
	  for(int j = i; j <= m; j ++)
	  {
	    f[i][j] = f[i][j-i];
	    pre[i][j] = (rec){i, j-i};
	    for(int k = 0; k < i; k ++)
	      if(f[i][j] > f[k][j-(i-k)] + (s[i]-s[k])*k)
	      {
	        f[i][j] = f[k][j-(i-k)] + (s[i]-s[k])*k;
	        pre[i][j] = (rec){k, j-(i-k)};
	      }
	  }
	}
	Schprint((rec){n, m});
	cout << f[n][m] << endl;
	for(int i = 1; i <= n; i ++) cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
/*
https://www.acwing.com/activity/content/code/content/1679211/
*/