#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1010;

int n, res;
int a[N], b[N], g[N][N];

int main()
{ 
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	memcpy(b, a, sizeof b);
	sort(b + 1, b + n + 1);
	
	for(int i = 1; i <= n; i ++) g[a[i]][b[i]] ++;
	
	int cnt = 0; // circle
	for(int i = 1; i <= 3; i ++) cnt += g[i][i], g[i][i] = 0; // self_circle
	for(int i = 1; i <= 3; i ++)
		for(int j = i + 1; j <= 3; j ++) // 2node_circle
		{
			int t = min(g[i][j], g[j][i]);
			cnt += t;
			g[i][j] -= t;
			g[j][i] -= t;
		}
	cnt += g[1][2] + g[2][1]; // 3node_circle		
	
	
	cout << n - cnt << endl;
	
	return 0;
}
/*
先要把题意理解清楚，然后进行分析
根据图3，发现n个数回到自己的位置当且仅当图中存在n个环
一共只有三种环，自环，2环，3环
当我们边加边减时，最后的任意一点的度数就是3环的个数 
*/
