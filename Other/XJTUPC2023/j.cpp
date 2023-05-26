#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef unsigned int UI;
typedef long long LL;
typedef pair<int, int> PII;

struct Rec {
    int l, r, qid;
};

int n, m, l, r;
UI ans, ans0, ansL, ansR;
int bNum, bSize;
vector<int> a, belong, cnt, pre, ne, p;
vector<Rec> query;

void add(int x, bool left) {
	if(!cnt[a[x]]) ans0 ++;
	cnt[a[x]] ++;
    if(left) {
    	ansL += min(r, ne[x]-1) - x + 1;
    	ansR += ans0;
    	ans += ansL;
    }
    else {
    	ansL += ans0;
    	ansR += x - max(l, pre[x]+1) + 1;
    	ans += ansR;
    }
}
void del(int x, bool left) {
    if(left) {
    	ans -= ansL;
    	ansL -= min(r, ne[x]-1) - x + 1;
    	ansR -= ans0;
    }
    else {
    	ans -= ansR;
    	ansL -= ans0;
    	ansR -= x - max(l, pre[x]+1) + 1;
    }
    cnt[a[x]] --;
    if(!cnt[a[x]]) ans0 --;
}
void solve() {
    cin >> n >> m;
    a.resize(n+1), belong.resize(n+1), cnt.resize(n+1);
    query.resize(m), pre.resize(n+1), ne.resize(n+1), p.resize(n+1);
    if(n > m) bSize = n/sqrt(m);
    else bSize = sqrt(n);
    bNum = (n-1)/bSize + 1;
    int mx = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        belong[i] = (i-1)/bSize + 1;
    }
    p.assign(n+1, 0);
    for(int i = 1; i <= n; i ++) {
    	pre[i] = p[a[i]];
    	p[a[i]] = i;
    }
    p.assign(n+1, n+1);
    for(int i = n; i > 0; i --) {
    	ne[i] = p[a[i]];
    	p[a[i]] = i;
    }
    for(int i = 0; i < m; i ++) {
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

    vector<UI> anss(m);
    l = 1, r = 0;
    for(int i = 0; i < m; i ++) {
        auto [ll, rr, qid] = query[i];
        while(l > ll) add(-- l, true);
        while(r < rr) add(++ r, false);
        while(l < ll) del(l ++,	true);
        while(r > rr) del(r --, false);
        anss[qid] = ans;
    }
    for(int i = 0; i < m; i ++) {
        cout << anss[i] << '\n';
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