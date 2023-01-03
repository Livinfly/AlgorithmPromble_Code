#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int cost[26][26];

void PrevCalu() {
    for(int i = 0; i < 26; i ++) 
        cost[0][i] = cost[i][0] = i, cost[25][i] = cost[i][25] = 25-i;
    for(int i = 1; i < 25; i ++)
        for(int j = i+1; j < 25; j ++)
            cost[i][j] = cost[j][i] = abs(i-j);
}
int GetCost(string a, string b) {
    int ans = 0;
    for(int i = 0; i < a.size(); i ++)
        ans += cost[a[i]-'a'][b[i]-'a'];
    return ans;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(auto &x : s) cin >> x;
    int res = 1e9;
    for(int i = 0; i < n; i ++)
        for(int j = i+1; j < n; j ++)
            res = min(res, GetCost(s[i], s[j]));
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    PrevCalu();
    int Tcase;
    cin >> Tcase;  // scanf("%d", &Tcase);
    while (Tcase--) solve();
    return 0;
}