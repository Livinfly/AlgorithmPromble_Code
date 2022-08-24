#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 2e5 + 10;

int n;
bool st[N];
vector<int> h[N], ans;

inline void dfs(int u)
{
	st[u] = true;
	ans.push_back(u);
	bool flag = false;
	for(int i = 0; i < h[u].size(); i ++)
	{
		int v = h[u][i];
		if(!st[v]) 
		{
			dfs(v);
			ans.push_back(u);
			flag = true;
		}
	}
	return;
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n - 1; i ++)
	{
		int a, b;
		cin >> a >> b;
		h[a].push_back(b);
		h[b].push_back(a);
	}
	for(int i = 1; i <= n; i ++) 
		sort(h[i].begin(), h[i].end());
	dfs(1);
	cout << ans[0];
    for(int i = 1; i < ans.size(); i ++)
    	cout << ' ' << ans[i];
    cout << endl;
    return 0;
}
