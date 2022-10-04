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
    vector<int> a(n);
    vector<PII> ans;
    for (int &x : a)
      cin >> x;
    bool flag = false;
    for (int i = 1; i < n; i++)
      if (a[i] < a[i - 1])
        flag = true;
    if (!flag)
    {
      cout << 0 << '\n';
      continue;
    }
    int t;
    if (a[0] + a[n - 1] & 1)
      t = a[0] % 2;
    else
      t = a[n - 1] % 2;
    ans.emplace_back((PII){1, n});
    for (int i = 1; i < n - 1; i++)
      if (a[i] % 2 != t)
        ans.emplace_back((PII){1, i + 1});
      else
        ans.emplace_back((PII){i + 1, n});
    cout << ans.size() << '\n';
    for (auto x : ans)
      cout << x.first << ' ' << x.second << '\n';
  }
  return 0;
}