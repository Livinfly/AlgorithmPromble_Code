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

LL n, c, d;
LL a[N];

bool cmp(LL a, LL b) {
    return a > b;
}
bool ok(LL mid) { // 隔mid天，mid+1一组
    LL ans = 0;
    mid ++;
    for(int i = 1; i <= min(n, mid); i ++) // min(n, ...), mid++后大于n的情况
        ans += d/mid * a[i];
    for(int i = 1; i <= min(n, d%mid); i ++) // !
        ans += a[i];
    return ans >= c;
}
void solve() {
    cin >> n >> c >> d;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a+1, a+n+1, cmp);
    LL l = -1, r = d;
    // cout << "mid:\n";
    while(l < r) {
        LL mid = l+r+1>>1;
        // cout << mid << '\n';
        if(ok(mid)) l = mid;
        else r = mid-1;
    }
    // cout << "r = " << r << '\n';
    if(!~r) 
        cout << "Impossible\n";
    else if(r == d) 
        cout << "Infinity\n";
    else 
        cout << r << '\n';
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