// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

template<typename T>
struct FenwickTree {
    int n;
    vector<T> a;
    void init(int n) {
        this->n = n;
        a.assign(n+1, T());
    }
    void clear(int x) { // for Max
        for( ; x <= n; x += lowbit(x)) {
            a[x] = T();
        }
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
    T sum(int l, int r) {
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

const int N = 1e6+10;

int siz, w[N];
set<int> st[N];
vector<array<int, 2>> ops;

// 线性。。
void solve() {
    int n; cin >> n;
    fen.init(n);
    while(n--) {
        int x, v; char op;
        cin >> op;
        if(op == '+') {
            cin >> x;
            v = w[++siz];
            if(v) {
                if(!st[v].empty()) {
                    fen.add(*st[v].begin(), -1);
                    st[v].erase(siz);
                }
                if(!st[v].empty()) {
                    fen.add(*st[v].begin(), 1);
                }
            }
            ops.push_back({v, 1});
            w[siz] = v = x;
            if(!st[v].empty()) {
                fen.add(*st[v].begin(), -1);
            }
            st[v].insert(siz);
            if(!st[v].empty()) {
                fen.add(*st[v].begin(), 1);
            }

        }
        else if(op == '-') {
            cin >> x;
            siz -= x;
            ops.push_back({x, 0});
        }
        else if(op == '!') {
            auto [x, y] = ops.back(); ops.pop_back();
            if(!y) {
                siz += x;
            }
            else {
                v = w[siz];
                if(!st[v].empty()) {
                    fen.add(*st[v].begin(), -1);
                    st[v].erase(siz);
                }
                if(!st[v].empty()) {
                    fen.add(*st[v].begin(), 1);
                }
                w[siz] = v = x;
                if(v) {
                    if(!st[v].empty()) {
                        fen.add(*st[v].begin(), -1);
                    }
                    st[v].insert(siz);
                    if(!st[v].empty()) {
                        fen.add(*st[v].begin(), 1);
                    }
                }
                siz--;
            }
        }
        else {
            cout << fen.sum(siz) << endl;
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}