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
    set<int> x, y;
    bool flag1 = false, flag2 = false;
    for(int i = 0; i < 3; i ++) {
        int a, b;
        cin >> a >> b;
        if(x.find(a) == x.end()) x.insert(a);
        else flag1 = true;
        if(y.find(b) == y.end()) y.insert(b);
        else flag2 = true;
    }
    bool flag = (flag1 &flag2);
    if(flag) cout << "NO\n";
    else cout << "YES\n"; 
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