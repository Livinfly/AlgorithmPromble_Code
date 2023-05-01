#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 17, M = 1 << N;

int n;
int a[N], p[N], ones[M];
LL f[M][N]; // i��ʾȷ����λ���˵ı�ţ�j��ʾĿǰ���һλ��˭ 

void init()
{
	memset(f, -0x3f, sizeof f); // f�����Ǹ��ģ�Ҫ��ʼ��Ϊ-INF 
}

int main()
{
	for(int i = 0; i < 1 << 17; i ++) 
		ones[i] = ones[i >> 1] + (i & 1);
	int T; scanf("%d", &T);
	for(int Case = 1; Case <= T; Case ++)
	{
		init();
		scanf("%d", &n);
		for(int i = 0; i < n; i ++) scanf("%d%d", &a[i], &p[i]);
		
		for(int i = 0; i < n; i ++) 
			if(p[i] == -1 || p[i] == 0) f[1 << i][i] = 0;
		
		for(int i = 0; i < 1 << n; i ++) // ״̬ 
			for(int j = 0; j < n; j ++)	// ĩλ 
				if(f[i][j] >= -1e18) // ��ǰ״̬�Ϸ� (��ʼ��Ϊf[][] = -4e18)
					for(int k = 0; k < n; k ++) // ö����һ���˷�˭ 
						if(((i >> k & 1) == 0) && (p[k] == -1 || ones[i] == p[k])) // 1. �����û���Ź� 2. λ�ÿ��� 
							f[i + (1 << k)][k] = max(f[i + (1 << k)][k], f[i][j] + a[j] * a[k]);
		LL res = -1e18;
		for(int i = 0; i < n; i ++) // ������ĩλ1~n���п��� 
			res = max(res, f[(1 << n) - 1][i]);
		
		printf("Case #%d:\n", Case);
		printf("%lld\n", res);
	}
	
	return 0;
}
