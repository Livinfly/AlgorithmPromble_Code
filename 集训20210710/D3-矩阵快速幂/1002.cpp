#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 11;

int n, P;
struct Matrix
{
	int line, row; // ÐÐ/ÁÐ 
	int m[N][N];
} m, m_init;

Matrix operator * (const Matrix &a, const Matrix &b)
{
	Matrix res;
	res.line = a.line, res.row = b.row;
	int t;
	for(int i = 0; i < a.line; i ++)
		for(int j = 0; j < b.row; j ++)
		{
			t = 0;
			for(int k = 0; k < a.row; k ++)
				t = (t + a.m[i][k] * b.m[k][j]) % P;
			res.m[i][j] = t;
		}
	return res;
}

void init()
{
	for(int i = 0; i < N; i ++) m_init.m[i][i] = 1;
}
int f(int x)
{
	Matrix ans;
	for(int i = 0; i < 10; i ++)
		for(int j = 0; j < 10; j ++)
			ans.m[i][j] = 0;
	ans.line = 1, ans.row = 10;
	for(int i = 0; i < 10; i ++) ans.m[i][0] = 9 - i;
	
	int b = x;
	while(b)
	{
		if(b & 1) ans = m * ans;
		m = m * m;
		b >>= 1;
	}
	return ans.m[9][0];
}



int main()
{
	init();
	while(cin >> n >> P)
	{
		for(int i = 0; i < 10; i ++)
			for(int j = 0; j < 10; j ++)
				m.m[i][j] = 0;
		m.line = m.row = 10;
		for(int i = 0; i < 10; i ++) scanf("%d", &m.m[0][i]);
		for(int i = 1; i < 10; i ++) m.m[i][i - 1] = 1;
		
		cout << f(n) << endl;
	}
	
	return 0;
}
