#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        auto &[x, id] = a[i];
        cin >> x; id = i;
    }
    sort(all(a));
    int l = 0, r = n-1, m = n;
    vector<int> ans(n);
    while(l <= r && ((a[l][0] == n-1-r) ^ (a[r][0] == n-l))) {
        if(a[l][0] == n-1-r) ans[a[l++][1]] = -(m--);
        else ans[a[r--][1]] = m--;
    }
    if(l == r+1) {
        cout << "Yes\n";
        for(auto x: ans) cout << x << ' ';
        cout << '\n';
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
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}