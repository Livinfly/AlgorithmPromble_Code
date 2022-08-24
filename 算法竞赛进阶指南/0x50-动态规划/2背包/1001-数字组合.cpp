#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110, M = 1e4 + 10;

int n, m;
int w[N], f[M];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> w[i];
	f[0] = 1;
	for(int i = 1; i <= n; i ++)
	  for(int j = m; j >= w[i]; j --)
	    f[j] += f[j-w[i]];
	cout << f[m] << endl;
	return 0;
}