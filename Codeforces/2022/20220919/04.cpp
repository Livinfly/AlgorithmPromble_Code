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
    LL n, x, y;
    cin >> n >> x >> y;
    string s1, s2;
    cin >> s1 >> s2;

    LL cnt = 0, last = -2;
    bool flag = false;
    for (int i = 0; i < s1.size(); i++)
    {

      if (s1[i] != s2[i])
      {
        if (last + 1 == i)
          flag = true;
        cnt++, last = i;
      }
    }

    if (cnt & 1)
    {
      cout << -1 << '\n';
      continue;
    }
    LL res = 0;
    if (flag && cnt == 2)
      res = min(x, 2 * y);
    else
      res = y * (cnt / 2);
    cout << res << '\n';
  }
  return 0;
}