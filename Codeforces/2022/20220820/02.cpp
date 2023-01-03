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
    LL n, k, b, s;
    cin >> n >> k >> b >> s;
    LL cnt = 0;
    for (cnt = 0; cnt < n; cnt++)
    {
      LL t = (LL)(s - cnt * (k - 1)) / k;
      if (t > b)
        continue;
      else
        break;
    }
    if (cnt == n || (LL)s / k < b)
      cout << -1 << '\n';
    else
    {
      for (int i = 0; i < cnt; i++)
        cout << k - 1 << ' ';
      for (int i = 0; i < n - 1 - cnt; i++)
        cout << 0 << ' ';
      cout << s - cnt * (k - 1) << '\n';
    }
  }
  return 0;
}