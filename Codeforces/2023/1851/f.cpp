#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10;

int idx, son[N*32][2], id[N*32];
int n, k;
int ans, pp, qq;


void insert(int x, int u) {
    int p = 0;
    for(int i = k-1; i >= 0; i --) {
        int t = x>>i & 1;
        if(!son[p][t]) son[p][t] = ++idx;
        p = son[p][t];
    }
    id[p] = u;
}
int query(int x, int u) {
    int p = 0, ret = 0;
    for(int i = k-1; i >= 0; i --) {
        int t = x>>i & 1;
        if(son[p][t]) {
            ret = (ret<<1) + 1;
            p = son[p][t];
        }
        else if(son[p][!t]) {
            ret = (ret<<1);
            p = son[p][!t];
        }
    }
    if(ret > ans) {
        ans = ret;
        pp = id[p];
        qq = u;
    }
    return ret;
}
void solve() {
    cin >> n >> k;
    for(int i = 0; i <= idx; i ++) {
        id[i] = 0;
        for(auto x: {0, 1}) {
            son[i][x] = 0;
        }
    }
    idx = ans = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(i) query(a[i], i);
        // cerr << t << '\n';
        // if(i) cerr << query(a[i], i) << '\n';
        insert(a[i], i);
    }
    // int mx = 0, q = -1;
    // for(int i = 0; i < pp; i ++) {
    //     if(i != pp) {
    //         if((a[i] & a[pp]) > mx) q = i;
    //     }
    // }
    int x = 0;
    if(ans == 0) pp = 0, qq = 1;
    else {
        for(int i = k-1; i >= 0; i --) {
            int aa = a[pp]>>i & 1, b = a[qq]>>i & 1;
            if(aa == b) {
                x += (!aa)<<i;
            }
        }
    }
    cout << pp+1 << ' ' << qq+1 << ' ' << x << '\n';
    // cerr << ((a[pp]^x) & (a[qq]^x)) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}