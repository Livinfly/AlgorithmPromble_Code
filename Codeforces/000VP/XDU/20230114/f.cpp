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
    LL n;
    cin >> n;
    string s;
    cin >> s;
    vector<LL> a(n), b;
    for(int i = 0; i < n; i ++)
        cin >> a[i];
    string t = "";
    LL mx = a[0];
    for(int i = 1; i < n; i ++) {
        if(s[i] == s[i-1]) {
            mx = max(mx, a[i]);
        }
        else {
            b.push_back(mx);
            t += s[i-1];
            mx = a[i];
        }
    }
    b.push_back(mx);
    t += s[n-1];
    s = t;
    n = s.size();
    if(n <= 2) {
        cout << "0\n";
        return;
    }
    // cout << s << '\n';
    // for(auto x : b) 
    //     cout << x << ' ';
    // cout << '\n';
    sort(b.begin()+1, b.end()-1);
    reverse(b.begin()+1, b.end()-1);
    LL len = (n-1)/2;
    // cout << len << '\n';
    LL res = 0;
    for(int i = 1; i <= len; i ++) {
        res += b[i];
    }
    cout << res << '\n';
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
数据范围上下限最后要想一想
*/