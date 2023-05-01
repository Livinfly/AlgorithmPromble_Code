#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1010;

int n, m;
int f[N];


int main()
{
	ios::sync_with_stdio(0);
	
	while(cin >> m >> n, n != -1 || m != -1)
	{
		memset(f, -0x3f, sizeof f);
		f[0] = 0;
		for(int i = 1; i <= n; i ++) 
		{
			int w, c;
			cin >> w >> c;
			for(int j = m; j >= c; j --)
				f[j] = max(f[j], f[j - c] + w);
		}
		if(f[m] < 0) cout << -1 << endl;
		else cout << f[m] << endl;
	}
	
	return 0;
}
