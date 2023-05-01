#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int N = 510, M = N * N;

int idx, h[N], ne[M], ver[M];
int n, m;
int ind[N];
priority_queue<int, vector<int>, greater<int> > heap;
vector<int> ans;

void add(int a, int b)
{
	ind[b] ++, ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void topo_sort()
{
	for(int i = 1; i <= n; i ++)
		if(!ind[i]) heap.push(i);
	while(heap.size())
	{
		int t = heap.top(); heap.pop();
		ans.push_back(t);
		for(int i = h[t]; ~i; i = ne[i])
		{
			int v = ver[i];
			if(-- ind[v] == 0) heap.push(v);
		}
	}
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(h, -1, sizeof h);
		memset(ind, 0, sizeof ind);
		ans.clear();
		idx = 0; // forget
		while(m --)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			add(a, b);
		}
		
		topo_sort();
		
		printf("%d", ans[0]);
		for(int i = 1; i < ans.size(); i ++)
			printf(" %d", ans[i]);
		puts("");
	}
	
	return 0;
}
/*

if(!g[i][j]) g[i][j] = 1, ind[j] ++;

ÎªÁË±ÜÃâ...
*/
