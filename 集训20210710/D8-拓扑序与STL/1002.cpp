#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e4 + 10, M = 2e4 + 10;

int idx, h[N], ind[N], ne[M], ver[M];
int n, m;
int w[N];
queue<int> q;

void add(int a, int b)
{
	ind[b] ++, ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int topo_sort()
{
	for(int i = 1; i <= n; i ++)
		if(!ind[i])
		{
			q.push(i);
			w[i] = 888;
		}
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		for(int i = h[t]; ~i; i = ne[i])
		{
			int v = ver[i];
			if(-- ind[v] == 0) 
			{
				w[v] = w[t] + 1;
				q.push(v);
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
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(h, -1, sizeof h);
		memset(ind, 0, sizeof ind);
		memset(w, 0, sizeof w);
		idx = 0; // forget
		while(m --)
		{
			int a, b;
			scanf("%d%d", &a, &b); // a > b
			add(b, a);
		}
		
		printf("%d\n", topo_sort());
	}
	
	return 0;
}
