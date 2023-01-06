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
    string s;
    cin >> s;
    vector<string> res;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] != '0') {
            string str = s.substr(i);
            for(int i = 1; i < str.size(); i ++)
                str[i] = '0';
            res.push_back(str);
        }
    }
    cout << res.size() << '\n';
    for(auto x : res) 
        cout << x << ' ';
    cout << '\n';
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