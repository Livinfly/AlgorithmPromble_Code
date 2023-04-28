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
    int q;
    cin >> q;
    LL L = 1, R = 1e18;
    while(q --) {
        LL op, a, b, n;
        cin >> op >> a >> b;
        if(op == 1) {
            cin >> n;
            LL l, r;
            if(n == 1) l = 1, r = a;
            else {
                l = (n-2)*(a-b)+a+1;
                r = (n-1)*(a-b)+a;
            }
            if(l <= R && r >= L) {
                cout << 1 << ' ';
                L = max(L, l);
                R = min(R, r);
            }
            else {
                cout << 0 << ' ';
            }
            // cout << "\nL R " << L << ' ' << R << '\n';
        }
        else {
            // 好像确实转化成长度会有点细节问题。。
            // LL l = (L-a-1)/(a-b)*(a-b)+a, r = l+a-b;
            // // cout << "\nl r " << l << ' ' << r << '\n';
            // if(R <= a) {
            //     cout << 1 << ' ';
            // }
            // else if(r < R) {
            //     cout << -1 << ' ';
            // }
            // else {
            //     cout << (L-a-1)/(a-b)+2 << ' ';
            // }
            LL t1 = L <= a ? -1LL : (L-a-1)/(a-b);
            LL t2 = R <= a ? -1LL : (R-a-1)/(a-b);
            // cout << '\n' << t1 << ' ' << t2 << '\n';
            if(t1 == t2)
                cout << t1+2 << ' ';
            else 
                cout << -1 << ' ';
        }
    }
    cout << '\n';
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
/*
1
9
1 7 3 6
1 2 1 8
2 5 1
1 10 9 7
1 8 1 2
1 10 5 8
1 10 7 7
2 7 4
1 9 4 2

1
3
2 3 2
1 3 1 3
2 2 1
*/