#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const double eps = 1e-8;

double ans = -1e9;

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
    int n;
    cin >> n;
    vector<array<double, 2>> a(n);
    for (auto &x : a)
      cin >> x[0];
    for (auto &x : a)
      cin >> x[1];
    double l = -1e9, r = 1e9; // time
    auto check = [&](double mid)
    {
      double l = 0, r = 2e9;
      for (auto x : a)
      {
        if (mid < x[1])
          return false;
        l = max(l, x[1] + x[0] - mid);
        r = min(r, x[0] + mid - x[1]);
      }
      ans = l;
      return r > l + eps;
    };
    for (int i = 0; i < 100; i++)
    {
      double mid = (l + r) / 2;
      if (check(mid))
        r = mid;
      else
        l = mid;
    }
    cout << fixed << ans << '\n';
  }
  return 0;
}