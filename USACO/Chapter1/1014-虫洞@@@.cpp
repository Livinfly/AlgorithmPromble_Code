#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 12;

int n, res;
int to1[N], to2[N]; // to1 - 单向边， to2 - 无向边 
bool st[N]; // 有无配对
bool used[N][2], in_stk[N][2];
struct Point
{
	int x, y;
	bool operator < (const Point &o) const // 方便求to1 
	{
		if(y != o.y) return y < o.y;
		return x < o.x;
	}
} p[N];


bool circle(int a, int b)
{
	if(in_stk[a][b]) return true;
	if(used[a][b]) return false; // 在!in_stk的情况下
	
	in_stk[a][b] = used[a][b] = true; // forget 
	bool flag = false;
	if(!b) // 入点 
	{
		if(circle(to2[a], 1)) flag = true;
	}
	else // 出点 
	{
		if(to1[a] != -1 && circle(to1[a], 0)) flag = true;
	}
	
	in_stk[a][b] = false;
	return flag;
}
bool check()
{
	memset(used, 0, sizeof used); // forget
	memset(in_stk, 0, sizeof in_stk); // forget
	
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < 2; j ++) // in_ver, out_ver 
			if(!used[i][j])
				if(circle(i, j)) return true;
	return false;
}
void dfs(int x) // x组配对完 
{
	if(x == n / 2)
	{
		if(check()) res ++;
		return;
	}
 // 寻找第一个没有被配对的虫洞和后面哪个配对，因为第一个没有配对的一定要配对 所以方案找完就break； 
	for(int i = 0; i < n; i ++)
	{
		if(st[i]) continue;
		for(int j = i + 1; j < n; j ++) // 不重复枚举 
		{
			if(st[j]) continue;
			st[i] = st[j] = true; // mark
			to2[i] = j, to2[j] = i; // edge
			dfs(x + 1);
			to2[i] = to2[j] = -1;
			st[i] = st[j] = false; // recover
			
		}
		break;
	}
}


int main()
{
	memset(to1, -1, sizeof to1);
	memset(to2, -1, sizeof to2);
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> p[i].x >> p[i].y;
	sort(p, p + n);
	for(int i = 1; i < n; i ++)
		if(p[i].y == p[i - 1].y) to1[i - 1] = i;
	
//	for(int i = 0; i < n; i ++) cout << to1[i] << endl;
	
	dfs(0);
	
	cout << res << endl;
	
	return 0;
}
/*
1. 搜索枚举配对方式 
2. 判断有没有环 
*/
