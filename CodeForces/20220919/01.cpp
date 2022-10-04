#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;

int a[N], idx[N], g[N][N], tidx[N];

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
    LL res = 0;
    memset(idx, 0, sizeof idx);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
    {
      int t = i % k;
      g[t][idx[t]++] = a[i];
    }
    for (int i = 0; i < k; i++)
      sort(g[i], g[i] + idx[i], greater<int>());
    for (int i = 0; i <= n - k; i++)
    {
      LL t = 0;
      memset(tidx, 0, sizeof tidx);
      int j = i + k - 1;
      for (int u = i; u <= j; u++)
      {
        int c = u % k;
        t += g[c][tidx[c]++];
      }
      res = max(res, t);
    }
    cout << res << '\n';
  }
  return 0;
}