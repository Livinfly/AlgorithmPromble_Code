// 2021/07/13
// Luogu P2679 - NOIP2015S �Ӵ� - ioj 
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1010, M = 210, P = 1e9 + 7;

int n, m, K;
int f[2][M][M][2];
char s1[N], s2[M];

int main()
{
	cin >> n >> m >> K;
	scanf("%s%s", s1 + 1, s2 + 1);
	
	f[0][0][0][0] = f[1][0][0][0] = 1;
//	for(int i = 0; i <= n; i ++) f[i][0][0][0] = 1;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			for(int k = 1; k <= K; k ++)
			{
				if(s1[i] == s2[j])
				{
					f[i & 1][j][k][1] = ((LL)f[i - 1 & 1][j - 1][k][1] + f[i - 1 & 1][j - 1][k - 1][1] + f[i - 1 & 1][j - 1][k - 1][0]) % P;
					f[i & 1][j][k][0] = ((LL)f[i - 1 & 1][j][k][1] + f[i - 1 & 1][j][k][0]) % P;
				}
				else
				{
					f[i & 1][j][k][1] = 0;
					f[i & 1][j][k][0] = (f[i - 1 & 1][j][k][1] + f[i - 1 & 1][j][k][0]) % P;
				}
			}
	
	cout << (f[n & 1][m][K][1] + f[n & 1][m][K][0]) % P << endl;
	
	return 0;
}
// ״̬��ʾ��
// 		f[i][j][k][2]��s1ǰi����s2ǰj����ѡk���Ӵ��ķ����� ѡ��ѡs1[i] 
// ״̬ת�ƣ�
//  	f[i][j][k][] = 
// 		1. s1[i] == s2[j]
//			1. ѡ��s1[i]�� f[i][j][k][1] = f[i - 1][j - 1][k][1] + f[i - 1][j - 1][k - 1][1] + f[i - 1][j - 1][k - 1][0](�Ƿ��s1[i]���ɵ����Ӵ�)
//			2. ��ѡ��s1[i]�� f[i][j][k][0] = f[i - 1][j][k][1] + f[i - 1][j][k][0](�ò���s1[i - 1])
//		2. s1[i] != s2[j] -> f[i][j][k][1] = 0(��ѡȴѡ), f[i - 1][j][k][0] + f[i - 1][j][k][1];
//
