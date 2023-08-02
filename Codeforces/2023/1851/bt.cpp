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
    vector<int> odd, even;
    for(auto &x: a) {
        cin >> x;
        if(x & 1) {
            odd.push_back(x);
        }
        else {
            even.push_back(x);
        }
        x &= 1;
    }
    sort(all(odd)), sort(all(even));
    int p1 = 0, p2 = 0;
    for(auto &x: a) {
        if(x) {
            x = odd[p1++];
        }
        else {
            x = even[p2++];
        }
    }
    auto b = a;
    sort(all(b));
    if(a == b) {
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