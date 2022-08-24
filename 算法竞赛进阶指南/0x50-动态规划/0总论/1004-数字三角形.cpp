#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 510;

int n;
int f[N][N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(f, -0x3f, sizeof f);
	cin >> n;
	for(int i = 1; i <= n; i ++)
	  for(int j = 1; j <= i; j ++)
	    cin >> f[i][j];
	for(int i = n-1; i; i --)
	  for(int j = 1; j <= i; j ++)
	    f[i][j] = max(f[i+1][j], f[i+1][j+1]) + f[i][j];
	cout << f[1][1] << endl;
	return 0;
}