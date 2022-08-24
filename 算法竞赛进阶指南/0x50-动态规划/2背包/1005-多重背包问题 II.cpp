#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 2010;

int n, m;
int f[N];

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
	  int c, w, s;
	  cin >> c >> w >> s;
	  for(int j = 1; j <= s; s -= j, j <<= 1) // 先减再移, <= 能减则减
  	  for(int k = m; k >= c*j; k --)
  	    f[k] = max(f[k], f[k-c*j] + w*j);
    if(s)
    {
      for(int k = m; k >= c*s; k --)
  	    f[k] = max(f[k], f[k-c*s] + w*s);
    }
	}
	cout << f[m] << endl;
	return 0;
}
/*
https://www.acwing.com/activity/content/code/content/1715555/
*/