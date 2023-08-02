// #pragma GCC optimize(2)

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
    bitset<100> b;
    cout << 8*sizeof(b) << '\n';
    vector<bool> a;
    cout << a.capacity() << '\n';
    a.push_back(true);
    cout << a.capacity() << '\n';
    a.push_back(false);
    cout << a.capacity() << '\n';
    a.push_back(true);
    cout << a.capacity() << '\n';
    a.resize(100);
    cout << a.capacity() << '\n';
    for(int i = 0; i < a.size(); i ++) {
        cout << a[i] << '\n';
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
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}