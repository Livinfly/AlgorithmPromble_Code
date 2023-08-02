#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

struct rec {
    int id;
    LL a, b;
    bool operator < (const rec &o) const {
        LL t1 = a * (o.a+o.b), t2 = o.a * (a+b);
        if(t1 == t2) {
            return id < o.id;
        }
        return t1 > t2;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<rec> p(n+1);
    for(int i = 1; i <= n; i ++) {
        auto &[id, a, b] = p[i];
        id = i;
        cin >> a >> b;
    }
    sort(1+all(p));
    for(int i = 1; i <= n; i ++) {
        cout << p[i].id << " \n"[i == n];
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