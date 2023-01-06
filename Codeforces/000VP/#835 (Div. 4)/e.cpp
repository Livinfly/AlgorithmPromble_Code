#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10;

int n;
int a[N], s[N];

LL GetInv() {
    LL ans = 0;
    for(int i = 1; i <= n; i ++) {
        s[i] = s[i-1]+a[i];
        if(!a[i])
            ans += s[i];
    }
    return ans;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    int p1 = -1, p2 = -1;
    for(int i = 1; i <= n; i ++)
        if(a[i] == 0) {
            p1 = i;
            break;
        }
    for(int i = n; i >= 1; i --) {
        if(a[i] == 1) {
            p2 = i;
            break;
        }
    }
    LL res = GetInv();
    if(p1 != -1) {
        a[p1] = 1-a[p1];
        res = max(res, GetInv());
        a[p1] = 1-a[p1];
    }
    if(p2 != -1) {
        a[p2] = 1-a[p2];
        res = max(res, GetInv());
        a[p2] = 1-a[p2];
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int Tcase;
    cin >> Tcase;  // scanf("%d", &Tcase);
    while (Tcase--) solve();
    return 0;
}
/*
可以不操作
*/