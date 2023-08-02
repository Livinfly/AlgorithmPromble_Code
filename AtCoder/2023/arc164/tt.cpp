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
    void clear(int x) {
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
const int N = 6e5+10, INF = 1e9;
struct Max {
    int x;
    Max(int x = -INF) : x(x) {}
    Max &operator += (const Max &a) {
        if (a.x > x) x = a.x;
        return *this;
    }
};
FenwickTree<Max> fen;
struct Node {
    int a, b, c, type, res;
};

int n, nn, q, mx;
Node p[N], tp[N], tmp[N];

void cdq(Node np[], int l, int r) {
    if(l == r) return;
    int mid = l+r >> 1, i = l, j = mid+1, k = l;
    cdq(np, l, mid), cdq(np, mid+1, r);
    while(i <= mid && j <= r) {
        if(np[i].a <= np[j].a) {
            if(np[i].type == 1) {
                fen.add(np[i].b, np[i].a + np[i].b);
            }
            tmp[k++] = np[i++];
        }
        else {
            if(np[j].type == 2) {
                p[np[j].c].res = min(p[np[j].c].res, 
                                np[j].a+np[j].b - fen.sum(np[j].b).x);
            }
            tmp[k++] = np[j++];
        }
    }
    while(j <= r) {
        if(np[j].type == 2) {
            p[np[j].c].res = min(p[np[j].c].res, 
                                np[j].a+np[j].b - fen.sum(np[j].b).x);
        }
        tmp[k++] = np[j++];
    }
    for(int x = l; x < i; x ++) {
        if(np[x].type == 1) {
            fen.clear(np[x].b);
        }
    }
    while(i <= mid) tmp[k++] = np[i++];
    for(int i = l; i <= r; i ++) {
        np[i] = tmp[i];
    }
}
void work(int rx, int ry) {
    for(int i = 1; i <= n+q; i ++) {
        tp[i] = p[i];
        if(rx) tp[i].a = mx - p[i].a + 1;
        if(ry) tp[i].b = mx - p[i].b + 1;
    }
    cdq(tp, 1, n+q);
}
void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        auto &[a, b, c, type, res] = p[i];
        cin >> a >> b;
        a ++, b ++, c = i, type = 1;
        mx = max({a, b, mx});
    }
    for(int i = n+1; i <= n+q; i ++) {
        auto &[a, b, c, type, res] = p[i];
        cin >> type >> a >> b;
        a ++, b ++, c = i, res = INF;
        mx = max({a, b, mx});
    }
    fen.init(mx);
    work(0, 0), work(0, 1), work(1, 0), work(1, 1);
    for(int i = n+1; i <= n+q; i ++) {
        if(p[i].type == 2) {
            cout << p[i].res << '\n';
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