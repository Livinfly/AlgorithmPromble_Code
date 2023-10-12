#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int n, bSize, bNum;
vector<int> a, belong, cnt, val;
int nid;
map<int, int> mp;
vector<vector<int>> va, f;

void PrevCalc() {
    for(int i = 1; i <= bNum; i ++) {
        int mx = 0, res = 0;
        cnt.assign(n+1, 0);
        for(int j = (i-1)*bSize + 1; j <= n; j ++) {
            int bj = belong[j];
            cnt[a[j]] ++;
            if(cnt[a[j]] > mx || cnt[a[j]] == mx && val[a[j]] < val[res])
                mx = cnt[a[j]], res = a[j];
            f[i][bj] = res;
        }
    }
}
int Query(int l, int r, int c) {
    return (upper_bound(all(va[c]), r) - lower_bound(all(va[c]), l));
}
int Query(int l, int r) {
    int bl = belong[l], br = belong[r], ret = 0, mx = 0;
    if(bl == br) {
        for(int i = l; i <= r; i ++) {
            int t = Query(l, r, a[i]);
            if(t > mx || t == mx && val[a[i]] < val[ret]) {
                mx = t, ret = a[i];
            }
        }
    }
    else {
        ret = f[bl+1][br-1], mx = Query(l, r, ret);
        for(int i = l; i <= n && belong[i] == bl; i ++) {
            int t = Query(l, r, a[i]);
            if(t > mx || t == mx && val[a[i]] < val[ret]) {
                mx = t, ret = a[i];
            }
        }
        for(int i = r; i > 0 && belong[i] == br; i --) {
            int t = Query(l, r, a[i]);
            if(t > mx || t == mx && val[a[i]] < val[ret]) {
                mx = t, ret = a[i];
            }
        }
    }
    return val[ret];
}
void solve() {
    cin >> n;
    bSize = sqrt(n/(log(n)/log(2.0))), bNum = (n-1)/bSize + 1;
    a.resize(n+1), belong.resize(n+1), val.resize(n+1), va.resize(n+1), f.resize(bNum+1);
    for(auto &v : f) 
        v.resize(bNum+1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        belong[i] = (i-1)/bSize + 1;
        if(!mp.count(a[i])) {
            mp[a[i]] = ++ nid;
            val[nid] = a[i];
        }
        a[i] = mp[a[i]];
        va[a[i]].push_back(i);
    }
    PrevCalc();
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        int l, r;
        cin >> l >> r;
        // l = (l+ans-1) % n + 1, r = (r+ans-1) % n + 1;;
        if(l > r) swap(l, r);
        ans = Query(l, r);
        cout << ans << '\n';
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