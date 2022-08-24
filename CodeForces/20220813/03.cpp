#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e5 + 100;

int n, res;
int a[N];
bool vis[N];

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
    res = 0;
    memset(vis, 0, sizeof vis);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    bool flag = false;
    int l1 = 0, l2 = 0;
    vis[0] = true;
    while (1)
    {
      flag = false;
      for (int i = n - 1; i >= l1 + 1; i--)
        if (a[i] < a[i - 1])
        {
          l2 = i, flag = true;
          break;
        }
      if (!flag)
        break;
      for (int i = l1; i < l2; i++)
        if (!vis[a[i]])
        {
          vis[a[i]] = true;
          a[i] = 0, res++;
        }

      for (int i = l2; i < n; i++)
        if (vis[a[i]])
          a[i] = 0;
      l1 = l2;
    }
    cout << res << '\n';
  }
  return 0;
}