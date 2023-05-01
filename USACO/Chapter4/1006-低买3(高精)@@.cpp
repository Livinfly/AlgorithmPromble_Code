#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 5010, M = 100;

int n;
int a[N], f[N], g[N][M];

inline void addHH(int a[], int b[], int res[])
{
	static int c[M];
	memset(c, 0, sizeof c);
	for(int i = 0, t = 0; i < M; i ++)
	{
		t += a[i] + b[i];
		c[i] = t % 10;
		t /= 10;
	}
	memcpy(res, c, sizeof c);
}
inline void printH(int a[])
{
	int k = M - 1;
	while(k > 0 && !a[k]) k --;
	for(int i = k; i >= 0; i --)
		cout << a[i];
  cout << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	
	g[0][0] = 1;
	int res = 0;
	for(int i = 1; i <= n; i ++)
	{
	  for(int j = 0; j < i; j ++)
	    if(!j || a[j] > a[i]) f[i] = max(f[i], f[j] + 1);
	  for(int j = 0; j < i; j ++) // prior, cuz its cnt won't come from the same
	    if(a[i] == a[j]) f[j] = -1;
	  for(int j = 0; j < i; j ++)
	    if((!j || a[j] > a[i]) && f[i] == f[j] + 1) 
	     addHH(g[i], g[j], g[i]);
	  res = max(res, f[i]);
	}
	int cnt[M] = {0};
	for(int i = 1; i <= n; i ++)
	  if(f[i] == res) addHH(cnt, g[i], cnt);
	cout << res << ' ';
	printH(cnt);
	return 0;
}