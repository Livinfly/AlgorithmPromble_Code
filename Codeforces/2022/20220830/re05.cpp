#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;

int n, q;
LL f[N][N];

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
    memset(f, 0, sizeof f);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      f[x + 1][y + 1] += x * y;
    }
    for (int i = 0; i <= 1001; i++)
      for (int j = 0; j <= 1001; j++)
        f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
    while (q--)
    {
      int h1, w1, h2, w2;
      cin >> h1 >> w1 >> h2 >> w2;
      cout << f[h2][w2] - f[h2][w1 + 1] - f[h1 + 1][w2] + f[h1 + 1][w1 + 1] << '\n';
    }
  }
  return 0;
}