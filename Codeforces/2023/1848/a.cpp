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
    LL s, k;
    cin >> s >> k;
    LL ts = s;
    if(!s) {
        cout << "0\n";
        return;
    }
    // 2 4 8 6, 2 4 8 6, 1->(), 3->6(), 0 5
    LL p = 0, ans = 0;
    for(p = 0; p < k; p ++) {
        ans = max(ans, s * (k-p));
        if(s + s%10 == 2*s) {
            s += s%10;
        }
        else {
            break;
        }
    }
    s = ts;
    if(s % 5) {
        p = 0;
        while(s%10 != 2 && p < k) {
            ans = max(ans, s * (k-p));
            s += s%10;
            p++;
        }
        ans = max(ans, s * (k-p));
        LL t = (k-p) / 4;
        s += t*20;
        p += t*4;
        while(p < k) {
            ans = max(ans, s * (k-p));
            s += s%10;
            p++;
            cerr << p << ' ' << s << '\n';
        }
        ans = max(ans, s * (k-p));
    }
    cout << ans << '\n';
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