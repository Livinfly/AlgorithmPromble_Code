#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10, MO = 1e9+7;

int qpm(int a, int b, const int &c = MO) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = 1LL*ans*a%MO;
        a = 1LL*a*a%MO;
        b >>= 1;
    }
    return ans;
}
struct Comb {
    int n;
    vector<int> _fac, _facInv, _inv;
    Comb() : n{0}, _fac{1}, _facInv{1}, _inv{0} {}
    Comb(int n) : Comb() {
        Init(n);
    }
    void Init(int m) {
        if(m <= n) return;
        _fac.resize(m+1);
        _facInv.resize(m+1);
        _inv.resize(m+1);
        for(int i = n+1; i <= m; i ++) {
            _fac[i] = 1LL*_fac[i-1]*i%MO;
        }
        _facInv[m] = qpm(_fac[m], MO-2);
        for(int i = m; i > n; i --) {
            _facInv[i-1] = 1LL*_facInv[i]*i%MO;
            _inv[i] = 1LL*_facInv[i]*_fac[i-1]%MO;
        }
        n = m;
    }
    int Fac(int m) {
        if(m > n) Init(2*m);
        return _fac[m];
    }
    int FacInv(int m) {
        if(m > n) Init(2*m);
        return _facInv[m];
    }
    int Inv(int m) {
        if(m > n) Init(2*m);
        return _inv[m];
    }
    int Permu(int n, int m) {
        if(n < m || m < 0) return 0;
        return 1LL*Fac(n) * FacInv(n-m) % MO;
    }
    int Bimon(int n, int m) {
        if(n < m || m < 0) return 0;
        return 1LL*Fac(n) * FacInv(n-m) % MO * FacInv(m) %MO;
    }
} comb;

int n, k, ans;
int siz[N];
vector<int> e[N];

void dfs(int u, int fa) {
    siz[u] = 1;
    for(auto v : e[u]) {
        if(v == fa) continue;
        dfs(v, u);
        siz[u] += siz[v];
    }
    ans = (1LL*ans + 1LL*comb.Bimon(siz[u], k/2)*comb.Bimon(n-siz[u], k/2)%MO) % MO;
}

void solve() {
    cin >> n >> k;
    comb.Init(n);
    for(int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    if(k & 1) {
        cout << "1\n";
    }
    else {
        dfs(1, -1);
        cout << (1LL*ans*qpm(comb.Bimon(n, k), MO-2)%MO+1)%MO << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}