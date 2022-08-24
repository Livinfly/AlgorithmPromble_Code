#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 5010;

int n;
int a[N], f[N], g[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	
	g[0] = 1;
	int res = 0;
	for(int i = 1; i <= n; i ++)
	{
	  for(int j = 0; j < i; j ++)
	    if(!j || a[j] > a[i]) f[i] = max(f[i], f[j] + 1);
	  for(int j = 0; j < i; j ++) // prior, cuz its cnt won't come from the same
	    if(a[i] == a[j]) f[j] = -1;
	  for(int j = 0; j < i; j ++)
	    if((!j || a[j] > a[i]) && f[i] == f[j] + 1) 
	      g[i] += g[j];
	  res = max(res, f[i]);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i ++)
	  if(f[i] == res) cnt += g[i];
	cout << res << ' ' << cnt << endl;
	return 0;
}