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
    map<int, vector<int>> mp;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        mp[x].push_back(i);
    }
    int a = 0, res = 0, l = 1, r = 1;
    for(auto it : mp) {
        auto vec = it.second;
        int b = it.first, mn = 0, tl = vec[0];
        for(int i = 0; i < vec.size(); i ++) {
            int p = vec[i];
            int cur = i-(p-i);
            if(cur < mn) {
                mn = cur;
                tl = p;
            }
            int tres = cur-mn+1;
            if(tres > res) {
                res = tres;
                a = b;
                l = tl;
                r = p;
            }
        }
    }
    cout << a << ' ' << l << ' ' << r << '\n';
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