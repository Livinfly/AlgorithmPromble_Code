#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int n;
int ne[18];
int len, num[18], snum[18];
LL pw10[18], f[18][18];
string s;

LL dfs(int cur, int match, bool isMax) {
    LL &ff = f[cur][match];
    if(!cur) {
        return ff = 0;
    }
    if(!isMax && ~ff) return ff;
    ff = 0;
    int mx = isMax ? num[cur] : 9;
    for(int i = 0; i <= mx; i ++) {
        if(!match && !i) {
            ff += dfs(cur-1, match, isMax && num[cur] == i);
        }
        else {
            int j = match;
            while(j && s[j+1]-'0' != i) j = ne[j];
            if(s[j+1]-'0' == i) j ++;
            // cout << n << ' ' << j << ' ' << i << "\n";
            if(j == n) {
                if(isMax && num[cur] == i) {
                    // cout << snum[cur]+1 << '\n';
                    ff += snum[cur-1]+1;
                }
                else {
                    // cout << pw10[cur] << '\n';
                    ff += pw10[cur-1];
                }
            }
            else {
                ff += dfs(cur-1, j, isMax && num[cur] == i);
            }
        }
    }
    return ff;
}
LL Get(LL x) {
    len = 0;
    while(x) {
        num[++ len] = x % 10;
        x /= 10;
    }
    for(int i = 1; i <= len; i ++) {
        snum[i] = snum[i-1] + num[i]*pw10[i-1];
        // cout << snum[i] << '\n';
    }
    return dfs(len, 0, true);
}
void solve() {
    memset(f, -1, sizeof f);
    cin >> s;
    n = s.size();
    s = " "+s;
    // kmp pw
    for(int i = 2, j = 0; i <= n; i ++) {
        while(j && s[j+1] != s[i]) j = ne[j];
        if(s[j+1] == s[i]) j ++;
        ne[i] = j;
    }
    LL l, r;
    cin >> l >> r;
    // cout << Get(r) << ' ' << Get(l-1) << '\n';
    cout << Get(r) - Get(l-1) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    for(LL t = 1, i = 0; i <= 16; i ++, t *= 10) 
        pw10[i] = t;
    int Tcase = 1;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}