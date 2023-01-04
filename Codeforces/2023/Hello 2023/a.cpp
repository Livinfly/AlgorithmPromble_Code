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
    string s;
    cin >> s;
    for(int i = 1; i < n; i ++) 
        if(s[i] == 'L' && s[i-1] == 'R') {
            cout << 0 << '\n';
            return;
        }
    for(int i = 1; i < n; i ++) 
        if(s[i] == 'R' && s[i-1] == 'L') {
            cout << i << '\n';
            return;
        }
    cout << "-1\n";
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