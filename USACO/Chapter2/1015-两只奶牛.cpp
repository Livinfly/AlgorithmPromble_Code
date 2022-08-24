#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 12;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int n = 10, jx, jy, cx, cy;
char g[N][N];
bool st[N][N][4][N][N][4];
struct rec
{
	int x1, y1, d1;
	int x2, y2, d2;
	int cnt;
};


inline int bfs()
{
	queue<rec> q;
	rec t = (rec){jx, jy, 0, cx, cy, 0, 0};
	q.push(t);
	while(q.size())
	{
		t = q.front(); q.pop();
		if(st[t.x1][t.y1][t.d1][t.x2][t.y2][t.d2]) continue;
		st[t.x1][t.y1][t.d1][t.x2][t.y2][t.d2] = true;
		if(t.x1 == t.x2 && t.y1 == t.y2) return t.cnt;
		
		int a1 = t.x1 + dx[t.d1], b1 = t.y1 + dy[t.d1],
			a2 = t.x2 + dx[t.d2], b2 = t.y2 + dy[t.d2];
		if(g[a1][b1] == '*' || a1 < 0 || a1 >= n || b1 < 0 || b1 >= n)
		{
			t.d1 = (t.d1 + 1) % 4;
		}
		else t.x1 = a1, t.y1 = b1;
		if(g[a2][b2] == '*' || a2 < 0 || a2 >= n || b2 < 0 || b2 >= n)
		{
			t.d2 = (t.d2 + 1) % 4;
		}
		else t.x2 = a2, t.y2 = b2;
		t.cnt ++;
		q.push(t);
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for(int i = 0; i < n; i ++) cin >> g[i];
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			if(g[i][j] == 'F') jx = i, jy = j;
			else if(g[i][j] == 'C') cx = i, cy = j;
	
	cout << bfs() << endl;
	
	return 0;
}
