#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

struct LinearBasis {
    int n;
    vector<LL> a;
    void init(int _n = 64) {
        n = _n;
        a.assign(n, 0);
    }
    void insert(LL x) {
        for(int i = n-1; i >= 0; i --) {
            if(!x) return;
            if(!(x>>i & 1)) continue;
            if(a[i]) x ^= a[i];
            else {
                for(int j = 0; j < i; j ++) {
                    if(x>>j & 1) {
                        x ^= a[j];
                    }
                }
                for(int j = i+1; j < n; j ++) {
                    if(a[j]>>i & 1) {
                        a[j] ^= x;
                    }
                }
                a[i] = x;
                break;
            }
        }
    }
    LL max() {
        LL ret = 0;
        for(int i = 0; i < n; i ++) {
            ret ^= a[i];
        }
        return ret;
    }
    LL kth(LL k) {
        LL ret = 0;
        for(int i = 0; i < n; i ++) {
            if(a[i]) {
                if(k & 1) { // 不为0的位才算个数
                    ret ^= a[i];
                }
                k >>= 1;
            }
        }
        return ret;
    }
}lb;

void solve() {
    lb.init(60);
    LL n, l, r;
    cin >> n >> l >> r;
    for(int i = 0; i < n; i ++) {
        LL x;
        cin >> x;
        lb.insert(x);
    }
    for(LL i = l; i <= r; i ++) {
        cout << lb.kth(i-1) << " \n"[i == r];
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