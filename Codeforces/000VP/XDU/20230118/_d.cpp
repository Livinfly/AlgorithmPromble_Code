#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5+10;

struct Node {
    int l, r, mxp, mnp;
} tr[N*4];

int n, m;
int w[N];
bool is_v[N];
vector<int> valley;
vector<PII> ans;

void PushUp(int u) {
    int mxl = tr[u<<1].mxp, mxr = tr[u<<1|1].mxp;
    int mnl = tr[u<<1].mnp, mnr = tr[u<<1|1].mnp;
    if(w[mxl] > w[mxr]) 
        tr[u].mxp = mxl;
    else 
        tr[u].mxp = mxr;
    
    if(w[mnl] && w[mnl] < w[mnr]) 
        tr[u].mnp = mnl;
    else 
        tr[u].mnp = mnr;
}
void Build(int u, int l, int r) {
    if(l == r) {
        tr[u] = {l, r, r, r};
        return;
    }
    tr[u] = {l, r};
    int mid = l+r>>1;
    Build(u<<1, l, mid), Build(u<<1|1, mid+1, r);
    PushUp(u);
}
void Modify(int u, int x, int c) {
    if(tr[u].l == x && tr[u].r == x) {
        w[x] = c;
        return;
    }
    int mid = tr[u].l+tr[u].r>>1;
    if(x <= mid) Modify(u<<1, x, c);
    else Modify(u<<1|1, x, c);
    PushUp(u);
}
int Query(int u, int l, int r) {
    if(tr[u].l >= l && tr[u].r <= r) 
        return tr[u].mxp;
    int mid = tr[u].l+tr[u].r>>1;
    int p = -1;
    if(l <= mid)
        p = Query(u<<1, l, r);
    if(r > mid) {
        if(!~p) p = Query(u<<1|1, l, r);
        else {
            int t = Query(u<<1|1, l, r);
            if(w[t] > w[p]) p = t;
        }
    }
    return p;
}
int QueryMn(int u, int l, int r) {
    if(tr[u].l >= l && tr[u].r <= r) 
        return tr[u].mnp;
    int mid = tr[u].l+tr[u].r>>1;
    int p = -1;
    if(l <= mid)
        p = QueryMn(u<<1, l, r);
    if(r > mid) {
        if(!~p || !w[p]) p = QueryMn(u<<1|1, l, r);
        else {
            int t = QueryMn(u<<1|1, l, r);
            if(w[t] && w[t] < w[p]) p = t;
        }
    }
    if(!w[p]) p = n+1;
    return p;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> w[i];
    w[n+1] = n+1;
    for(int i = 2; i <= n; i ++)
        if(w[i] < w[i-1] && w[i] < w[i+1]) {
            valley.push_back(i);
            // is_v[i] = true;
        }
    Build(1, 1, n);
    int idv = 0, cntv = 0;
    m = n;
    while(m > 0) {
        int p1 = tr[1].mxp;
        int p0 = Query(1, 1, valley[idv]);
        if(p0 != p1) {
            if(idv+1 < valley.size() && (p0 == valley[idv] || !w[Query(1, p0+1, valley[idv])] && w[p0] < w[QueryMn(1, valley[idv], Query(1, valley[idv], valley[idv+1]))])) {
                idv ++;
                // if(is_v[p0]) cntv ++;
                // is_v[p0] = false;
                p0 = Query(1, 1, valley[idv]);
            }
        }
        if(p0 == p1) {
            // if(cntv+1 == valley.size() && p0 == valley[idv]) break;
            p0 = Query(1, 1, p1-1);
            if(!w[p0]) p0 = p1;
        }
        // cout << p0 << ' ' << p1 << endl;
        // cout << valley[idv] << endl;
        // if(is_v[p0]) cntv ++;
        // is_v[p0] = false;
        // if(is_v[p1]) cntv ++;
        // is_v[p1] = false;
        if(p0 != p1) m -= 2;
        else m --;
        ans.push_back({w[p0], w[p1]});
        Modify(1, p0, 0), Modify(1, p1, 0);
    }
    // for(int i = 1, j = 0; i <= n; i = j) {
    //     j = i+1;
    //     if(w[i]) {
    //         while(j+1 <= n && !w[j]) j ++;
    //         if(!w[j]) ans.push_back({w[i], w[i]});
    //         else ans.push_back({w[i], w[j]});
    //         w[i] = w[j] = 0;
    //         j ++;
    //     }
    // }
    
    cout << ans.size() << '\n';
    for(auto x : ans)
        cout << x.fi << ' ' << x.se << '\n';
    return 0;
}
/*
8
2 5 3 6 1 8 4 7

8
2 1 4 3 6 5 8 7
x   x x x   x x

6
4 2 6 5 3 1
*/