#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int work(int x) {
    bool flag = false;
    int t = x & 1, cnt = 0;
    while(x && (x & 1) == t) {
        x /= 2, cnt ++;
        flag = true;
    }
    if(flag)
        return cnt;
    return 1e9;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int &x : a) cin >> x, sum += x;
    if(sum & 1) {
        int res = 1e9;
        for(int x : a) {
            res = min(res, work(x));
        }
        cout << res << '\n';
    }
    else 
        cout << "0\n";
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