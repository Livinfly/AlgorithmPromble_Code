#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = (int)1e9;

int a[N], b[N];

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
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      b[i] = i;
    }
    sort(b + 1, b + n + 1, [](int p1, int p2)
         { return a[p1] < a[p2]; });
    for (int i = 1; i <= k - 1; i++)
      a[b[i]] = INF;
    multiset<int> s1, s2;
    for (int i = 1; i <= n; i++)
    {
      s1.insert(a[i]);
      if (i < n)
        s2.insert(min(a[i], a[i + 1]));
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
      s1.erase(s1.find(a[i]));
      if (i >= 2)
        s2.erase(s2.find(min(a[i - 1], a[i]))), s2.insert(min(a[i - 1], INF));
      if (i <= n - 1)
        s2.erase(s2.find(min(a[i], a[i + 1]))), s2.insert(min(a[i + 1], INF));
      ans = max(ans, min(*s1.begin() * 2, *s2.rbegin()));
      s1.insert(a[i]);
      if (i >= 2)
        s2.insert(min(a[i - 1], a[i])), s2.erase(s2.find(min(a[i - 1], INF)));
      if (i <= n - 1)
        s2.insert(min(a[i], a[i + 1])), s2.erase(s2.find(min(a[i + 1], INF)));
    }
    cout << ans << '\n';
  }
  return 0;
}
// 还有二分res的