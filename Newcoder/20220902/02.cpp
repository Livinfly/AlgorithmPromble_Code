#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int P = 19980829;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  cin >> T; // scanf("%d", &T);
  LL res = 0, t1, t2;
  bool flag = false;
  while (T--)
  {
    if (res >= 1e9)
    {
      res %= P;
      flag = true;
    }
    LL a, b;
    cin >> a >> b;
    t1 = res + a, t2 = res * b;
    if (flag)
    {
      if (b == 1)
        res = t1 % P;
      else
        res = t2 % P;
    }
    else
      res = max(t1, t2);
  }
  cout << res % P << '\n';
  return 0;
}