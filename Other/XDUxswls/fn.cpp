#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 510, M = N*N*2, INF = 0x3f3f3f3f;

int idx, h[N<<1], ne[M], ver[M], e[M];
LL co[M];
int n, S, T;
int d[N<<1], cur[N<<1];
LL eMx = INF;

void add(int a, int b, int c, LL d) {
    ver[idx] = b, e[idx] = c, co[idx] = d, ne[idx] = h[a], h[a] = idx ++;
}
bool bfs() {
    queue<int> q;
    memset(d, -1, sizeof d);
    q.push(S);
    d[S] = 0, cur[S] = h[S];
    while(q.size()) {
        int t = q.front(); q.pop();
        for(int i = h[t]; ~i; i = ne[i]) {
            int v = ver[i];
            if(d[v] == -1 && e[i] && co[i] <= eMx) {
                d[v] = d[t]+1;
                cur[v] = h[v];
                if(v == T) return true;
                q.push(v);
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
        if(d[v] == d[u]+1 && e[i] && co[i] <= eMx) {
            int t = update(v, min(e[i], limit-flow));
            if(!t) d[v] = -1;
            flow += t;
            e[i] -= t;
            e[i^1] += t;
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
bool check(LL mid) {
    eMx = mid;
    for(int i = 0; i < idx; i += 2)
        e[i] = 1, e[i^1] = 0;
    return dinic() == n;
}
void solve() {
    memset(h, -1, sizeof h);
    cin >> n;
    S = n*2, T = n*2+1;
    for(int i = 0; i < n; i ++) {
        add(S, i, 1, 0);
        add(i, S, 0, 0); 
        add(i+n, T, 1, 0); 
        add(T, i+n, 0, 0);
    }
    vector<LL> e;
    for(int i = 0; i < n; i ++) 
        for(int j = 0; j < n; j ++) {
            LL x; cin >> x;
            if(x != 0) {
                add(i, j+n, 1, x);
                add(j+n, i, 0, x);
                e.push_back(x);
            }
        }
    sort(all(e));
    e.resize(unique(all(e))-e.begin()+1);
    LL l = 0, r = e.size()-1;
    // cout << check(1) << '\n';
    while(l < r) {
        LL mid = l+r>>1;
        // cout << mid << ' ' << check(mid) << '\n';
        if(check(e[mid])) r = mid;
        else l = mid+1;
    }
    cout << ((r < 0 || !check(e[r])) ? -1 : e[r]) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("o.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}