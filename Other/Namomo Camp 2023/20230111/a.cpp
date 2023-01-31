#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5+10;

LL n;
LL a[N];



void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a+1, a+n+1);
    LL res = 0;
    for(int i = 1; i <= n; i ++) {
        if(a[i] > i) {
            res += 2*(min(a[i], n)-i);
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    return 0;
}