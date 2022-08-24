#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 210;

int n;
int a[N], b[N];
int f[N][N];

int main()
{
	int T; cin >> T;
	for(int zz = 1; zz <= T; zz ++)
	{
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		memset(f, 0x3f, sizeof f);
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i ++) scanf("%d", &b[i]);
		
		for(int i = 1; i <= n; i ++) f[i][i] = a[i] + b[i - 1] + b[i + 1];
		
		for(int len = 2; len <= n; len ++)
			for(int l = 1; l + len - 1 <= n; l ++)
			{
				int r = l + len - 1;
				f[l][r] = min(a[l] + f[l + 1][r], a[r] + f[l][r - 1]) + b[l - 1] + b[r + 1];
				for(int k = l + 1; k <= r - 1; k ++)
					f[l][r] = min(f[l][r], f[l][k - 1] + f[k + 1][r] + a[k] + b[l - 1] + b[r + 1]);
			}
		
//		for(int i = 1; i <= n; i ++)
//		{
//			for(int j = 1; j <= n; j ++)
//				printf("%d ", f[i][j]);
//			cout << endl;
//		}
		printf("Case #%d: %d\n", zz, f[1][n]);
	}
	
	return 0;
}
