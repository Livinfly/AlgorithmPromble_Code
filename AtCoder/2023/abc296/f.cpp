#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

struct FenwickTree { // int / LL
    int n;
    vector<int> a;
    void Init(int n) {
        this->n = n;
        a.assign(n+1, 0);
    }
    int Lowbit(int x) {
        return x & -x;
    }
    void Add(int x, int v) {
        for( ; x <= n; x += Lowbit(x))
            a[x] += v;
    }
    int Sum(int x) {
        int ans = 0;
        for( ; x; x -= Lowbit(x))
            ans += a[x];
        return ans;
    }
    int RangeSum(int l, int r) {
        return Sum(r) - Sum(l-1);
    }
}fen;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
   	for(auto &x : a) 
   		cin >> x;
   	for(int i = 0; i < n; i ++) 
   		cin >> b[i];
    vector<int> va = a, vb = b;
    sort(all(va)), sort(all(vb));
    if(va != vb) {
        cout << "No\n";
        return;
    }
    if(unique(all(va))-va.begin() != n) {
        cout << "Yes\n";
        return;
    }
    fen.Init(n);
    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        cnt ^= fen.RangeSum(a[i]+1, n)&1;
        fen.Add(a[i], 1);
    }
    fen.Init(n);
    for(int i = 0; i < n; i ++) {
        cnt ^= fen.RangeSum(b[i]+1, n)&1;
        fen.Add(b[i], 1);
    }
    if(cnt & 1) {
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
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