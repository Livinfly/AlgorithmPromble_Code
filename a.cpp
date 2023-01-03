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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int t = 0;
    while((1<<t)+1 < n) t ++;
    // cout << t << '\n';
    int res = 0;
    if(n & 1) {
        for(int i = 0; i < min(2, n); i ++)
            res = res + a[i]*(t+1);
        for(int i = 2; i < n; i ++)
            res = res + a[i]*t;
        cout << res << '\n';
    }
    else {
        for(int i = 0; i < n; i ++) 
            res = res + a[i]*t;
        cout << res << '\n';
    }
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