#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110;

int n, m;
int f[N];

int main()
{
	cin >> n >> m;
// 	memset(f, 0xcf, sizeof f);
// 	f[0] = 0;
	for(int i = 1; i <= n; i ++)
	{
	  int c, w, s;
	  cin >> c >> w >> s;
	  for(int j = 0; j < s; j ++)
  	  for(int k = m; k >= c; k --)
  	    f[k] = max(f[k], f[k-c] + w);
	}
// 	int res = 0;
// 	for(int i = 0; i <= m; i ++)
// 	 res = max(res, f[i]); // 不一定恰好用的体积最大的值最大
	cout << f[m] << endl;
	return 0;
}
/*
https://www.acwing.com/activity/content/code/content/1715492/
*/