#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

LL pw[15];

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    LL n;
    cin >> n;
    pw[0] = 1;
    for(int i = 1; i < 12; i ++) 
        pw[i] = pw[i-1]*26;
    string s = "";
    for(int i = 0; i < 12; i ++)
        if(n >= pw[i]) 
            s = "a"+s, n -= pw[i];
    // cout << n << '\n';
    for(int i = s.size()-1; i >= 0; i --) {
        s[s.size()-1-i] += n/pw[i];
        n %= pw[i];
    }
    cout << s << '\n';
    return 0;
}