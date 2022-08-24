#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int N = 110;

int n, m, k, hmax;
map<char, int> dic;
char g[N][N], ans[N][N];

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i ++) cin >> g[i];
	for(int i = 0; i < k; i ++) 
	{
		char ch;
		int a;
		cin >> ch >> a;
		dic[ch] = a;
	}
	cout << "Front View" << endl;
	hmax = 0;
	for(int i = 0; i < 30; i ++)
		for(int j = 0; j < 80; j ++)
			ans[j][i] = ' ';
	for(int i = 0; i < m; i ++)
	{
		int maxn = 0;
		for(int j = 0; j < n; j ++)
			maxn = max(maxn, dic[g[j][i]]);
		hmax = max(hmax, maxn);
		for(int j = 0; j < maxn; j ++)
			ans[i][j] = '#';
	}
	for(int i = hmax - 1; i >= 0; i --)
	{
		for(int j = 0; j < m; j ++)
			cout << ans[j][i];
		cout << endl;
	}
	cout << endl;
	hmax = 0;
	for(int i = 0; i < 30; i ++)
		for(int j = 0; j < 80; j ++)
			ans[j][i] = ' ';
	cout << "Side View" << endl;
	for(int i = 0; i < n; i ++)
	{
		int maxn = 0;
		for(int j = 0; j < m; j ++)
			maxn = max(maxn, dic[g[i][j]]);
		hmax = max(hmax, maxn);
		for(int j = 0; j < maxn; j ++)
			ans[i][j] = '#';
	}
	for(int i = hmax - 1; i >= 0; i --)
	{
		for(int j = 0; j < n; j ++)
			cout << ans[j][i];
		if(i) cout << endl;
	}
    return 0;
}
