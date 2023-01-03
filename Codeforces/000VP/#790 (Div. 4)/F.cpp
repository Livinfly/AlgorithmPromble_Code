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
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    while(n --) {
        int x;
        cin >> x;
        mp[x] ++;
    }
    int last = -1, p1 = 0, p2 = -1, t = -1;
    for(auto a : mp) {
        int x = a.first, c = a.second;
        if(c < k) continue;
        if(last != x-1) t = x;
        last = x;
        if(p2-p1 < x-t) p1 = t, p2 = x;
    }
    if(!p1) 
        cout << "-1\n";
    else 
        cout << p1 << ' ' << p2 << '\n';
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