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
    vector<string> s(8);
    for(auto &x : s) cin >> x;
    for(int i = 1; i < 7; i ++)
        for(int j = 1; j < 7; j ++)
            if(s[i][j] == '#' && s[i-1][j-1] == '#' && 
                s[i-1][j-1] == s[i+1][j+1] && 
                s[i-1][j+1] == s[i+1][j-1] && 
                s[i-1][j-1] == s[i-1][j+1]) {
                cout << i+1 << ' ' << j+1 << '\n';
                return;
            }
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