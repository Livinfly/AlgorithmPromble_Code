#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 3e4 + 10;

int n, m;
int fa[N], siz[N];

int get_fa(int x)
{
  if (fa[x] != x)
    return fa[x] = get_fa(fa[x]);
  return x;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  while (cin >> n >> m, n || m)
  {
    for (int i = 0; i < n; i++)
      fa[i] = i, siz[i] = 1;
    while (m--)
    {
      int k;
      cin >> k;
      int a, b;
      cin >> a;
      for (int i = 0; i < k - 1; i++)
      {
        cin >> b;
        int ta = get_fa(a), tb = get_fa(b);
        if (ta != tb)
        {
          siz[ta] += siz[tb];
          fa[tb] = ta;
        }
      }
    }
    cout << siz[get_fa(0)] << endl;
  }
  return 0;
}