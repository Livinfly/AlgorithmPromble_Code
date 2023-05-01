#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 510;

int n = 500, m;
int g[N][N], deg[N], cnt, ans[1030];

inline void dfs(int u)
{
    for(int i = 1; i <= n; i ++)
        if(g[u][i])
        {
            g[u][i] --, g[i][u] --;
            dfs(i);
        }
    ans[++ cnt] = u;
}

int main()
{
	cin >> m;
	while(m --)
	{
	    int a, b;
	    cin >> a >> b;
	    g[a][b] ++, g[b][a] ++;
	    deg[a] ++, deg[b] ++;
	}
	int root = 0;
	while(!deg[root]) root ++;
	for(int i = 1; i <= n; i ++)
	    if(deg[i] & 1)
	    {
	        root = i;
	        break;
	    }
	dfs(root);
	for(int i = cnt; i; i --) cout << ans[i] << endl;
	return 0;
}
