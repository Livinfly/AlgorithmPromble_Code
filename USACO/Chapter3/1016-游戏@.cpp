#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110;

int n;
int s[N], f[N][N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++) 
	{
	    cin >> f[i][i];
	    s[i] = s[i - 1] + f[i][i];
	}
	for(int len = 2; len <= n; len ++)
	{
	    for(int l = 1; l + len - 1 <= n; l ++)
	    {
	        int r = l + len - 1;
	        f[l][r] = s[r] - s[l - 1] - min(f[l + 1][r], f[l][r - 1]); // let player2 get less
	    }
	}
	
	cout << f[1][n] << ' ' << min(f[2][n], f[1][n - 1]) << endl;
	
	return 0;
}
