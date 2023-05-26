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
        a.assign(n+1, 0);
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
FenwickTree<int> fen;

void solve() {
    fen.init(1000);
    fen.add(1, 2), fen.add(2, 4);
    cout << fen.kth(0) << '\n';
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