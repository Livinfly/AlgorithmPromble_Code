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
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    sort(all(a));
    reverse(all(a));
    for(int i = 1; i < a.size(); i ++) {
        if(a[i] != a[0]) {
            swap(a[i], a[1]);
            break;
        }
    }
    int sum = 0;
    for(auto x : a) {
        if(x == sum) {
            cout << "NO\n";
            return;
        }
        sum += x;
    }
    cout << "YES\n";
    for(auto x : a) 
        cout << x << ' ' ;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int Tcase;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    return 0;
}