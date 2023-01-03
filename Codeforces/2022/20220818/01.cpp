#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int d1 = __gcd(a, b), d2 = __gcd(c, d);
    if (d1)
      a /= d1, b /= d1;
    if (d2)
      c /= d2, d /= d2;
    int d3 = __gcd(a, c), d4 = __gcd(b, d);
    if (d3)
      a /= d3, c /= d3;
    if (d4)
      b /= d4, d /= d4;
    LL t1, t2;
    t1 = a * d, t2 = c * b;
    if (t1 == t2)
      cout << 0 << '\n';
    else if (!t1 || !t2 || t1 % t2 == 0 || t2 % t1 == 0)
      cout << 1 << '\n';
    else
      cout << 2 << '\n';
  }
  return 0;
}