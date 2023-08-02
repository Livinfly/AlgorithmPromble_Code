#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = cin.get(); // getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = cin.get(); // getchar();
    }
    while('0' <= ch && ch <= '9')
        x = (x<<3)+(x<<1)+ch-'0', ch = cin.get();  // getchar();
    return x * f;
}
void write(__int128 x) {
    static int _stk_[40];
    int top = 0;
    do {
        _stk_[++ top] = x % 10, x /= 10;
    } while(x);
    while(top)
        putchar(_stk_[top --] + '0');
}
void solve() {
    __int128 n = read(), c = read();
    // cin >> n >> c;
    vector<__int128> s(n);
    __int128 sum = 0;
    for(auto &x: s) 
        x = read();
    auto f = [&](__int128 mid) {
        __int128 ret = 0;
        for(auto x: s) {
            ret += (x+mid*2) * (x+mid*2);
        }
        return ret;
    };
    __int128 l = 1, r = sqrt((LL)c/(LL)n)+10000;
    while(l < r) {
        __int128 mid = l+r >> 1;
        if(f(mid) >= c) r = mid;
        else l = mid+1;
    }
    // cout << r << '\n';
    write(r);
    cout << '\n';
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}