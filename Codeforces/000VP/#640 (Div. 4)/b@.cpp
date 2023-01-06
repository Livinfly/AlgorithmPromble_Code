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
    if(n % 2 == 0 && n >= 2*k) {
        cout << "YES\n";
        int a = 2, b = n-2*(k-1);
        cout << b << ' ';
        for(int i = 0; i < k-1; i ++)
            cout << a << ' ';
        cout << '\n';
        return;
    }
    if(n % 2 == k % 2 && n >= k) {
        cout << "YES\n";
        int a = 1, b = n-(k-1);
        cout << b << ' ';
        for(int i = 0; i < k-1; i ++)
            cout << a << ' ';
        cout << '\n';
        return;
    }
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