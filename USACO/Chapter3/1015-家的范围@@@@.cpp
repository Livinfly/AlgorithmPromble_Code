#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 260;

int n, maxn;
int cnt[N], f[N][N]; // [i, j] as right_down point, max (a)
char g[N][N];

/*
* (g[i][j] == '1') f[i][j] = min(f[i - 1][j - 1], f[i][j - 1], f[i][j - 1]) + 1;
*/

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> g[i] + 1;
	for(int i = 1; i <= n; i ++) // no need for initialization
	    for(int j = 1; j <= n; j ++)
	        if(g[i][j] == '1') 
	            f[i][j] = min(f[i - 1][j - 1], min(f[i][j - 1], f[i - 1][j])) + 1;
	for(int i = 1; i <= n; i ++)
	    for(int j = 1; j <= n; j ++)
	    {
	        maxn = max(maxn, f[i][j]);
	        for(int k = 1; k <= f[i][j]; k ++)
	            cnt[k] ++;
	    }
	for(int i = 2; i <= maxn; i ++)
        cout << i << ' ' << cnt[i] << endl;
	
	return 0;
}
