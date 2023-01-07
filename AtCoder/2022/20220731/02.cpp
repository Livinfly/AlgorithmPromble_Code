#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 110;

int n, m;
bool g[N][N];


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
	cin >> n >> m;
	while(m --)
	{
		int a, b;
		cin >> a >> b;
		g[a][b] = g[b][a] = true;
	} 
	int res = 0;
	for(int i = 1; i <= n-2; i ++)
		for(int j = i+1; j <= n-1; j ++)
			for(int k = j+1; k <= n; k ++)
				if(g[i][j] && g[j][k] && g[k][i]) 
					res ++;		
	cout << res << endl;
  return 0;
}
