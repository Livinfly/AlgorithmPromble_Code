#pragma GCC optimize(2)

#include <bits/stdc++.h>

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
    int n, k;
    cin >> n >> k;
    if (k & 1)
    {
      cout << "YES\n";
      for (int i = 1; i <= n; i += 2)
        cout << i << ' ' << i + 1 << '\n';
    }
    else
    {
      if (k % 4 == 2)
      {
        cout << "YES\n";
        for (int i = 1, cur = 0; i <= n; i += 2, cur ^= 1)
        {
          int t1, t2;
          if (cur)
            t1 = i, t2 = i + 1;
          else
            t1 = i + 1, t2 = i;
          cout << t1 << ' ' << t2 << '\n';
        }
      }
      else
        cout << "NO\n";
    }
  }
  return 0;
}