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
    LL a, b;
    cin >> a >> b;
    LL cnt = 0;
    while(a != b) {
        if(a < b) {
            cnt += (b-a-1)/a+1;
            b -= ((b-a-1)/a+1)*a;
        }
        if(b < a) {
            cnt += (a-b-1)/b+1;
            a -= ((a-b-1)/b+1)*b;
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}