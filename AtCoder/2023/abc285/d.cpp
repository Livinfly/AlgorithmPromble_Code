#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10;

int fa[N];

int GetFa(int x) {
    return (x == fa[x]) ? x : fa[x] = GetFa(fa[x]);
}

void solve() {
    int n;
    cin >> n;
    map<string, int> mp;
    for(int i = 0; i < N-10; i ++)
        fa[i] = i;
    int idx = 0;
    for(int i = 1; i <= n; i ++) {
        string s, t;
        cin >> s >> t;
        if(!mp.count(s)) 
            mp[s] = idx ++;
        if(!mp.count(t))
            mp[t] = idx ++;
        int fx = GetFa(mp[s]), fy = GetFa(mp[t]);
        if(fx == fy) {
            cout << "No\n";
            return;
        }
        fa[fy] = fx;
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    return 0;
}
/*
不熟（
*/