#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 210;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n, m, x1, y1, x2, y2;
int dist[N][N];
PII pos[2];
string g[N];
bool st[N][N];
queue<PII> q;

int bfs()
{
	memset(dist, 0x3f, sizeof dist);
	for(int i = 0; i < 2; i ++)
	{
		memset(st, 0, sizeof st);
		q.push(pos[i]);
		dist[pos[i].x][pos[i].y] = 1;
		while(q.size())
		{
			PII t = q.front(); q.pop();
			st[t.x][t.y] = true;
			for(int i = 0; i < 4; i ++)
			{
				int a = t.x + dx[i], b = t.y + dy[i];
				int a1 = t.x + dx[i] * 2, b1 = t.y + dy[i] * 2;
				if(st[a1][b1]) continue;
				if(a1 < 0 || a1 >= n || b1 < 0 || b1 >= m) continue;
				if(g[a][b] == ' ' && g[a1][b1] == ' ') 
				{
					if(dist[a1][b1] > dist[t.x][t.y] + 1)
					{
						dist[a1][b1] = dist[t.x][t.y] + 1;
						q.push(make_pair(a1, b1));
					}
				}
			}
		}
	}
//	for(int i = 0; i < n; i ++)
//	{
//	    for(int j = 0; j < m; j ++)
//	        cout << dist[i][j] << ' ';
//	    cout << endl;
//	}
	int res = 0;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			if(dist[i][j] != dist[0][0]) 
			    res = max(res, dist[i][j]);
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> m >> n;
	n = n * 2 + 1, m = m * 2 + 1;
	getline(cin, g[0]); // space
	for(int i = 0; i < n; i ++) getline(cin, g[i]);
	int t = 0;
	for(int i = 0; i < n; i ++) // row 0...push 1 move
		if(g[i][0] == ' ') pos[t ++] = make_pair(i, 1);
	for(int i = 0; i < m; i ++) // line 0
		if(g[0][i] == ' ') pos[t ++] = make_pair(1, i);
	for(int i = 0; i < n; i ++) // row m-1
		if(g[i][m - 1] == ' ') pos[t ++] = make_pair(i, m - 2);
	for(int i = 0; i < m; i ++) // line n - 1 | n -> m
		if(g[n - 1][i] == ' ') pos[t ++] = make_pair(n - 2, i);
	
	cout << bfs() << endl;
	
	return 0;
}
