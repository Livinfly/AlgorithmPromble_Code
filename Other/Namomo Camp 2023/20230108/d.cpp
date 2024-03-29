#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int &x : a) cin >> x, sum ^= x;
    for(int &x : a) x ^= sum, cout << x << ' ';
    cout << '\n';
    return 0;
}