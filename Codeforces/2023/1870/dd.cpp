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
    int n; cin >> n;
    vector<int> a(n+1), c(n+1);
    for(int i = 1; i <= n; i ++) cin >> c[i];
    int k; cin >> k;
    vector<PII> stk;
    stk.reserve(n);
    for(int i = n; i >= 1; i --) {
        if(stk.empty() || stk.back().fi > c[i]) stk.push_back({c[i], i});
    }
    for(int i = 0; i+1 < stk.size(); i ++) {
        stk[i].fi -= stk[i+1].fi;
    }
    
    int l = 0, mn = k/stk.back().fi;
    while(!stk.empty()) {
        mn = min(mn, k / stk.back().fi);
        for(int i = l; i < stk.back().se; i ++) {
            cout << mn << ' ';
        }
        l = stk.back().se;
        k %= stk.back().fi;
        stk.pop_back();
    }
    cout << '\n';
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}