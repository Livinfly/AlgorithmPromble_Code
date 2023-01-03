#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

char s[25];

void solve() {
    int n; 
    cin >> n;
    cin >> s;
    int mn = 1, mx = 1<<n;
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; s[i]; i ++) {
        if(s[i] == '0') {
            mx -= 1<<cnt0;
            cnt0 ++;
        }
        else {
            mn += 1<<cnt1;
            cnt1 ++;
        }
    }
    // cout << mn << '\n';
    // cout << mx << '\n';
    for(LL i = mn; i <= mx; i ++)
        cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    solve();
    return 0;
}