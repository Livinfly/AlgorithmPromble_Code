#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 2e6 + 100;

int n, m;
int a[N];
bool st[N];

inline void dfs(int x, int d)
{
	if(x < 1 || x > n || d < 1 || st[x]) return; // st[]放后面 qwq不然会出现数组越界 
	cout << x << ' ';
	st[x] = true;
	// + 
	dfs(x - d, d - 1);
	// - 
	dfs(x + d, d - 1);
}

int main()
{
	cin >> n >> m;
	if(n - 1 < m) cout << -1 << endl;
	else
	{
		for(int i = 1; i < n - m; i ++)
		{
			cout << i << ' ';
			st[i] = true;
		}
		
		dfs(n - m, m);
		
		for(int i = 1; i <= n; i ++)
			if(!st[i]) cout << i << ' ';
		cout << endl;
	}
	
	return 0;
}
