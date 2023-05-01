// 2021/07/13
// Luogu P2679 - NOIP2015S 子串 - ioj 
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
// 状态表示：
// 		f[i][j][k][2]：s1前i个，s2前j个，选k个子串的方案数 选不选s1[i] 
// 状态转移：
//  	f[i][j][k][] = 
// 		1. s1[i] == s2[j]
//			1. 选用s1[i]， f[i][j][k][1] = f[i - 1][j - 1][k][1] + f[i - 1][j - 1][k - 1][1] + f[i - 1][j - 1][k - 1][0](是否把s1[i]看成单独子串)
//			2. 不选用s1[i]， f[i][j][k][0] = f[i - 1][j][k][1] + f[i - 1][j][k][0](用不用s1[i - 1])
//		2. s1[i] != s2[j] -> f[i][j][k][1] = 0(不选却选), f[i - 1][j][k][0] + f[i - 1][j][k][1];
//
