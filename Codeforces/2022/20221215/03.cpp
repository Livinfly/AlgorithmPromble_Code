#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10, P = 998244353;

char s[N];

void solve() {
    int n;
    cin >> n;   
    cin >> s;
    LL res = 1, t = 1;
    for(int i = 1; s[i]; i ++) {
        if(s[i] == s[i-1]) t = t*2LL % P;
        else t = 1;
        res = (res+t) % P;
    }
    cout << res << '\n';
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