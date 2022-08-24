#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

const int M = 110, N = 210, INF = 0x3f3f3f3f;

int n, m;
int fa[N], g[N][N], d[N][N];
struct rec
{
  int c;
  vector<int> a[2];
} e[M];

inline int get_fa(int x)
{
  if(x == fa[x]) return x;
  return fa[x] = get_fa(fa[x]);
}
inline int get_point(int a, int b)
{
  for(int i = 0; i < 2; i ++)
    for(int j = 0; j < e[a].a[i].size(); j ++)
      if(e[a].a[i][j] == b) return a + m * i;
  return -1;
}
inline void data_read()
{
  cin >> m;
	n = m * 2;
	for(int i = 0; i < m; i ++)
	{
	  int a, b, cnt1, cnt2;
	  cin >> a;
	  cin >> e[a].c >> cnt1 >> cnt2;
	  while(cnt1 --)
	  {
	    cin >> b;
	    e[a].a[0].push_back(b);
	  }
	  while(cnt2 --)
	  {
	    cin >> b;
	    e[a].a[1].push_back(b);
	  }
	}
	for(int i = 1; i <= n; i ++) fa[i] = i;
	for(int i = 1; i <= m; i ++)
	  for(int j = 0; j < 2; j ++)
	    for(int k = 0; k < e[i].a[j].size(); k ++)
	    {
	      int p = e[i].a[j][k];
	      int a = i + m * j, b = get_point(p, i);
	      fa[get_fa(a)] = get_fa(b); // forget
	    }
}
inline void solve()
{
  memset(g, 0x3f, sizeof g);
  for(int i = 1; i <= n; i ++) g[i][i] = 0;
  for(int i = 1; i <= m; i ++)
  {
    int a = get_fa(i), b = get_fa(i + m);
    g[a][b] = g[b][a] = e[i].c;
  }
  memcpy(d, g, sizeof d);
  int res = INF;
  for(int k = 1; k <= n; k ++)
  {
    for(int i = 1; i < k; i ++)
      for(int j = i+1; j < k; j ++)
        res = min((LL)res, (LL)d[i][j] + g[i][k] + g[j][k]);
    for(int i = 1; i <= n; i ++)
      for(int j = 1; j <= n; j ++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  }
  cout << res << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	data_read();
	solve();
	return 0;
}