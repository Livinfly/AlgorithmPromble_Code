#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 40, M = 2010;
const LL INF = 1e18;

int n, m, S, T;
int h[N], e[M], ne[M], idx;
LL f[M];
int q[N], d[N], cur[N];

void add(int a, int b, LL c)
{
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx ++ ;
}

bool bfs()
{
    int hh = 0, tt = 0;
    memset(d, -1, sizeof d);
    q[0] = S, d[S] = 0, cur[S] = h[S];
    while (hh <= tt)
    {
        int t = q[hh ++ ];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int ver = e[i];
            if (d[ver] == -1 && f[i])
            {
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];
                if (ver == T) return true;
                q[ ++ tt] = ver;
            }
        }
    }
    return false;
}

LL find(int u, LL limit)
{
    if (u == T) return limit;
    LL flow = 0;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i])
    {
        cur[u] = i;
        int ver = e[i];
        if (d[ver] == d[u] + 1 && f[i])
        {
            LL t = find(ver, min(f[i], limit - flow));
            if (!t) d[ver] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }
    return flow;
}

LL dinic()
{
    LL r = 0, flow;
    while (bfs()) while (flow = find(S, INF)) r += flow;
    return r;
}

void init()
{
    for (int i = 0; i < idx; i += 2)
    {
        f[i] += f[i ^ 1];
        f[i ^ 1] = 0;
    }
}

int main()
{
    cin >> n >> m;
    S = 1, T = n;
    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c * 10000ll + 1);
    }

    LL res = dinic();
    cout << res / 10000 << ' ' << res % 10000 << endl;
    for (int i = 0; i < idx; i += 2)
    {
        init();
        LL t = f[i];
        f[i] = 0;
        LL r = dinic();
        if (r == res - t)
        {
            cout << i / 2 + 1 << endl;
            res = r;
        }
        else f[i] = t;
    }
    return 0;
}
/*
作者：yxc
链接：https://www.acwing.com/activity/content/code/content/653011/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/