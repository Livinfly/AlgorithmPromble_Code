#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int N = 60, M = 1e4 + 10;

int idx, h[N], ne[M], ver[M], edge[M];
int n, cnt;
int g[N][N], dist[N];
bool st[N];
map<char, int> dic;
map<int, char> redic;

inline void init()
{
	memset(h, -1, sizeof h);
	memset(g, 0x3f, sizeof g);
	for(int i = 'a'; i <= 'z'; i ++) dic[(char)i] = ++ cnt, redic[cnt] = (char)i;
	for(int i = 'A'; i <= 'Z'; i ++) dic[(char)i] = ++ cnt, redic[cnt] = (char)i;
}
inline void read_data()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
	{
		char a, b;
		int c;
		scanf(" %c %c %d", &a, &b, &c);
		int x = dic[a], y = dic[b];
		g[x][y] = g[y][x] = min(g[x][y], c);
	}
}
inline void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	dist[dic['Z']] = 0;
	for(int i = 0; i < cnt; i ++)
	{
		int t = -1;
		for(int j = 1; j <= cnt; j ++)
			if(!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
		st[t] = true;
		for(int j = 1; j <= cnt; j ++)
			if(!st[j]) dist[j] = min(dist[j], dist[t] + g[t][j]);
	}
	
	char res = 'A';
	for(int i = 1; i <= cnt; i ++)
		if(redic[i] >= 'A' && redic[i] <= 'Y' && dist[dic[res]] > dist[i])
			 res = redic[i];
	cout << res << ' ' << dist[dic[res]] << endl;
}

int main()
{
	init();
	read_data();
	dijkstra();
	return 0;
}
