#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e4 + 10, M = 2e4 + 10;

int idx, h[N], ne[M], ver[M];
int n, m;
int ind[N], w[N];
int q[N];

void add(int a, int b)
{
	ind[b] ++, ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int topo_sort()
{
	int hh = 0, tt = -1;
	for(int i = 1; i <= n; i ++)
		if(!ind[i])
		{
			w[i] = 888;
			q[++ tt] = i;
		}
	
	while(hh <= tt)
	{
		int t = q[hh ++];
		
		for(int i = h[t]; ~i; i = ne[i])
		{
			int v = ver[i];
			if(-- ind[v] == 0) 
			{
				w[v] = w[t] + 1;
				q[++ tt] = v;
			}
		}
	}
	
	int res = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(ind[i]) return -1;
		res += w[i];
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	while(cin >> n >> m)
	{
		memset(h, -1, sizeof h);
		memset(ind, 0, sizeof ind); // forget
		idx = 0; // forget
		while(m --)
		{
			int a, b;
			cin >> a >> b;
			add(b, a);
		}
		
		cout << topo_sort() << endl;
	}
    
    return 0;
}
