#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 3e5 + 10;

int n, res;
int a[N], f[N];

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
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int res = 1;
    for (int i = 0; i < n; i++)
    {
      f[i] = 1;
      for (int j = i >> 8 << 8; j < i; j++)
        if ((a[j] ^ i) < (a[i] ^ j))
          f[i] = max(f[i], f[j] + 1);
      res = max(res, f[i]);
    }
    cout << res << '\n';
  }
  return 0;
}