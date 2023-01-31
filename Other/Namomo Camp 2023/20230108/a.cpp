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
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    for(int &x : a) scanf("%d", &x);
    sort(all(a));
    int res = 0;
    for(int i = 0; i < k; i ++)
        res += a[i];
    printf("%d\n", res);
    return 0;
}