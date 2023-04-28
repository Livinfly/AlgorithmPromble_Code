#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int n, m;

int ask(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    int res;
    cin >> res;
    return res;
}
void answer(int x, int y) {
    cout << "! " << x << ' ' << y << endl;
}
void solve() {
    cin >> n >> m;
    int rx, ry;
    int mx1 = ask(1, 1);
    if(mx1+1 <= n && mx1+1 <= m) {
        int mx2 = ask(1+mx1, 1+mx1);
        int mx3 = ask(1+mx1, 1+mx1-mx2);
        if(mx3 == 0) rx = 1+mx1, ry = 1+mx1-mx2;
        else if(mx3 == mx2) {
            rx = 1+mx1-mx2, ry  = 1+mx1;
    }
    }
    else if(mx1+1 > n) {
        ry = mx1+1;
        int mx2 = ask(1, ry);
        rx = 1+mx2;
    }
    else if(mx1+1 > m) {
        rx = mx1+1;
        int mx2 = ask(rx, 1);
        ry = 1+mx2;
    }
    answer(rx, ry);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}