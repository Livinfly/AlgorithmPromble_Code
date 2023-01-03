#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

char ch[5] = {'Y', 'e', 's'};

void solve() {
    string s;
    cin >> s;
    int p = 0;
    for(p = 0; p < 3; p ++) 
        if(s[0] == ch[p]) break;
    if(p == 3) {
        cout << "NO\n";
        return;
    }
    for(auto x : s) {
        if(x != ch[p]) {
            cout << "NO\n";
            return;
        }
        p = (p+1)%3;
    }
    cout << "YES\n";
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