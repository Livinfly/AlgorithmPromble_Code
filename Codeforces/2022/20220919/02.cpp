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
    int n, x, y;
    cin >> n >> x >> y;
    if (x < y)
      swap(x, y);
    if (y || !x && !y || x > n - 1)
    {
      cout << -1 << '\n';
    }
    else
    {
      if ((n - 1) % x != 0)
        cout << -1 << '\n';
      else
      {
        if (n == 2)
          cout << 1;
        else
        {
          int t = 1;
          for (int i = 1; i <= n - 1; i++)
          {
            if ((i - 1) && (i - 1) % x == 0)
              t = i + 1;
            cout << t << ' ';
          }
        }

        cout << '\n';
      }
    }
  }
  return 0;
}