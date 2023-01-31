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
    int n;
    cin >> n;
    vector<LL> a(n);
    for(auto &x : a) cin >> x;
    LL chaos = 0;
    for(int i = 1; i < n; i ++) {
        chaos += abs(a[i]-a[i-1]);
    }
    set<LL> chg;
    for(int i = 1; i < n; i ++) {
        chg.insert(abs(a[i]+a[i-1])-abs(a[i]-a[i-1]));
    }
    int cnt = 0;
    LL t = 0;
    for(auto x : chg) {
        if(x >= 0) break; // 不一定施法
        t += x;
        cnt ++;
        if(cnt == 2) break;
    }
    for(int i = 1; i < n-1; i ++) //只变一个
        t = min(t, abs(a[i]+a[i-1])-abs(a[i]-a[i-1])+abs(a[i]+a[i+1])-abs(a[i]-a[i+1]));
    chaos += t;
    cout << chaos << '\n';
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