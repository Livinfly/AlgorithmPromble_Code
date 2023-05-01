#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110;

int n = 100, m;
int w[N][N];
bool d[N][N];

inline void dfs(int x, int y) // x �ع� y���ع� x �Ĺ�˾Ҫ���� y ���ֹ�Ʊ 
{
	if(d[x][y]) return; // ���¹����ع�x�Ĺ�˾�Ƿ��Ѿ���������y 
	d[x][y] = true;
	for(int i = 1; i <= n; i ++) w[x][i] += w[y][i];
	for(int i = 1; i <= n; i ++)
		if(d[i][x]) dfs(i, y); // �ֿ�д��x�عɵ���������棬i�عɵ������dfs��
	for(int i = 1; i <= n; i ++)
		if(w[x][i] > 50) dfs(x, i); // x�ع�i������ 
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
		for(int i = 1; i <= n; i ++) // �ع� a �Ĺ�˾ i Ҫ���� c (a Ҳ�ع� a)
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
