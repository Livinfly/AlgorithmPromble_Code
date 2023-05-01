#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 12;

int n, res;
int to1[N], to2[N]; // to1 - ����ߣ� to2 - ����� 
bool st[N]; // �������
bool used[N][2], in_stk[N][2];
struct Point
{
	int x, y;
	bool operator < (const Point &o) const // ������to1 
	{
		if(y != o.y) return y < o.y;
		return x < o.x;
	}
} p[N];


bool circle(int a, int b)
{
	if(in_stk[a][b]) return true;
	if(used[a][b]) return false; // ��!in_stk�������
	
	in_stk[a][b] = used[a][b] = true; // forget 
	bool flag = false;
	if(!b) // ��� 
	{
		if(circle(to2[a], 1)) flag = true;
	}
	else // ���� 
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
void dfs(int x) // x������� 
{
	if(x == n / 2)
	{
		if(check()) res ++;
		return;
	}
 // Ѱ�ҵ�һ��û�б���Եĳ涴�ͺ����ĸ���ԣ���Ϊ��һ��û����Ե�һ��Ҫ��� ���Է��������break�� 
	for(int i = 0; i < n; i ++)
	{
		if(st[i]) continue;
		for(int j = i + 1; j < n; j ++) // ���ظ�ö�� 
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
1. ����ö����Է�ʽ 
2. �ж���û�л� 
*/
