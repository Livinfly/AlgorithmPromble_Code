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
    // freopen("o.txt", "w", stdout);
    string tmp = "SRP";
    int n = random(50000)+1, m = random(n)+1;
    cout << n << ' ' << m << '\n';
    for(int i = 0; i < n; i ++)
        cout << tmp[random(3)];
    cout << '\n';
    return 0;
}