#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int l, r, x;
int a, b;
bool work(int op) {
    if(!op) return a == b;
    if(op == 1) return a-b >= x;
    if(op == 2) return a+x <= r || b-x >= l;
    if(op == 3) return a-x >= l && b+x <= r && (b+x)-(a-x) >= x;
}
void solve() {
    cin >> l >> r >> x;
    cin >> a >> b;
    if(a < b) swap(a, b); // a >= b
    if(work(0)) cout << "0\n";
    else if(work(1)) cout << "1\n";
    else if(work(2)) cout << "2\n";
    else if(work(3)) cout << "3\n";
    else cout << "-1\n";
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