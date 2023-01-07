#pragma GCC optimize(2)

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  LL n, p, q, r;
  cin >> n >> p >> q >> r;
  vector<LL> a(n + 4), s(n + 4);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    s[i] = s[i - 1] + a[i];
  for (int x = 1, y = 2, z = 3, w = 4;; x++)
  {
    while (w <= n + 1 && s[w - 1] - s[x - 1] < p + q + r)
      w++;
    if (w == n + 2)
    {
      cout << "No\n";
      return 0;
    }
    if (s[w - 1] - s[x - 1] != p + q + r)
      continue;
    while (y <= n - 1 && s[y - 1] - s[x - 1] < p)
      y++;
    if (y == n)
    {
      cout << "No\n";
      return 0;
    }
    if (s[y - 1] - s[x - 1] != p)
      continue;
    while (z <= n && s[z - 1] - s[y - 1] < q)
      z++;
    if (z == n + 1)
    {
      cout << "No\n";
      return 0;
    }
    if (s[z - 1] - s[y - 1] != q)
      continue;
    cout << "Yes\n";
    return 0;
  }
  return 0;
}