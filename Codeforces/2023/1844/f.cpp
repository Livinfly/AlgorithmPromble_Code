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
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    if(c >= 0) {
        sort(all(a));
    }
    else {
        sort(all(a), greater<int>());
        for(int i = 0; i < n; i ++) {
            int p = i;
            for(int j = n-1; j > i; j --) {
                LL t = 0; // j -> i, i -> i+1
                if (i > 0) {
                    t += abs(a[i] - a[i-1] - c);
                    t -= abs(a[j] - a[i-1] - c);
                }
                if(j > 0) {
                    t += abs(a[j] - a[j-1] - c);
                    t -= abs(a[i] - a[j] - c);
                }
                if (j+1 < n) {
                    t += abs(a[j+1] - a[j] - c);
                    t -= abs(a[j+1] - a[j-1] - c);
                }
                if(!t) {
                    p = j;
                    break;
                }
            }
            a.insert(a.begin() + i, a[p]);
            a.erase(a.begin() + p+1);
            // for(int j = p; j > i; j --) {
            //     swap(a[j], a[j-1]);
            // }
        }
    }
    for(int i = 0; i < n; i ++) {
        cout << a[i] << " \n"[i+1 == n];
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