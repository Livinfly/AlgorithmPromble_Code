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
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    sort(all(a));
    reverse(all(a));
    for(int i = 1; i < a.size(); i ++)
        a[i] += a[i-1];
    while(Q --) {
        int x;
        cin >> x;
        int l = 0, r = n;
        while(l < r) {
            int mid = l+r >> 1;
            if(a[mid] >= x) r = mid;
            else l = mid+1;
        }
        r ++;
        if(r == n+1) r = -1;
        cout << r << '\n';
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