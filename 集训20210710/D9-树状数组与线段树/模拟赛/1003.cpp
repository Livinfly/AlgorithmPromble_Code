#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>

using namespace std;

const int N = 1e3 + 10;

int n, res, maxn;
int f[N][N], s[N];

int main()
{
	while(scanf("%d", &n) == 1)
	{
		res = 0;
		for(int i = 1; i <= n; i ++) scanf("%d", &f[i][i]);
		for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + f[i][i];
		
		for(int len = 2; len <= n; len ++)
		{
			for(int l = 1; l + len - 1 <= n; l ++)
			{
				int r = l + len - 1;
				f[l][r] = s[r] - s[l - 1] - min(f[l + 1][r], f[l][r - 1]);
			}
		}
		
		cout << f[1][n] << endl;
	}
	
	return 0;
}
