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
    if(n == 3) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if(n % 2) {
        for(int i = 0; i < n; i ++) 
            if(i % 2) cout << -n/2 << " \n"[i == n-1];
            else cout << n/2-1 << " \n"[i == n-1];
    }
    else {
        for(int i = 0; i < n; i ++) 
            if(i % 2) cout << 1 << " \n"[i == n-1];
            else cout << -1 << " \n"[i == n-1];
    }
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