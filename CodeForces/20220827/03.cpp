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
    vector<int> a(n + 1), b(n + 1), d1(n + 1), d2(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    for (int i = 1; i <= n; i++)
      cin >> b[i];
    for (int i = n, l = n - 1, r = n; i > 0; i--)
    {
      while (l && b[l] >= a[i])
        l--;
      d1[i] = b[l + 1] - a[i], d2[i] = b[r] - a[i];
      if (l + 1 == i)
        r = l;
    }
    for (int i = 1; i <= n; i++)
      cout << d1[i] << " \n"[i == n];
    for (int i = 1; i <= n; i++)
      cout << d2[i] << " \n"[i == n];
  }
  return 0;
}