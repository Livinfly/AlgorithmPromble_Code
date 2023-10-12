// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

void solve() {
    string s; cin >> s;
    int n = s.size();
    int top = 0;
    int ans = -1, min0 = 1e9, flag1 = 0, flag0 = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '+') {
            top++;
            flag0 = 1;
        }
        else if(s[i] == '-') {
            top--;
            if(top < min0) flag1 = 1;
        }
        else if(s[i] == '1') {
            if(top >= 2 && ans != -1 && ans != s[i]-'0' && !flag1) {
                cout << "NO\n";
                return;
            }
            min0 = 1e9;
            flag0 = flag1 = 0;
            ans = 1;
        }
        else {
            if(top < 2 || (ans != -1 && ans != s[i]-'0' && !flag0)) {
                cout << "NO\n";
                return;
            }
            min0 = min(min0, top);
            flag0 = flag1 = 0;
            ans = 0; // 0..
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}