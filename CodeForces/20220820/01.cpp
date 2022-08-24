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
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1)
    {
      cout << 0 << '\n';
      continue;
    }
    if (n < m)
      swap(n, m);
    cout << (m - 1) * 2 + n << '\n';
  }
  return 0;
}