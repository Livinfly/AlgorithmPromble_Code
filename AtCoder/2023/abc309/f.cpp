#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

struct Node {
    int a, b, c;
};

const int N = 2e5+10, INF = 2e9;

int n, nn, k;
Node p[N], np[N], tmp[N];
map<int, int> pl, pr;

bool cmp1(const Node &a, const Node &b) {
    if(a.a == b.a) {
        if(a.b == b.b) {
            return a.c < b.c;
        }
        return a.b < b.b;
    }
    return a.a < b.a;
}
bool cmp2(const Node &a, const Node &b) {
    if(a.b == b.b) {
        return a.c < b.c;
    }
    return a.b < b.b;
}
bool cdq(Node np[], int l, int r) {
    if(l >= r) return false;
    int mid = pl[np[l+r >> 1].a] - 1;
    if(mid < l) {
        mid = pr[np[l+r >> 1].a];
    }
    if(mid >= r) return false;
    if(cdq(np, l, mid) || cdq(np, mid+1, r)) {
        return true;
    }
    int i = l, j = mid+1, k = l;
    int t = INF;
    while(i <= mid && j <= r) {
        if(np[i].b < np[j].b) {
            t = min(t, np[i].c);
            tmp[k++] = np[i++];
        }
        else {
            if(t < np[j].c) {
                return true;
            }
            tmp[k++] = np[j++];
        }
    }
    while(j <= r) {
        if(t < np[j].c) {
            return true;
        }
        tmp[k++] = np[j++];
    }
    while(i <= mid) {
        tmp[k++] = np[i++];
    }
    for(int i = l; i <= r; i ++) {
        np[i] = tmp[i];
    }
    return false;
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i ++) {
        auto &[a, b, c] = p[i];
        cin >> a >> b >> c;
        if(a > b) swap(a, b);
        if(b > c) swap(b, c);
        if(a > b) swap(a, b);
    }
    sort(p, p+n, cmp1);
    for(int i = n-1; i >= 0; i --) {
        pl[p[i].a] = i;
    }
    for(int i = 0; i < n; i ++) {
        pr[p[i].a] = i;
    }
    bool ok = cdq(p, 0, n-1);
    if(ok) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
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