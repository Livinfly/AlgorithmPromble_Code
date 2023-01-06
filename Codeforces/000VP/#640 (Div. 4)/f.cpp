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
    int a, b, c;
    cin >> a >> b >> c;
    for(int i = 0; i < a; i ++)
        if(!i) cout << "00";
        else cout << "0";
    if(!a && b) {
        cout << "0";
    }
    for(int i = 0, t = 1; i < b-(b+1)%2; i ++, t = 1-t) {
        cout << t; 
    }
    if(!b && c) cout << "1";
    for(int i = 0; i < c; i ++) {
        cout << "1";
    }
    if(b && (b+1)%2) cout << "0\n";
    else cout << '\n';
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