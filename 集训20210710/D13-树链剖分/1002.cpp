#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 4e4 + 10, M = N * 2, K = 16;

int idx, h[N], ne[M], ver[M], e[M];
int n, m;
int d[N], fa[N][K], dist[N]; // i号点 向上跳2^j所到达的祖先节点 

void add(int a, int b, int c)
{
	ver[idx] = b, e[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
void bfs()
{
	int q[N];
	int hh = 0, tt = 0;
	q[0] = 1, dist[1] = 0, d[1] = 1;
	
	while(hh <= tt)
	{
		int t = q[hh ++];
		for(int i = h[t]; ~i; i = ne[i])
		{
			int v = ver[i];
			if(d[v]) continue;
			d[v] = d[t] + 1; // mistake
			
			dist[v] = dist[t] + e[i];
			
			fa[v][0] = t;
			for(int k = 1; k < K; k ++)
				fa[v][k] = fa[fa[v][k - 1]][k - 1];
			q[++ tt] = v;
		}
	}
}
int lca(int x, int y)
{
	if(d[x] < d[y]) swap(x, y); // x在y下面
	for(int k = K - 1; k >= 0; k --) // x, y same, x在y 
		if(d[fa[x][k]] >= d[y]) x = fa[x][k];
	
	if(x == y) return x;
	
	for(int k = K - 1; k >= 0; k --) // 到lca的下一层 
		if(fa[x][k] != fa[y][k]) x = fa[x][k], y = fa[y][k];
	
	return fa[x][0];
}

int main()
{
	ios::sync_with_stdio(0);
//	freopen("data1.txt", "r", stdin);
	int T; cin >> T;
	while(T --)
	{
		idx = 0;
		memset(h, -1, sizeof h);
		memset(fa, 0, sizeof fa);
		memset(d, 0, sizeof d); 
		memset(dist, 0, sizeof dist);
		cin >> n >> m;
		
		for(int i = 0; i < n - 1; i ++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			add(a, b, c), add(b, a, c);
		}
		
		bfs();
		
		while(m --)
		{
			int a, b;
			cin >> a >> b;
			cout << dist[a] + dist[b] - 2 * dist[lca(a, b)] << endl;
		}
	}
    
    return 0;
}
