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
    vector<int> a(n+2);
    a[0] = 1e9+7, a[n+1] = 1e9+7;
    for(int i = 1; i <= n; i ++) 
        cin >> a[i];
    bool ok = false;
    int cnt = 0;
    for(int i = 1; i <= n+1; i ++) {
        if(a[i] < a[i-1]) 
            ok = true;
        else if(a[i] > a[i-1]) {
            if(ok) cnt ++;
            ok = false;
        }
    }
    // cout << "?? " << cnt << '\n';
    if(cnt == 1) 
        cout << "YES\n";
    else
        cout << "NO\n";
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