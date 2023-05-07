#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

struct Rec {
    int l, r, qid;
};

LL tans;
int bNum, bSize;
vector<int> a, belong, cnt;
vector<Rec> query;

LL f(int c) {
    return 1LL*c*(c-1)*(c-2)/6;
}
void add(int x) {
    auto &c = cnt[a[x]];
    tans -= f(c);
    c ++;
    tans += f(c);
}
void del(int x) {
    auto &c = cnt[a[x]];
    tans -= f(c);
    c --;
    tans += f(c);
}
void solve() {
    int n, m;
    cin >> n >> m;
    a.resize(n+1), belong.resize(n+1), query.resize(m+1);
    if(n > m) bSize = n/sqrt(m);
    else bSize = sqrt(n);
    bNum = (n-1)/bSize + 1;
    int mx = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        belong[i] = (i-1)/bSize + 1;
    }
    cnt.resize(mx+1);
    for(int i = 1; i <= m; i ++) {
        auto &[l, r, qid] = query[i];
        cin >> l >> r;
        qid = i;
    }
    sort(1+all(query), [&](const Rec &a, const Rec &b) {
        int abl = belong[a.l], bbl = belong[b.l];
        if(abl != bbl) {
            return abl < bbl;
        }
        else {
            if(abl & 1) return a.r < b.r;
            else return a.r > b.r;
        }
    });

    vector<LL> ans(m+1);
    int l = 1, r = 0;
    for(int i = 1; i <= m; i ++) {
        auto [ll, rr, qid] = query[i];
        while(l < ll) del(l ++);
        while(l > ll) add(-- l);
        while(r < rr) add(++ r);
        while(r > rr) del(r --);
        ans[qid] = tans;
    }
    for(int i = 1; i <= m; i ++) {
        cout << ans[i] << '\n';
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