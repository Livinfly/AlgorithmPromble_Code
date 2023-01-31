#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

void solve() {
    ULL n;
    cin >> n;
    ULL sum = 0, len = 1;
    while(n --) {
        ULL a;
        cin >> a;
        if(a >= 128) {
            a -= 128;
            sum += a*len;
            len *= 128;
        }
        else {
            sum += a*len;
            if(sum & 1) {
                cout << -(LL)(sum/2+1) << '\n'; // -(sum+1)/2
            }
            else {
                cout << sum/2 << '\n';
            }
            sum = 0, len = 1;
        }
    }
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
题意在绕，读懂后按题意模拟即可

题目只保证被加密的数在LL范围，并不保证加密出来的数在LL范围
ps. 一开始我用了int128，然后后面发现加密出来的数最多超LL一倍，且是正数
所以也可以用ULL
*/