#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 11;

int n, m;
int s[N];

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int c;
        cin >> c;
        for(int j = 0; j < c; j ++) {
            int a;
            cin >> a;
            s[i] |= (1<<a-1);
        }
    }
    int res = 0;
    for(int i = 1; i < (1<<m); i ++) {
        int sum = 0;
        for(int j = 0; j < m; j ++) {
            if(i>>j & 1) {
                sum |= s[j];
            }
        }
        // cout << "----\n";
        // cout << sum << ' ' << (1<<n)-1 << '\n';
        if(sum == (1<<n)-1) {
            res ++;
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
    // time_t t1 = clock();
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}