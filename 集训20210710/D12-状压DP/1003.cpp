#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 17, M = 1 << N, P = 1e9 + 7;

int n, m, cur;
int p[N];
LL f[2][M];
/*
������DP 
f[i][S] ��i�� S״̬�ķ�����
����/����/���� 
*/
void prev_calu()
{
	for(int i = 1, j = 1; i < N; i ++, j *= 2) p[i] = j;
}

int main()
{
	prev_calu(); 
	int T; scanf("%d", &T);
	while(T --)
	{
		memset(f, 0, sizeof f);
		scanf("%d%d", &n, &m);
		if(n < m) swap(n, m);
		f[0][(1 << m) - 1] = 1; // ��0����������Ϊ��һ�в���������
		cur = 0; // �������� 
		for(int i = 0; i < n; i ++) // ö�ٵ�i��
			for(int j = 1; j <= m; j ++) // ��ǰ�ڲ��������� 
			{
				cur ^= 1; // ���������� !!!???
				memset(f[cur], 0, sizeof f[cur]);
				for(int S = 0; S < 1 << m; S ++) // i - 1�е�״̬ 
				{
					// ������ 1. ��һ��û���� 2. i > 0 
					if((S & p[j]) == 0 && i > 0) f[cur][S | p[j]] = (f[cur][S | p[j]] + f[cur ^ 1][S]) % P;
					// ������ 1. ��һ������ 2. ��һ��������� 3. j > 0
					if((S & p[j]) && (S & p[j - 1]) == 0 && j > 1) f[cur][S | p[j - 1]] = (f[cur][S | p[j - 1]] + f[cur ^ 1][S]) % P;
					// ���� 1. ��һ������
					if(S & p[j]) f[cur][S ^ p[j]] = (f[cur][S ^ p[j]] + f[cur ^ 1][S]) % P;
				}
			}
		printf("%lld\n", f[cur][(1 << m) - 1] % P);
	}
	
	return 0;
}
