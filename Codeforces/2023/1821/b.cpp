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
    vector<int> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    int l = -1, r = -1;
    for(int i = 0; i < n; i ++) {
        if(a[i] != b[i]) {
            l = i;
            break;
        }
    }
    for(int i = n-1; i >= 0; i --) {
        if(a[i] != b[i]) {
            r = i;
            break;
        }
    }
    // cout << l << ' ' << r << '\n';
    for(int i = l-1; i >= 0; i --) {
        if(b[i] <= b[i+1]) l = i;
        else break;
    }
    for(int i = r+1; i < n; i ++) {
        if(b[i-1] <= b[i]) r = i;
        else break;
    }
    cout << l+1 << ' ' << r+1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}
/*
1
5
5 5 5 3 4
5 5 3 5 4
*/