#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const LL P = 998244353;

LL c[65][65], f[65];

void prev_calc()
{
  for (int i = 0; i <= 60; i++)
    for (int j = 0; j <= i; j++)
      if (!j)
        c[i][j] = 1;
      else
        c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % P;
  f[0] = f[1] = 1;
  for (LL i = 1; i < 60; i++)
    f[i + 1] = f[i] * (4 * i + 2) % P / (i + 2);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  prev_calc();
  int T;
  cin >> T; // scanf("%d", &T);
  while (T--)
  {
    int n;
    cin >> n;
    LL res1 = 0;
    for (int i = 1; i <= n / 2 && (n - i * 2 + 1 >= n / 2 - i); i += 2)
      res1 = (res1 + c[n - i * 2 + 1][n / 2 - i]) % P;
    cout << res1 << ' ' << ((c[n][n / 2] - res1 - 1) % P + P) % P << ' ' << 1 << '\n';
  }
  return 0;
}