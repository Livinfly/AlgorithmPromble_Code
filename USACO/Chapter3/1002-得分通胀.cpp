#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int M = 1e4 + 10;

int n, m;
int w, c, f[M]; 

int main()
{
	cin >> m >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> w >> c;
		for(int j = c; j <= m; j ++)
			f[j] = max(f[j], f[j - c] + w);
	}
	
	cout << f[m] << endl;
	
	return 0;
}
