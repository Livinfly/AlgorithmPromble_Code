#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int n, k;

bool ok(int mid) {
    
}
void solve() {
    scanf("%d%d", &k, &n);
    int l = 1, r = n-1;
    while(l < r) {
        int mid = l+r>>1;
        if(ok(mid)) l = mid;
        else r = mid-1;
    }
    
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int Tcase;
    scanf("%d", &Tcase); // cin >> Tcase;
    while (Tcase--) 
        solve();
    return 0;
}