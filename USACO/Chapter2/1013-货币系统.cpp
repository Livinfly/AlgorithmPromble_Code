#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e4 + 10;

typedef long long LL;

int n, m;
LL f[N];

void solve()
{
	f[0] = 1;
	for(int i = 0; i < n; i ++)
	{
		int v;
		cin >> v;
		for(int j = v; j <= m; j ++)
			f[j] += f[j - v];
	}
	cout << f[m] << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	solve();
	
	return 0;
}
