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
	  for(int j = 0; j < i; j ++)
	    if((!j || a[j] > a[i]) && f[i] == f[j] + 1) g[i] += g[j];
	  for(int j = 0; j < i; j ++)
	    if(a[i] == a[j]) a[j] = -1;
	  res = max(res, f[i]);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i ++)
	  if(a[i] > 0 && f[i] == res) cnt += g[i];
	cout << res << ' ' << cnt << endl;
	return 0;
}