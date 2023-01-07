#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

LL Sqrt(LL n) {
    LL v = sqrt(n);
    while ((v + 1) * (v + 1) <= n) v++;
    while (v * v > n) v--;
    return v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    for(LL n = 310000000000LL; n <= (LL)9e18; n ++) {
        LL t = sqrt(n)+0.1, T = Sqrt(n);
        if(n % 100000000 == 0)
            cout << n << endl;
        if((t*t == n) ^ (T*T == n)) {
            cout << n << '\n';
            cout << "?????\n";
            break;
        }
    }
    
    return 0;
}