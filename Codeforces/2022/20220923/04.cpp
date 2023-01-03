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
  int T;
  cin >> T; // scanf("%d", &T);
  while (T--)
  {
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n + 2), s(n + 2);
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    s[k] = a[k];
    LL lmax = a[k], lmin = a[k], rmax = a[k], rmin = a[k];
    bool flag = false;
    for (int i = k - 1; i > 0; i--)
    {
      s[i] += s[i + 1];
      if (s[i] < 0)
        flag = true;
      if (!flag)
        lmax = s[i];
      lmin = min(lmin, s[i]);
    }
    flag = false;
    for (int i = k + 1; i <= n; i++)
    {
      s[i] += s[i - 1];
      if (s[i] < 0)
        flag = true;
      if (!flag)
        rmax = s[i];
      rmin = min(rmin, s[i]);
    }
    if (lmin + rmax >= 0 || rmin + lmax >= 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}