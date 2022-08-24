#pragma GCC optimize(2)

#include <bits/stdc++.h>

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
    int res = (n % 2 + m % 2) % 2;
    if (res & 1)
      cout << "Burenka\n";
    else
      cout << "Tonya\n";
  }
  return 0;
}