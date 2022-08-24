#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 810, M = 3010, INF = 0x3f3f3f3f;

int idx, h[N], ne[M], ver[M], e[M];
int n, p, m;
int dist[N], id[N];
bool st[N];
queue<int> q;

inline void add(const int &a, const int &b, const int &c)
{
    ver[idx] = b, e[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
inline int spfa(int A)
{
    memset(dist, 0x3f, sizeof dist);
    // memset(st, 0, sizeof st);
    q.push(A);
    dist[A] = 0;
    st[A] = true;
    while(q.size())
    {
        int t = q.front(); q.pop();
        st[t] = false; // forget
        for(int i = h[t]; ~i; i = ne[i])
        {
            int v = ver[i];
            if(dist[v] > dist[t] + e[i])
            {
                dist[v] = dist[t] + e[i];
                if(!st[v])
                {
                    st[v] = true;
                    q.push(v);
                }
            }
        }
    }
    int res = 0;
    for(int i = 0; i < n; i ++)
        if(dist[id[i]] == INF) return INF;
        else res += dist[id[i]];
    return res;
}

int main()
{
	ios::sync_with_stdio(0);
	memset(h, -1, sizeof h);
	cin >> n >> p >> m;
	for(int i = 0; i < n; i ++) cin >> id[i];
	while(m --)
	{
	    int a, b, c;
	    cin >> a >> b >> c;
	    add(a, b, c), add(b, a, c);
	}
	
	int res = INF;
	for(int i = 1; i <= p; i ++)
	    res = min(res, spfa(i));
	cout << res << endl;
	return 0;
}
