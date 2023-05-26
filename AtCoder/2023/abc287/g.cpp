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
FenwickTree<int> fenc;
FenwickTree<LL> fens;

void solve() {
    int n;
    cin >> n;
    vector<int> val(1, 0);
    vector<array<int, 2>> ab(n);
    for(auto &[x, y] : ab) {
    	cin >> x >> y;
    	val.push_back(x);
    }
    int Q;
    cin >> Q;
    vector<array<int, 3>> query(Q);

    for(auto &[op, x, y] : query) {
    	cin >> op;
    	if(op == 1) {
    		cin >> x >> y;
    		val.push_back(y);
    	}
    	else if(op == 2) {
    		cin >> x >> y;
    	}
    	else {
    		cin >> x;
    	}
    }
    sort(1+all(val), greater<int>());
    val.resize(unique(1+all(val)) - val.begin());
    int m = val.size();
    fenc.init(m);
    fens.init(m);

    auto getVal = [&](int x) {
        return (lower_bound(1+all(val), x, greater<int>()) - val.begin());
    };

    for(auto &[a, b] : ab) {
        a = getVal(a);
        fenc.add(a, b);
        fens.add(a, 1LL*val[a] * b);
    }
    for(auto [op, x, y] : query) {
        // cerr << op << ' ' << x << ' ' << y << '\n';
        if(op == 1) {
            auto &[tx, tc] = ab[x-1];
            fenc.add(tx, -tc);
            fens.add(tx, -1LL*val[tx] * tc);
            y = getVal(y);
            // cerr << "1 : " << tx << ' ' << tc << ' ' << y << '\n';
            tx = y;
            fenc.add(tx, tc);
            fens.add(tx, 1LL*val[tx] * tc);
        }
        else if(op == 2) {
            auto &[tx, tc] = ab[x-1];
            fenc.add(tx, -tc);
            fens.add(tx, -1LL*val[tx] * tc);
            tc = y;
            fenc.add(tx, tc);
            fens.add(tx, 1LL*val[tx] * tc);
        }
        else {
            int p = fenc.kth(x), tot = fenc.sum(p);
            if (tot < x) {
                cout << -1 << "\n";
            }
            else {
                LL ans = fens.sum(p);
                ans -= 1LL*val[p] * (tot-x);
                cout << ans << "\n";
            }
        }
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