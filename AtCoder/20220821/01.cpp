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
  int x, y, n;
  cin >> x >> y >> n;
  int t1 = n * x, t2 = n / 3 * y + (n % 3) * x;
  cout << min(t1, t2) << '\n';
  return 0;
}