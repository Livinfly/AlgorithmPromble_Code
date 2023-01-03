#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110, P = 998244353;

LL C[N][N];
LL res = 1;
int fa[N];
vector<PII> seg;

int GetFa(int x) {
    if(x == fa[x]) return x;
    return fa[x] = GetFa(fa[x]);
}
void merge(int x, int y) {
    int fx = GetFa(x), fy = GetFa(y);
    if(fx != fy) 
        fa[fy] = fx;
}
LL qpm(LL a, int b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = ans*a % P;
        a = a*a % P;
        b >>= 1;
    }
    return ans;
}
int count(int l, int r) {
    int res = 0;
    for(int i = l; i < r; i ++) {
        if(fa[i] != fa[i-1]) res ++;
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) fa[i] = i;
    seg.clear();
    for(int i = 1; i <= n; i ++)
        for(int j = i; j <= n; j ++) {
            int x;
            cin >> x;
            if(x == 1) {
                for(int k = i; k <= j; k ++) 
                    merge(i, j);
            }
            else if(x == 2)
                seg.push_back(mkp(i, j));
        }
    sort(all(seg));
    res = 1;
    for(int i = 0; i < seg.size(); i ++) {
        int cnt = count(seg[i].fi, seg[i].se);
        if(cnt == 1) {
            cout << "0\n";
            return;
        }
        for(int j = i+1; j < seg.size(); j ++) {
            if(seg[i].se < seg[j].fi) break;
            if(seg[j].se <= seg[i].se) {
                
                res = res * C[]
            }
        }
    }
    res = res*2%P;
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    for(int i = 0; i <= 100; i ++)
        for(int j = 0; j <= i; j ++)
            if(!j) C[i][j] = 1;
            else C[i][j] = (C[i-1][j]+C[i-1][j-1])%P;
    int T;
    cin >> T;  // scanf("%d", &T);
    while (T--) solve();
    return 0;
}