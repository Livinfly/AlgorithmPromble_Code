#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

mt19937_64 mt_rand(time(0));

LL random(LL x) {
    return mt_rand()%x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    int n = 3, m = 4;
    // cout << 100000 << '\n';
    int tot = 1*2*3*4*5*6*7*8*9*10*11*12;
    cout << tot << '\n';
    vector<int> a(n*m);
    int t = 0;
    iota(all(a), 1);
    next_permutation(all(a));
    do {
        cout << n << ' ' << m << '\n';
        for(auto x: a) cout << x << ' ';
        cout << endl;
    } while(next_permutation(all(a)));
    return 0;
}