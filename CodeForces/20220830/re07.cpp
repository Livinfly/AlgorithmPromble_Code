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
    cin >> n;
    if (n % 4 == 0)
    {
      for (int i = 1; i <= n - 1; i++)
        cout << i << ' ';
      cout << 0 << '\n';
    }
    else if (n % 4 == 1)
    {
      cout << 0 << ' ';
      for (int i = 2; i <= n; i++)
        cout << i << " \n"[i == n];
    }
    else if (n % 4 == 2)
    {
      int t1 = 0, t2 = 0;
      for (int i = 1; i <= n - 2; i++)
      {
        cout << i << ' ';
        if (i & 1)
          t1 ^= i;
        else
          t2 ^= i;
      }
      int t = 0;
      while (n)
        n /= 2, t++;
      cout << (1 << t) + t1 << ' ' << (1 << t) + t2 << '\n';
    }
    else
    {
      for (int i = 1; i <= n; i++)
        cout << i << " \n"[i == n];
    }
  }
  return 0;
}