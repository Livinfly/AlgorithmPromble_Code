#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 1e4 + 10, M = 5e5 + 10;

int idx, h[N], ne[M], ver[M], e[M];
int n, m, A, Z;
int w[N], ind[N], rind[N];
LL f[N], g[N];

inline void add(int h[], int a, int b, int c)
{
	ver[idx] = b, e[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
inline LL bfs()
{
	memset(f, 0x3f, sizeof f);
//	memset(g, 0x3f, sizeof g);
	f[A] = w[A];
	queue<int> q;
	for(int i = 1; i <= n; i ++)
		if(!ind[i]) q.push(i);
	while(q.size())
	{
		int t = q.front(); q.pop();
		for(int i = h[t]; ~i; i = ne[i])
		{
			int v = ver[i];
			if(v == Z || w[v] <= 0) f[v] = min(f[v], f[t] + e[i] + w[v]);
			else f[v] = min(f[v], f[t] + e[i]);
			if(-- ind[v] == 0) q.push(v);
		}
	}
	
//	for(int i = 1; i <= n; i ++)
//		if(!rind[i]) q.push(i);
//	while(q.size())
//	{
//		int t = q.front(); q.pop();
//		for(int i = rh[t]; ~i; i = ne[i])
//		{
//			int v = ver[i];
//			g[v] = min(g[v], g[t] + e[i] + w[v]);
//			if(-- rind[v] == 0) q.push(v);
//		}
//	}
	
	return f[Z];
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(h, -1, sizeof h);
//	memset(rh, -1, sizeof rh);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++)
	{
		int a; cin >> a;
		w[i] -= a;
	}
	while(m --)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(h, a, b, c); ind[b] ++;
//		add(rh, b, a, c); rind[a] ++;
	}
    cin >> A >> Z;
    cout << bfs() << endl;
    
    return 0;
}
