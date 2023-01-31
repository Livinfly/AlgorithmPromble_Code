#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 1e9+7;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    vector<LL> s(n+1);
    map<int, int> mp;
    mp[INF] = n+1, mp[0] = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(!mp.count(a[i])) {
            mp[a[i]] = i;
        }
    }
    // process!!!
    for(auto it = ++mp.rbegin(); it != mp.rend(); it ++) {
        auto prevIt = it;
        prevIt --;
        it->second = min(it->second, prevIt->second);
        // cout << it->first << ' ' << it->second << ':' << prevIt->first << ' ' << prevIt->second << '\n';
    }
    // for(auto x:mp) {
    //     cout << x.first << ' ' << x.second << '\n';
    // }
    for(int i = 1; i < a.size(); i ++)
        s[i] += s[i-1]+a[i];
    while(q --) {
        LL x;
        cin >> x;
        int p = mp.upper_bound(x)->second-1;
        cout << s[p] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int T;
    cin >> T;  // scanf("%d", &T);
    while (T--) solve();
    return 0;
}