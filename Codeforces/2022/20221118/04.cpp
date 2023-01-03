#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

LL check0(LL x) {
    LL cnt = 0;
    while(x && x%10 == 0) x /= 10, cnt ++;
    return cnt;
}
void solve() {
    LL n, m;
    cin >> n >> m;
    int cnt2 = 0, cnt5 = 0, cnt22 = 0, cnt55 = 0;
    LL t = n;
    while(!(t%2)) t >>= 1, cnt2 ++;
    t = n;
    while(!(t%5)) t /= 5, cnt5 ++;
    t = m;
    while(!(t%2)) t >>= 1, cnt22 ++;
    t = m;
    while(!(t%5)) t /= 5, cnt55 ++;
    LL dx = 0, k = 1;
    if(cnt2 > cnt5) {
        dx = min(cnt2-cnt5, cnt55), cnt55 -= dx;
        for(int i = 0; i < dx; i ++)
            k *= 5;
    }
    else {
        dx = min(cnt5-cnt2, cnt22), cnt22 -= dx;
        for(int i = 0; i < dx; i ++)
            k *= 2;
    }
    for(int i = 0; k*10 <= m; i ++)
        k *= 10;
    for(int i = 9; i > 0; i --)
        if(k*i <= m) {
            k *= i;
        }
    cout << k*n << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int T;
    cin >> T;  // scanf("%d", &T);
    while (T--) solve();
    return 0;
}
/*
1, 
2, 5 
3, 
4, 5
5, 2 4 6 8
6, 5 
7,
8, 5 
9, 
*/