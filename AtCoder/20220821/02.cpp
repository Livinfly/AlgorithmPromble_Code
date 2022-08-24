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
  LL n, m, t;
  cin >> n >> m >> t;
  vector<LL> cost(n + 2), bonus(n + 2, 0);
  for (int i = 2; i <= n; i++)
    cin >> cost[i]; // i-1->i
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    bonus[x] = y;
  }
  for (int i = 2; i <= n; i++)
  {
    t -= cost[i];
    if (t <= 0)
    {
      cout << "No\n";
      return 0;
    }
    t += bonus[i];
  }
  cout << "Yes\n";
  return 0;
}