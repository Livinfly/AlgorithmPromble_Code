#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

LL cnt[2];

void solve() {
    memset(cnt, 0, sizeof cnt);
    int q;
    cin >> q;
    bool ok[2] = {};
    while(q --) {
        LL a, b;
        string s;
        cin >> a >> b >> s;
        for(auto x : s) {
            if(x == 'a') cnt[a-1] += b;
            else ok[a-1] = true;
        }
        string res;
        if(ok[1] || !ok[0] && cnt[0] < cnt[1]) 
            res = "YES\n";
        else 
            res = "NO\n";
        cout << res;
    }
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
/*
    possible to arrange !
    smallest < biggest
*/