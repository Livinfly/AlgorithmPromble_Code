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
    int n, m;
    cin >> n >> m;
    if (n > m || n % 2 == 0 && m % 2 == 1)
    {
      cout << "No\n";
      continue;
    }
    else
      cout << "Yes\n";
    if (n & 1)
    {
      int t = m / n;
      for (int i = 0; i < n - 1; i++)
        cout << t << ' ';
      cout << t + m % n << '\n';
    }
    else
    {
      for (int i = 0; i < n - 2; i++)
        cout << 1 << ' ';
      cout << (m - (n - 2)) / 2 << ' ' << (m - (n - 2)) / 2 << '\n';
    }
  }
  return 0;
}