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
    vector<int> a(n+1), mp(n+1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i], mp[a[i]] ++, a[i] += a[i-1];
    int cnt = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = i+1; j <= n; j ++)
            if(a[j]-a[i-1] <= n)
                cnt += mp[a[j]-a[i-1]], mp[a[j]-a[i-1]] = 0;
    cout << cnt << '\n';
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