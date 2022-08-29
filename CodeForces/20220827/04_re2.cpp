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
    vector<int> a(n), b(n);
    for (int &x : a)
      cin >> x;
    for (int &x : b)
      cin >> x;
    auto check = [&](int x)
    {
      // 这边选用vector判等
      vector<int> ta(n), tb(n);
      for (int i = 0; i < n; i++)
      {
        ta[i] = a[i] & x;
        tb[i] = ~b[i] & x;
      }
      sort(all(ta));
      sort(all(tb));
      return ta == tb;
    };
    int ans = 0;
    for (int i = 29; i >= 0; i--)
      if (check(ans | (1 << i)))
        ans |= 1 << i;
    cout << ans << '\n';
  }
  return 0;
}
/*
  jls YYDS
*/