#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6+10;

int n;
int f[N];
int cost[10] = {
    6, 2, 5, 5, 4, 5, 6, 3, 7, 6
};
/*
6 = 3+3 -> 7*2 = 14
7 = 3+4 -> 7+4 = 11
5 = 3+2 -> 7+1 = 8
4 = 4 -> 4
3 = 3 -> 7
2 = 2 -> 1
*/
void solve() {
    cin >> n;
    map<int, int> mp;
    mp[6] = 14, mp[7] = 11, mp[5] = 8, mp[4] = 4;
    mp[3] = 7, mp[2] = 1;
    memset(f, 0xcf, sizeof f);
    f[0] = 0;
    for(auto it : mp) {
        int v = it.fi, w = it.se;
        for(int j = v; j <= n; j ++)
            f[j] = max(f[j], f[j-v]+w);
    }
    cout << f[n] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    freopen("auxiliary.in", "r", stdin);
    freopen("auxiliary.out ", "w", stdout);
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    return 0;
}
/*
贪心好像也可以做，直接模3，然后稍微分类下就行
*/