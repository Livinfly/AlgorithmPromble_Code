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
int n, bSize, bNum, modecnt;
vector<int> a, belong, val, cnt, ccnt;
vector<vector<int>> f;
vector<Rec> query;

void add(int x) {
    x = a[x];
    int bx = belong[x], &c = cnt[x];
    ccnt[c] --;
    f[bx][c] --;
    c ++;
    if(modecnt < c) {
        modecnt = c;
    }
    ccnt[c] ++;
    f[bx][c] ++;
}
void del(int x) {
    x = a[x];
    int bx = belong[x], &c = cnt[x];
    ccnt[c] --;
    f[bx][c] --;
    if(modecnt == c && ccnt[c] == 0) {
        modecnt --;
    }
    c --;
    ccnt[c] ++;
    f[bx][c] ++;
}
int Query() {
    for(int i = 1; i <= bNum; i ++) {
        if(f[i][modecnt] > 0) {
            for(int j = (i-1)*bSize + 1; j <= min(i*bSize, n); j ++) {
                if(cnt[j] == modecnt) {
                    return val[j];
                }
            }
        }
    }
    return -1;
}
void solve() {
    cin >> n;
    bSize = sqrt(n), bNum = (n-1)/bSize + 1;
    a.resize(n+1), belong.resize(n+1), val.resize(n+1), cnt.resize(n+1);
    ccnt.resize(n+1), query.resize(n), f.resize(bNum+1);
    for(auto &v : f) v.resize(n+1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        belong[i] = (i-1)/bSize + 1;
        val[i] = a[i];
    }
    sort(1+all(val));
    val.resize(unique(1+all(val)) - val.begin());
    for(int i = 1; i <= n; i ++) {
        a[i] = lower_bound(1+all(val), a[i]) - val.begin();
    }
    for(int i = 0; i < n; i ++) {
        auto &[l, r, qid] = query[i];
        cin >> l >> r;
        qid = i;
    }
    sort(all(query), [&](const Rec &a, const Rec &b) {
        int abl = belong[a.l], bbl = belong[b.l];
        if(abl != bbl) {
            return abl < bbl;
        }
        else {
            if(abl & 1) return a.r < b.r;
            else return a.r > b.r;
        }
    });
    vector<int> ans(n);
    int l = 1, r = 0;
    for(int i = 0; i < n; i ++) {
        auto [ll, rr, qid] = query[i];
        while(l > ll) add(-- l);
        while(r < rr) add(++ r);
        while(l < ll) del(l ++);
        while(r > rr) del(r --);
        ans[qid] = Query();
    }
    for(auto x : ans) {
        cout << x << '\n';
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