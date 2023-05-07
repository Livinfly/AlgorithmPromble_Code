#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

LL pw10[18];

LL Get(string x, string s) {
    int n = x.size(), m = s.size();
    LL ret = 0;
    LL num = stoll(x), snum = stoll(s);
    for(int i = 0; i+m <= n; i ++) {
        LL t = num - snum*pw10[n-m-i];
            if(t >= 0 && (i || s[0] != '0')) {
            LL a = t / pw10[n-i] - (s[0]=='0'), b = min(pw10[n-m-i]-1, t % pw10[n-i])+1;
            ret += a*pw10[n-m-i]+b;
        }
    }
    return ret;
}
void solve() {
    string s;
    cin >> s;
    string l, r;
    cin >> l >> r;
    l = to_string(stoll(l)-1);
    cout << Get(r, s) - Get(l, s) << '\n';
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