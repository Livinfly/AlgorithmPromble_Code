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
  int n;
  while (cin >> n, n)
  {
    vector<array<int, 2>> a;
    for (int i = 0; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      a.push_back({x, y});
    }
    auto cmp = [&](array<int, 2> a, array<int, 2> b)
    {
      return a[1] < b[1];
    };
    sort(all(a), cmp);
    int R = -1e9, res = 0;
    for (auto x : a)
    {
      if (x[0] >= R)
      {
        R = x[1];
        res++;
      }
    }
    cout << res << '\n';
  }
  return 0;
}