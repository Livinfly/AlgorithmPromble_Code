#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 2010, P = 998244353;

int n, res;
int a[N], l[N], r[N];

void dfs(int x, int b1, int dx)
{
	if(x == n + 1) 
	{
		res ++;
		return;
	}
	for(int b = a[x] - r[x]; b <= a[x] - l[x]; b ++)
	{
		if(x == 1 || a[x] - b != dx && b1 <= b) 
			dfs(x + 1, b, a[x] - b);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i ++) scanf("%d%d", &l[i], &r[i]);
	
	dfs(1, -1, -1);
		
	cout << res << endl;
	
	return 0;
}
