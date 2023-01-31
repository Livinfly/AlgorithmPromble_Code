#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

LL n, k;
LL Work(LL x) {
    LL cnt = 1;
    LL m = n-(k-x), last = -1;
    while(x < m) {
        // cout << x << '\n';
        if(x == last) {
            cnt = 1e18;
            break;
        }
        last = x;
        x += min(x, (n-x)/2);
        cnt ++;
    }
    return cnt;
}
void solve() {
    cin >> n >> k;
    LL res = 1e18;
    for(int i = 1; i <= k; i ++) {
        res = min(res, Work(i));
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
/*
增长的过程：
阶段一：
    乘二
阶段二：
    += (n-x)/2
所以是先快后慢，很容易得到中间时候放不如在开始或结尾放，所以枚举即可。
*/