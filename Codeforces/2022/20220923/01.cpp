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
    vector<LL> a(n);
    for (LL &x : a)
      cin >> x;
    sort(all(a));
    LL res = 1e18;
    for (int i = 0; i < n - 2; i++)
      res = min(res, a[i + 2] - a[i]);
    cout << res << '\n';
  }
  return 0;
}