#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int work(string s, char ch) {
    bool ff = true;
    for(int i = 0; i < s.size(); i ++)
        if(s[i] != ch) {
            ff = false;
            break;
        }
    if(ff) return 0;
    string t = "";
    int cnt = 0;
    while(1) {
        cnt ++;
        int p = -2;
        for(int i = 0; i < s.size(); i ++) {
            // cout << p << endl;
            if(s[i] != ch && i-p > 1) {
                p = i;
                continue;
            }
            t += s[i];
        }
        // cout << ch << ' ' << s << ' ' << t << endl;
        bool ff = true;
        for(int i = 0; i < t.size(); i ++)
            if(t[i] != ch) {
                ff = false;
                break;
            }
        if(ff) break;
        s = t;
        t = "";
    }
    return cnt;
}
void solve() {
    string s;
    cin >> s;
    int res = 1e9;
    for(char ch = 'a'; ch <= 'z'; ch ++) {
        // cout << ch << ' ' << work(s, ch) << '\n';
        res = min(res, work(s, ch));
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}