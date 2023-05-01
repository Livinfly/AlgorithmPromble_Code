#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110;

int n = 100, m;
int g[N][N];
bool d[N][N];

inline void dfs(int x, int y)
{
    if(d[x][y]) return;
    d[x][y] = true;
    for(int i = 1; i <= n; i ++)
        g[x][i] += g[y][i];
    for(int i = 1; i <= n; i ++)
        if(d[i][x]) dfs(i, y);
    for(int i = 1; i <= n; i ++)
        if(g[x][i] > 50) dfs(x, i);
}
inline void read_data()
{
	ios::sync_with_stdio(0);
	for(int i = 1; i <= n; i ++) d[i][i] = true;
	cin >> m;
	while(m --)
	{
		int a, b, c;
		cin >> a >> b >> c;
		for (int i = 1; i <= n; ++i) 
            if (d[i][a]) 
            {
                g[i][b] += c;
                if (g[i][b] > 50) dfs(i, b);
            }
	}
}
inline void solve()
{
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
		    if(i != j && d[i][j]) cout << i << ' ' << j << endl;
}

int main()
{
	read_data();
	solve();
	return 0;
}
