#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 5e4 + 10;

int n, m;
int fa[N];

int get_fa(int x)
{
    if (fa[x] != x)
        return fa[x] = get_fa(fa[x]);
    return x;
}

int main()
{
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int CC = 0;
    while (scanf("%d%d", &n, &m) == 2, n || m)
    {
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        int res = n;
        while (m--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            int ta = get_fa(a), tb = get_fa(b);
            if (ta != tb)
            {
                fa[tb] = ta;
                res--;
            }
        }
        printf("Case %d: %d\n", ++CC, res);
    }
    return 0;
}