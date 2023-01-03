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
    int n, m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;
    if (sx + d < n && sy - d > 1 || sx - d > 1 && sy + d < m)
      cout << n + m - 2 << '\n';
    else
      cout << -1 << '\n';
  }
  return 0;
}