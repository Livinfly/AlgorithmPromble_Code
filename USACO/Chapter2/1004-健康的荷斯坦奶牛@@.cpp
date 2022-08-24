#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 30;

int n, m, maxn;
int cow[N];
int len, ans[N];

struct rec
{
	int vit[N];
} feeds[17];

inline bool check()
{
	static int sum[N];
	memset(sum, 0, sizeof sum);
	for(int i = 0; i < len; i ++)
		for(int j = 0; j < n; j ++)
			sum[j] += feeds[ans[i]].vit[j];
	for(int i = 0; i < n; i ++)
		if(sum[i] < cow[i]) return false;
	return true;
}
inline bool dfs(int x, int depth)
{
	len = depth;
	if(check()) return true;
	if(depth == maxn) return false;
	for(int i = x + 1; i < m; i ++)
	{
		ans[depth] = i;
		if(dfs(i, depth + 1)) return true;
	}
	return false;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> cow[i];
	cin >> m;
	for(int i = 0; i < m; i ++)
		for(int j = 0; j < n; j ++)
			cin >> feeds[i].vit[j];
	
	for(maxn = 1; maxn <= m; maxn ++)
		if(dfs(-1, 0)) break;
	
	cout << len << ' ';
	for(int i = 0; i < len; i ++)
		cout << ans[i] + 1 << ' ';
	cout << endl;
	
	return 0;
}
