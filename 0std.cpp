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
    int a, b;
    cin >> a >> b;
    if(a+1 == b) {
        cout << "-1\n";
        return;
    }
    if(__gcd(a, b) > 1) {
        cout << "0\n";
        return;
    }
    int dx = b-a;
    vector<int> divs;
    for(int i = 2; i <= dx/i; i ++) {
        if(dx % i == 0) {
            divs.push_back(i);
            do {
                dx /= i;
            } while(dx % i == 0);
        }
    }
    if(dx > 1) divs.push_back(dx);
    int res = (int)1e9;
    for(int x : divs) {
        res = min(res, x-(a-a/x*x));
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