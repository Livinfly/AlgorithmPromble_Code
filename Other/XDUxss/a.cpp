#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    int n, m, cnt = 0;
    scanf("%d%d", &n, &m);
    while(m --) {
        int k;
        cin >> k;
        bool flag = false;
        for(int i = 0; i < k; i ++) {
            int h1, m1, h2, m2;
            scanf("%d:%d-%d:%d", &h1, &m1, &h2, &m2);
            int sum = h2*60+m2-h1*60-m1;
            if(sum >= 30) flag = true;
        }
        if(flag) cnt ++;
    }
    if(cnt >= n) puts("ZhongYuDaWanKaLe");
    else puts("WanDanTiYuGuaLe");
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    solve();
    return 0;
}