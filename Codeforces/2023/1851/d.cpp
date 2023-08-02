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
    vector<LL> a(n+2), b(n+2);
    for(int i = 1; i < n; i ++) cin >> a[i];
    for(int i = 1; i < n; i ++) b[i] = a[i]-a[i-1];
    LL sum = 1LL*n*(n+1)/2;
    if(a[n-1] > sum) {
        cout << "No\n";
        return;
    }
    vector<bool> vis(n+2);
    LL s = 0;
    int cnt = 0;
    for(int i = 1; i < n; i ++) {
        if(b[i] >= 2*n) {
            cout << "No\n";
            return;
        }
        if(b[i] > n || vis[b[i]]) {
            s = b[i];
            cnt++;
        }
        if(b[i] <= n) {
            vis[b[i]] = true;
        }
    }
    if(cnt >= 2) {
        cout << "No\n";
        return;
    }
    if(a[n-1] < sum) {
        for(int i = 1; i <= n; i ++) {
            if(!vis[i]) {
                if(a[n-1] + i != sum) {
                    cout << "No\n";
                }
                else {
                    cout << "Yes\n";
                }
                return;
            }
        }
    }
    vector<int> no;
    for(int i = 1; i <= n; i ++) {
        if(!vis[i]) no.push_back(i);
    }
    LL ss = 0;
    for(auto x: no) ss += x;
    if(ss == s && no.size() == 2) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}