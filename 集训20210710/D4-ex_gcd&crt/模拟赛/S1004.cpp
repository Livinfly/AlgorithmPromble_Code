#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 4e5 + 10;

int idx, h[N], ne[M], ver[M];
int n, m, maxn, S, E;
int col[N], f[N];
bool st[N];

void add(int a, int b)
{
	ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void lt(int u)
{
	for(int i = h[u]; ~i; i = ne[i])
	{
		int v = ver[i];
		if(!st[v]) 
		{
			st[v] = true;
			lt(v);
		}
		else continue;
	}
}
void dfs(int u, int step)
{
	if(u == E) return;
	for(int i = h[u]; ~i; i = ne[i])
	{
		int v = ver[i];
		if(f[v] <= f[u]) continue;
		if(col[u] == col[v])
		{
			if(step > maxn)
			{
				f[v] = min(f[v], f[u] + 1);
				dfs(v, 1);
			}
			else
			{
				f[v] = min(f[v], f[u]);
				dfs(v, step + 1);
			}
		}
		else
		{
			f[v] = min(f[v], f[u] + 1);
			dfs(v, 1);
		}
	}
}

int main()
{
	memset(h, -1, sizeof h);
	memset(f, 0x3f, sizeof f);
	scanf("%d%d%d%d%d", &n, &m, &maxn, &S, &E);
	for(int i = 1; i <= n; i ++) scanf("%d", &col[i]);
	while(m --)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
	}
	st[S] = true;
	lt(S);
	if(!st[E])
	{
		cout << -1 << endl;
		return 0;
	}
	
	f[S] = 1;
	dfs(S, 1);
	
//	for(int i = 1; i <= n; i ++)
//		cout << f[i] << endl;
//	cout << endl;
	
	if(f[E] == 0x3f3f3f3f) cout << -1 << endl;
	else cout << f[E] << endl;
	
	
	return 0;
}
