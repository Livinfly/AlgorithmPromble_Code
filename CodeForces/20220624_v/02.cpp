#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  cin >> T; // scanf("%d", &T);
  while (T--)
  {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), deg(n);
    set<int> e[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < m; i++)
    {
      int a, b;
      cin >> a >> b;
      deg[--a]++, deg[--b]++;
      e[a].insert(b);
    }
    if (m & 1)
    {
      int res = 2147483647;
      for (int i = 0; i < n; i++)
      {
        if (deg[i] & 1)
          res = min(res, a[i]);
        else
        {
          for (auto x : e[i])
          {
            if (deg[x])
              res = min(res, a[i] + a[x]);
          }
        }
      }
      cout << res << '\n';
    }
    else
      cout << 0 << '\n';
  }
  return 0;
}