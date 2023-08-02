#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template<typename T>
struct FenwickTree {
    int n;
    vector<T> a;
    void init(int n) {
        this->n = n;
        a.assign(n+1, T());
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, T v) {
        for( ; x <= n; x += lowbit(x))
            a[x] += v;
    }
    T sum(int x) {
        auto ans = T();
        for( ; x; x -= lowbit(x))
            ans += a[x];
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l-1);
    }
    int kth(T k) {
        assert(k > 0);
        int x = 1;
        for (int i = 1<<__lg(n); i; i /= 2) {
            if(x+i <= n && k > a[x+i-1]) {
                x += i;
                k -= a[x-1];
            }
        }
        return x;
    }
};

constexpr int INF = 1e9;
struct Max {
    int x;
    Max(int x = -INF) : x(x) {}
    Max &operator+=(const Max &a) {
        if (a.x > x) x = a.x;
        return *this;
    }
};
FenwickTree<Max> fen1, fen2;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n+1);
    for(int i = 1; i <= n; i ++) {
        cin >> p[i];
    }
    vector<int> d(n+1, INF);
    fen1.init(n), fen2.init(n);
    for(int i = 1; i <= n; i ++) {
        d[i] = min(i + p[i] - fen1.sum(p[i]).x, 
            i - p[i] - fen2.sum(n-p[i]+1).x);
        fen1.add(p[i], i + p[i]);
        fen2.add(n-p[i]+1, i - p[i]);
    }
    fen1.init(n), fen2.init(n);
    for(int i = n; i >= 1; i --) {
        d[i] = min({d[i], 
                p[i] - i - fen1.sum(p[i]).x, 
                -i - p[i] - fen2.sum(n-p[i]+1).x});
        fen1.add(p[i], p[i] - i);
        fen2.add(n-p[i]+1, -i - p[i]);
    }
    for(int i = 1; i <= n; i ++) {
        cout << d[i] << " \n"[i == n];
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