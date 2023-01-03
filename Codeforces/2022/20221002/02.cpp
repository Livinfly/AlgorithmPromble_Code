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
    for (auto &x : a)
      cin >> x;
    int t = a[0] * 2 - 1, res = 0;
    for (int i = 1; i < n; i++)
      if (a[i] > t)
      {
        res += a[i] / t;
        if (a[i] % t == 0)
          res--;
      }

    cout << res << '\n';
  }
  return 0;
}