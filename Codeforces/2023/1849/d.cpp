#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+2);
    vector<bool> red(n+2);
    red[0] = red[n+1] = true;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    int ans = 0;
    if(a[1] > 0) {
        ans++;
        red[1] = red[min(2, n)] = true;
    }
    if(a[n] > 0) {
        ans++;
        red[max(1, n-1)] = red[n] = true;
    }
    for(int i = 1; i <= n; i ++) {
        if(a[i] == 2) {
            if(!red[i]) {
                ans++;
                red[i-1] = red[i] = red[i+1] = true;
            }
            else {
                red[i+1] = true;
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        if(a[i] == 1) {
            if(!red[i]) {
                ans++;
                if(!red[i-1]) red[i-1] = red[i] = true;
                else red[i] = red[i+1] = true;
            }
            else {
                if(!red[i-1]) red[i-1] = red[i] = true;
                else red[i] = red[i+1] = true;
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        if(!red[i]) ans++;
    }
    cout << ans << '\n';
}
void solve1() {
    int n;
    cin >> n;
    vector<int> a(n+2);
    vector<bool> red(n+2);
    red[0] = red[n+1] = true;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    int ans = 0;
    for(int l = 1, r; l <= n; l = r+1) {
        int mx = 0;
        while(l <= n && !a[l]) l++;
        if(l > n) break;
        r = l;
        while(r <= n && a[r]) {
            mx = max(mx, a[r]);
            red[r++] = true;
        }
        r--;
        ans++;
        if(mx == 2) {
            red[l-1] = red[r+1] = true;
        }
        if(mx == 1) {
            if(!red[l-1]) red[l-1] = true;
            else red[r+1] = true;
        }
        // cerr << l << ' ' << r << ' ' << mx << '\n';
    }
    for(int i = 1; i <= n; i ++) {
        if(!red[i]) ans++;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve1();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}