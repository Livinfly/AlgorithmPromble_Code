#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1010;

int n, m;
char s1[N], s2[N];
int f[N][N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> s1 + 1 >> s2 + 1;
	for(int i = 1; i <= n; i ++)
	  for(int j = 1; j <= m; j ++)
	  {
	    f[i][j] = max(f[i-1][j], f[i][j-1]); // 不要s1[i], 不要s2[j]
	    if(s1[i] == s2[j]) f[i][j] = max(f[i][j], f[i-1][j-1]+1);
	  }
	cout << f[n][m] << endl;
	return 0;
}