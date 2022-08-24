#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 210, M = N * 2, INF = 0x3f3f3f3f;

int idx, h[N], ne[M], e[M], f[M];
int n, m, S, T;
int q[N], d[N], cur[N];

inline void add(int a, int b, int c)
{
  e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++;
  e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx ++;
}
inline bool bfs()
{
  int hh = 0, tt = 0;
  memset(d, -1, sizeof d);
  q[0] = S, d[S] = 0, cur[S] = h[S];
  while(hh <= tt)
  {
    int t = q[hh ++];
    for(int i = h[t]; ~i; i = ne[i])
    {
      int v = e[i];
      if(d[v] == -1 && f[i])
      {
        d[v] = d[t] + 1;
        cur[v] = h[v];
        if(v == T) return true;
        q[++ tt] = v;
      }
    }
  }
  return false;
}
inline int find(int u, int limit)
{
  if(u == T) return limit;
  int flow = 0;
  for(int i = cur[u]; ~i && flow < limit; i = ne[i])
  {
    cur[u] = i;
    int v = e[i];
    if(d[v] == d[u] + 1 && f[i])
    {
      int t = find(v, min(f[i], limit - flow));
      if(!t) d[t] = -1;
      f[i] -= t, f[i^1] += t, flow += t;
    }
  }
  return flow;
}
inline int dinic()
{
  int r = 0, flow;
  while(bfs()) 
    while(flow = find(S, INF))
      r += flow;
  return r;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	S = 1, T = n;
	memset(h, -1, sizeof h);
	while(m --)
	{
	  int a, b, c;
	  cin >> a >> b >> c;
	  add(a, b, c);
	}
	cout << dinic() << endl;
	return 0;
}