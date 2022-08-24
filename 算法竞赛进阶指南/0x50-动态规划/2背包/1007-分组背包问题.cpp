#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110;

int n, m;
int s[N], c[N][N], w[N][N], f[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
	  cin >> s[i];
	  for(int j = 1; j <= s[i]; j ++)
	    cin >> c[i][j] >> w[i][j];
	}
	for(int i = 1; i <= n; i ++)
  	for(int j = m; j >= 0; j --)
	    for(int k = 1; k <= s[i]; k ++)
	    {
	      if(j >= c[i][k])
	        f[j] = max(f[j], f[j-c[i][k]]+w[i][k]);
	    }
	cout << f[m] << endl;
	return 0;
}
/*
https://www.acwing.com/activity/content/code/content/1715707/
*/