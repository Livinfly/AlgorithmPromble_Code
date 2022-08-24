#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10, M = 4e5 + 10;

int idx, h[N], ne[M], ver[M];
int n, m, maxn, S, E;
int col[N], rec[N], dist[N];
bool st[N];
deque<PII> q;

void add(int a, int b)
{
	ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int bfs()
{
	memset(dist, 0x3f, sizeof dist);
	memset(rec, 0x3f, sizeof rec);
	dist[S] = 1, rec[S] = 1, st[S] = true;
	q.push_back(make_pair(1, S));
	
	while(q.size())
	{
		PII t = q.front(); q.pop_front();
		int d = t.x, u = t.y;
		st[u] = false;
		if(d > dist[u]) continue;
		if(u == E) return dist[E];
		for(int i = h[u]; ~i; i = ne[i])
		{
			int v = ver[i];
			if(dist[v] > dist[u])
			{
				if(col[u] == col[v])
				{
					if(rec[u] < maxn)
					{
						dist[v] = dist[u];
						rec[v] = rec[u] + 1;
						q.push_front(make_pair(dist[v], v));
						st[v] = true;
					}
					else
					{
						dist[v] = dist[u] + 1;
						rec[v] = 1;
						if(!st[v]) 
						{
							q.push_back(make_pair(dist[v], v));
							st[v] = true;
						}
						
					}
				}
				else
				{
					dist[v] = dist[u] + 1;
					rec[v] = 1;
					if(!st[v]) 
					{
						q.push_back(make_pair(dist[v], v));
						st[v] = true;
					}
				}
			}
			else if(dist[v] == dist[u])
			{
				if(col[u] == col[v])
				{
					if(rec[v] > rec[u] + 1)
					{
						rec[v] = rec[u] + 1;
						q.push_front(make_pair(dist[v], v));
						st[v] = true;
					}
				}
			}
		}
	}
	
	if(dist[E] == 0x3f3f3f3f) return -1;
	else return dist[E];
}

int main()
{
	memset(h, -1, sizeof h);
	scanf("%d%d%d%d%d", &n, &m, &maxn, &S, &E);
	for(int i = 1; i <= n; i ++) scanf("%d", &col[i]);
	while(m --)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
	}
	
	cout << bfs() << endl;
	
//	for(int i = 1; i <= n; i ++)
//		cout << dist[i] << ' ';
//	cout << endl;
	
	return 0;
}
