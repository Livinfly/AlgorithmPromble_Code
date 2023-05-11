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

int n, bSize, bNum, ansx;
vector<int> a, belong, cnt;
vector<Rec> query;
map<int, int> num;

void add(int x) {
    //
}
void del(int x) {
    //
}
void solve() {
    cin >> n;
    a.resize(n+1), belong.resize(n+1), query.resize(n+1), cnt.resize(n+1);
    bSize = sqrt(n), bNum = (n-1)/bSize + 1;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        belong[i] = (i-1)/bSize + 1;
    }
    for(int i = 1; i <= n; i ++) {
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
    vector<int> ans(n+1);
    int l = 1, r = 0;
    for(int i = 1; i <= n; i ++) {
        auto [ll, rr, qid] = query[i];
        while(l < ll) del(l ++);
        while(l > ll) add(-- l);
        while(r < rr) add(++ r);
        while(r > rr) del(r --);
        ans[qid] = ansx;
    }
    for(int i = 1; i <= n; i ++) {
        cout << ans[i] << " \n"[i == n];
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