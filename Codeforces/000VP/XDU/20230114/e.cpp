#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1.5e6+10;
int n, m, T, ans[N];
string s;

void solve() {
    cin >> n >> T;
    T = min(T, n);
    cin >> s;
    string tmp = "SRP";
    for(int i = 0; i < s.size(); i ++) {
        while(s[i] != tmp[m%3]) m ++;
        ans[m] ++;
    }
    for(int i = 0; i <= m; i ++) {
        if(ans[i+1] == 0) {
            ans[i+3] += min(T, ans[i]);
            ans[i] = max(0, ans[i]-T);
        }
    }
    m += 3;
    for(int i = 0; i <= m; i ++)
        while(ans[i] --) {
            cout << tmp[i%3];
        }
    cout << '\n';
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