#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m, maxn; 

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
		{
			int t;
			cin >> t;
			maxn = max(maxn, t);
		}
    cout << maxn << endl;
    
    return 0;
}
