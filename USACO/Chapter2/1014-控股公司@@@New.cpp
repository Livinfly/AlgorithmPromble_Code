#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110;

int n = 100, m;
int w[N][N];
bool d[N][N];

inline void dfs(int x, int y) // x 控股 y，控股 x 的公司要加上 y 所持股票 
{
	if(d[x][y]) return; // 更新过，控股x的公司是否已经都加上了y 
	d[x][y] = true;
	for(int i = 1; i <= n; i ++) w[x][i] += w[y][i];
	for(int i = 1; i <= n; i ++)
		if(d[i][x]) dfs(i, y); // 分开写，x控股的情况在下面，i控股的情况在dfs里
	for(int i = 1; i <= n; i ++)
		if(w[x][i] > 50) dfs(x, i); // x控股i，更新 
}

int main()
{
	ios::sync_with_stdio(0);
	for(int i = 1; i <= n; i ++) d[i][i] = true;
	cin >> m;
	while(m --)
	{
		int a, b, c;
		cin >> a >> b >> c;
		for(int i = 1; i <= n; i ++) // 控股 a 的公司 i 要加上 c (a 也控股 a)
		{
			if(d[i][a])
			{
				w[i][b] += c;
				if(w[i][b] > 50) dfs(i, b);
			}
		}
	}
	
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			if(i != j && d[i][j]) cout << i << ' ' << j << endl;
	
	return 0;
}
