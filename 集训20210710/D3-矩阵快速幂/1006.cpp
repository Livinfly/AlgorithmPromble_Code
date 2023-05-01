#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 4, P = 1e4 + 7;

int n, x, y;
struct Matrix
{
	int m[N][N];
} m, m_init, m_ept;

Matrix operator * (const Matrix &a, const Matrix &b)
{
	Matrix res;
	int t;
	for(int i = 0; i < N; i ++)
		for(int j = 0; j < N; j ++)
		{
			t = 0;
			for(int k = 0; k < N; k ++)
				t = (t + a.m[i][k] * b.m[k][j]) % P;
			res.m[i][j] = t;
		}
	return res;
}

void init()
{
	for(int i = 0; i < N; i ++) 
		for(int j = 0; j < N; j ++)
			m_ept.m[i][j] = 0;
	m_init = m_ept;
	for(int i = 0; i < N; i ++) m_init.m[i][i] = 1;
}
void work(int n)
{
	Matrix ans;
	ans = m_ept;
	ans.m[0][0] = 2;
	ans.m[1][0] = 1;
	ans.m[2][0] = 1;
	ans.m[3][0] = 1;
	
	m = m_ept;
	m.m[0][0] = 1, m.m[0][1] = x * x % P, m.m[0][2] = y * y % P, m.m[0][3] = 2 * x * y % P;
	m.m[1][1] = x * x % P, m.m[1][2] = y * y % P, m.m[1][3] = 2 * x * y % P;
	m.m[2][1] = 1;
	m.m[3][1] = x, m.m[3][3] = y;
	
	int b = n - 1;
	while(b)
	{
		if(b & 1) ans = m * ans;
		m = m * m;
		b >>= 1;
	}
	cout << ans.m[0][0] << endl;
}

int main()
{
	init();
	while(scanf("%d%d%d", &n, &x, &y) == 3)
	{
		x %= P, y %= P;
		work(n);
	}
	
	return 0;
}
//Sn 1 x^2 y^2 2 * x * y
//An 0 x^2 y^2 2 * x * y
//An-1 ^ 2 0 1 0 0
//An * An-1 0 x 0 y
