#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 5e4 + 10, M = 1e6 + 10;

int idx, h[N], ne[M], ver[M];
int n, m, cnt;
int siz[N];
bool st[N];
string ans[N];

inline void add(int a, int b)
{
	ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
inline string get_string(int x)
{
	string res = "";
	while(x) res += (char)(x % 10 + 48), x /= 10; // only because '+= -> =' make me too sad
	reverse(res.begin(), res.end());
	return res;
}
inline void dfs(int u, int fa)
{
	siz[u] = 1;
	st[u] = true;
	for(int i = h[u]; ~i; i = ne[i])
	{
		int v = ver[i];
		if(st[v]) continue;
		dfs(v, u);
		siz[u] += siz[v];
	}
	if(fa != -1) ans[cnt ++] = get_string(fa) + " -> " + get_string(u);
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while(m --)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	dfs(1, -1);
    if(siz[1] < n)
    {
    	cout << "Impossible!" << endl;
	}
	else
	{
		for(int i = 0; i < cnt; i ++)
			cout << ans[i] << endl;
	}
    
    return 0;
}
