#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 1010;

int n, m;
int fa[N];

int get_fa(int x)
{
    if (fa[x] != x)
        return fa[x] = get_fa(fa[x]);
    return x;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    int res = n;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        int ta = get_fa(a), tb = get_fa(b);
        if (ta != tb)
            res--;
        fa[tb] = ta;
    }
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}