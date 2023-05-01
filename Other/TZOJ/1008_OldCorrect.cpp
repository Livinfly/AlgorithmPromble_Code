#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 5e4 + 10, M = 1e6 + 10;

int idx, h[N], ne[M], ver[M];
int n, m, cnt;
int fm[N], to[N];
bool st[N];

inline void add(int a, int b)
{
	ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
inline void dfs(int u, int fa)
{
	st[u] = true;
	for(int i = h[u]; ~i; i = ne[i])
	{
		int v = ver[i];
		if(st[v]) continue;
		dfs(v, u);
	}
	if(fa != -1) fm[++ cnt] = fa, to[cnt] = u;
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while(m --)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	dfs(1, -1);
    if(cnt != n - 1)
    {
    	cout << "Impossible!" << endl;
	}
	else
	{
		for(int i = 1; i <= cnt; i ++)
			cout << fm[i] << " -> " << to[i] << endl;
	}
    
    return 0;
}
