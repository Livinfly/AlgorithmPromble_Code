#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int n;
    cin >> n;
    map<int, int> mp;
    LL sum = 0;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        sum += x, mp[x] ++;
    }
    int Q;
    cin >> Q;
    while(Q --) {
        int a, b;
        cin >> a >> b;
        sum += (LL)(b-a)*mp[a];
        mp[b] += mp[a], mp[a] = 0;
        cout << sum << '\n';
    }
    return 0;
}