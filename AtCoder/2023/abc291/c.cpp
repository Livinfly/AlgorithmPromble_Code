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
    string s;
    cin >> n >> s;
    set<PII> S;
    S.insert({0, 0});
    int xx = 0, yy = 0;
    for(auto x : s) {
        if(x == 'R') xx ++;
        else if(x == 'L') xx --;
        else if(x == 'U') yy ++;
        else yy --;
        if(S.count({xx, yy})) {
            cout << "Yes\n";
            return;
        }
        S.insert({xx, yy});
        // cout << xx << ' ' << yy << '\n';
    }
    cout << "No\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}