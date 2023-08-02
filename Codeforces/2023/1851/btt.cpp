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
    vector<int> a(n);
    multiset<int> odd, even;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(a[i] & 1) {
            odd.insert(a[i]);
        }
        else {
            even.insert(a[i]);
        }
        a[i] %= 2;
    }
    for(int i = 0; i < n; i ++) {
        if(a[i]) {
            a[i] = *odd.begin();
            odd.erase(odd.begin());
        }
        else {
            a[i] = *even.begin();
            even.erase(even.begin());
        }
    }
    bool ok = true;
    for(int i = 1; i < n; i ++) {
        if(a[i] < a[i-1]) {
            ok = false;
            break;
        }
    }
    if(ok) {
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