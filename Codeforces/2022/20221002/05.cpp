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
    int n;
    vector<LL> a(n), b(n), h(n);
    LL p1, p2, sum1 = 0, sum2 = 0;
    for (LL &x : a)
      cin >> x, sum1 += x;
    for (LL &x : b)
      cin >> x, sum2 += x;
    if (sum1 < sum2)
    {
      sort(all(a));
      for (int i = 1; i < n; i++)
        h[i] = a[i] + a[0];
      LL tans1 = a[0];
      a[0] = 0;
      bool flag = false;
      LL tsum = 0;
      for (int i = 0; i < n; i++)
      {
        tsum = 0;
        for (int j = 0; j < n; j++)
          tsum += abs(h[i] - h[j]);
        if (tsum == sum2)
        {
          cout << "YES\n";
          for (auto x : h)
            cout << x << ' ';
          cout << '\n';
          cout << tans1 << ' ' << h[i] << '\n';
          flag = true;
        }
        if (flag)
          break;
      }
      if (tsum > sum2)
      {
        cout << "NO\n";
        continue;
      }
      if ((sum2 - tsum) % n == 0)
      {
        cout << "YES\n";
        for (auto x : h)
          cout << x << ' ';
        cout << '\n';
        cout << tans1 << ' ' << h[n - 1] + (sum2 - tsum) % n << '\n';
        flag = true;
      }
      if (flag)
        continue;
    }
    else
    {
      sort(all(b));
      for (int i = 1; i < n; i++)
        h[i] = b[i] + b[0];
      LL tans1 = b[0];
      b[0] = 0;
      bool flag = false;
      LL tsum = 0;
      for (int i = 0; i < n; i++)
      {
        tsum = 0;
        for (int j = 0; j < n; j++)
          tsum += abs(h[i] - h[j]);
        if (tsum == sum1)
        {
          cout << "YES\n";
          for (auto x : h)
            cout << x << ' ';
          cout << '\n';
          cout << tans1 << ' ' << h[i] << '\n';
          flag = true;
        }
        if (flag)
          break;
      }
      if (tsum > sum1)
      {
        cout << "NO\n";
        continue;
      }
      if ((sum1 - tsum) % n == 0)
      {
        cout << "YES\n";
        for (auto x : h)
          cout << x << ' ';
        cout << '\n';
        cout << tans1 << ' ' << h[n - 1] + (sum1 - tsum) % n << '\n';
        flag = true;
      }
      if (flag)
        continue;
    }
  }
  return 0;
}