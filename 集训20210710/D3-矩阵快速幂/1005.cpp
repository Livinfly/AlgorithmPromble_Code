#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 4, P = 1e9 + 7;

int l, r;
struct Matrix 
{
	LL m[N][N];
} m_init, m_ept;

Matrix operator * (const Matrix &a, const Matrix &b)
{
	Matrix res = m_ept;
	for(int i = 0; i < N; i ++)
		for(int j = 0; j < N; j ++)
			for(int k = 0; k < N; k ++)
				res.m[i][j] = (res.m[i][j] + ((a.m[i][k] % P) * (b.m[k][j] % P)) % P) % P;
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
int work(int n)
{
	if(n < 0) return 0;
//	if(n < 3) return n + 1;
	Matrix ans, m;
	ans = m = m_ept;
	ans.m[0][0] = 3, ans.m[1][0] = 1, ans.m[2][0] = 1, 
		ans.m[3][0] = 1;
	
	for(int i = 0; i < N; i ++) m.m[0][i] = 1;
	for(int i = 1; i < N; i ++) m.m[1][i] = 1;
	m.m[2][1] = 1, m.m[3][2] = 1;
	
	int b = n - 2;
	while(b)
	{
		if(b & 1) ans = m * ans;
		m = m * m;
		b >>= 1;
	}
	
	return ans.m[0][0];
}

int main()
{
	init();
	while(cin >> l >> r)
	{
		cout << (work(r) - work(l - 1) + P) % P << endl;
	}
	
	return 0;
}
