#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

int a[N], cnt[N];

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
    int n, q;
    cin >> n >> q;
    memset(a, 0, sizeof a);
    memset(cnt, 0, sizeof cnt);
    int maxn = 0, pos = 0;
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      if (maxn > a[i])
      {
        cnt[i] = 0;
        cnt[pos]++;
      }
      else
      {
        maxn = a[i], pos = i;
        if (pos > 1)
          cnt[pos] = 1;
      }
    }
    while (q--)
    {
      int id, k;
      cin >> id >> k;
      if (a[id] == maxn)
      {
        int t = id;
        if (t == 1)
          t = 2;
        cout << max(0, k - t + 2) << '\n';
      }
      else
      {
        int t = id;
        if (t == 1)
          t = 2;
        cout << min(max(0, k - t + 2), cnt[id]) << '\n';
      }
    }
  }
  return 0;
}