#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 22;

int n, m, tsum, cnt;
int c[N], f[N][N]; // front i, j CD, k rest

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> tsum >> m;
	for(int i = 0; i < n; i ++) cin >> c[i];
	for(int i = 0; i < n; i ++)
	    for(int j = m; j >= 1; j --)
	        for(int k = tsum; k >= c[i]; k --)
	            f[j][k] = max(f[j - 1][tsum], f[j][k - c[i]]) + 1;
	int res = 0;
    for(int i = 0; i <= tsum; i ++)
        res = max(res, f[m][i]);
    cout << res << endl;
	return 0;
}
