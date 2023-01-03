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
    int n, k;
    cin >> n >> k;
    vector<int> cnt(31);
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        for(int i = 0; i < 31; i ++)
            if(x >> i & 1) cnt[i] ++;
    }
    int res = 0;
    for(int i = 30; i >= 0; i --) {
        if(n-cnt[i] <= k) res |= 1<<i, k -= n-cnt[i];
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int Tcase;
    cin >> Tcase;  // scanf("%d", &Tcase);
    while (Tcase--) solve();
    return 0;
}