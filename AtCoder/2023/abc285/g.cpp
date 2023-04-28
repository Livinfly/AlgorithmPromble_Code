#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int G = 310, N = 1.8e5+10, M = 7.2e6+10, INF = 1e8;

int dxy[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};

int hh, tt, q[N];
int idx, h[N], ne[M], ver[M], e[M];
int n, m, S, T;
int d[N], cur[N];
char g[G][G];

void add(int a, int b, int c) {
    ver[idx] = b, e[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    ver[idx] = a, e[idx] = 0, ne[idx] = h[b], h[b] = idx ++;
}
bool bfs() {
    memset(d, -1, sizeof d);
    hh = tt = 0;
    q[0] = S, d[S] = 0, cur[S] = h[S];
    while(hh <= tt) {
        auto u = q[hh ++];
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = ver[i];
            if(!~d[v] && e[i]) {
                d[v] = d[u]+1;
                cur[v] = h[v];
                if(v == T) return true;
                q[++ tt] = v;
            }
        }
    }
    return false;
}
int update(int u, int limit) {
    if(u == T) return limit;
    int flow = 0;
    for(int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        cur[u] = i;
        int v = ver[i];
        if(d[v] == d[u]+1 && e[i]) {
            int t = update(v, min(e[i], limit-flow));
            if(!t) d[v] = -1;
            flow += t;
            e[i] -= t, e[i^1] += t;
        }
    }
    return flow;
}
int dinic() {
    int res = 0, flow;
    while(bfs())
        while(flow = update(S, INF)) 
            res += flow;
    return res;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout << fixed;  // << setprecision(20); // double
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    S = N-1, T = N-2;
    for(int i = 0; i < n; i ++)
        scanf("%s", g[i]);
    int cnt2 = 0;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++) {
            if(g[i][j] == '2') {
                cnt2 ++;
                add(S, i*m+j, 1);
                for(int k = 0; k < 4; k ++) {
                    int a = i+dxy[k][0], b = j+dxy[k][1];
                    if(a >= 0 && a < n && b >= 0 && b < m && g[a][b] != '1')
                        add(i*m+j, n*m+a*m+b, 1);
                }
            }
            if(g[i][j] != '1') 
                add(n*m+i*m+j, T, 1);
        }
    int res = dinic();
    if(res == cnt2) 
        puts("Yes");
    else 
        puts("No");
    return 0;
}