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
int n, bSize, bNum, modecnt, modecntB, res, resB;
vector<int> a, belong, val, cnt, tcnt;
vector<Rec> query;

int bf(int l, int r) {
    int ret = 0, mx = 0;
    tcnt.assign(n+1, 0);
    for(int i = l; i <= r; i ++) { // tcnt
        tcnt[a[i]] ++;
        if(tcnt[a[i]] > mx || tcnt[a[i]] == mx && a[i] < ret) {
            mx = tcnt[a[i]], ret = a[i];
        }
    }
    return val[ret];
}
void add(int x) {
    x = a[x];
    cnt[x] ++;
    if(cnt[x] > modecnt || cnt[x] == modecnt && x < res) {
        modecnt = cnt[x], res = x;
    }
}
void del(int x) {
    x = a[x];
    cnt[x] --;
}
void solve() {
    cin >> n;
    bSize = sqrt(n), bNum = (n-1)/bSize + 1;
    a.resize(n+1), belong.resize(n+1), val.resize(n+1);
    cnt.resize(n+1);
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
    query.resize(n);
    n = 0;
    for(auto &[l, r, qid] : query) {
        cin >> l >> r;
        qid = n ++;
    }
    sort(all(query), [&](const Rec &a, const Rec &b) {
        int abl = belong[a.l], bbl = belong[b.l];
        return abl == bbl ? a.r < b.r : abl < bbl;
    });

    vector<int> ans(n);
    for(int bid = 1, id = 0; bid <= bNum; bid ++) {
        int tp = min(bid*bSize, n), l = tp+1, r = tp;
        res = modecnt = 0;
        cnt.assign(n+1, 0);
        for( ; id < n && belong[query[id].l] == bid; id ++) {
            auto [ll, rr, qid] = query[id];
            int bll = belong[ll], brr = belong[rr];
            if(bll == brr) {
                ans[qid] = bf(ll, rr);
            }
            else {
                while(r < rr) add(++ r);
                modecntB = modecnt, resB = res;
                while(l > ll) add(-- l);
                ans[qid] = val[res];
                while(l < tp+1) del(l ++);
                modecnt = modecntB, res = resB;
            }
        }
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