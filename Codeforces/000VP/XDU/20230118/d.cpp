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
    int l, r, mxp;
} tr[N*4];
struct List {
    int val, pre, ne;
};

int n, m;
List w[N];
vector<PII> ans;
set<int> st;

void PushUp(int u) {
    int mxl = tr[u<<1].mxp, mxr = tr[u<<1|1].mxp;
    if(w[mxl].val > w[mxr].val) 
        tr[u].mxp = mxl;
    else 
        tr[u].mxp = mxr;
}
void Build(int u, int l, int r) {
    if(l == r) {
        tr[u] = {l, r, r};
        return;
    }
    tr[u] = {l, r};
    int mid = l+r>>1;
    Build(u<<1, l, mid), Build(u<<1|1, mid+1, r);
    PushUp(u);
}
void Modify(int u, int x, int c) {
    if(tr[u].l == x && tr[u].r == x) {
        w[x].val = c;
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
            if(w[t].val > w[p].val) p = t;
        }
    }
    return p;
}
void update(int u) {
    auto l = w[u].pre, r = w[u].ne;
    if(st.count(u)) {
        st.erase(st.find(u));
        bool UDL = w[w[l].pre].val <= w[l].val;
        bool UDR = w[r].val <= w[w[r].ne].val;
        if(w[l].val < w[r].val) {
            if(!UDR && r <= n && r >= 1) {
                st.insert(r);
            }
        }
        else {
            if(UDL && l <= n && l >= 1) {
                st.insert(l);
            }
        }
    }
    w[l].ne = r;
    w[r].pre = l;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> w[i].val;
        w[i].pre = i-1, w[i].ne = i+1;
    }
    w[0] = {0, 0, 1};
    w[n+1] = {n+1, n, n+1};
    // w[n+2] = {n+2, n+1, n+3};
    for(int i = 1; i <= n; i ++)
        if(w[i].val > w[i-1].val && w[i].val > w[i+1].val) {
            st.insert(i);
        }
    // st.insert(n); // ?
    Build(1, 1, n);
    // int idv = 0, cntv = 0;
    // m = n;
    while(st.size()) {
        // for(auto x : st)
        //     cout << x << ' ';
        // cout << '\n';
        // for(int i = 1; i <= n; i ++)
        //     if(w[i].val)
        //         cout << i << ": " << w[i].pre << ' ' << w[i].ne << ' ' << w[i].val << '\n';
        // cout << '\n';
        int p1 = tr[1].mxp;
        int p0 = *st.begin();
        if(p0 == p1 && w[w[p0].pre].val) p0 = w[p0].pre;
        ans.push_back({w[p0].val, w[p1].val});
        Modify(1, p0, 0), Modify(1, p1, 0);
        update(p0);
        if(p0 != p1) update(p1);
    }
    // int p0 = w[0].ne;
    // while(st.size()) {
    //     int p1 = *st.begin();
    //     ans.push_back({w[p0].val, w[p1].val});
    //     w[p0].val = w[p1].val = 0;
    //     update(p0);
    //     if(p0 != p1) update(p1);
    //     p0 = w[p0].ne;
    // }
    for(int i = 1, j = 0; i <= n; i = j) {
        j = i+1;
        if(w[i].val) {
            while(j+1 <= n && !w[j].val) j ++;
            if(!w[j].val) ans.push_back({w[i].val, w[i].val});
            else ans.push_back({w[i].val, w[j].val});
            w[i].val = w[j].val = 0;
            j ++;
        }
    }
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


0 0 0 2 1 0 6 5
      *     *

0 0 0 0 1 0 0 5

*/