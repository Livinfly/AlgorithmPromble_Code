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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<int> pos, neg;
    int mx1 = 0, mx2 = 0, p1 = 0, p2 = 0;
    for(int i = 0; i < n; i ++) {
        if(a[i] > 0) {
            pos.push_back(i+1);
            if(a[i] > mx1) {
                mx1 = a[i];
                p1 = i+1;
            }
        }
        if(a[i] < 0) {
            neg.push_back(i+1);
            if(-a[i] > mx2) {
                mx2 = -a[i];
                p2 = i+1;
            }
        }
    }
    vector<array<int, 2>> ans;
    bool ispos = true;
    if(mx1 > mx2) {
        if(neg.size() <= 12) {
            for(auto x: neg) {
                ans.push_back({x, p1});
            }
        }
        else {
            for(int i = 0; i < 5; i ++) {
                ans.push_back({p2, p2});
            }
            for(auto x: pos) {
                ans.push_back({x, p2});
            }
            ispos = false;
        }
    }
    else {
        if(pos.size() <= 12) {
            for(auto x: pos) {
                ans.push_back({x, p2});
            }
            ispos = false;
        }
        else {
            for(int i = 0; i < 5; i ++) {
                ans.push_back({p1, p1});
            }
            for(auto x: neg) {
                ans.push_back({x, p1});
            }
        }
    }
    if(ispos) {
        for(int i = 1; i < n; i ++) {
            ans.push_back({i+1, i});
        }
    }
    else {
        for(int i = n; i > 1; i --) {
            ans.push_back({i-1, i});
        }
    }
    cout << ans.size() << '\n';
    for(auto [x, y]: ans) cout << x << ' ' << y << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}