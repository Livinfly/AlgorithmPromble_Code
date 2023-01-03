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
    string s;
    cin >> n >> s;
    s = " " + s;
    LL res = 0;
    vector<int> failz(n + 1), ref(n + 1);
    for (int i = 1; i <= n; i++)
    {
      if (!(s[i] & 1))
      {
        if (!ref[i])
        {
          for (int j = i; j <= n; j += i)
            if (!(s[j] & 1))
            {
              if (!ref[j])
              {
                res += i, ref[j] = i;
                // cout << i << ' ' << j << '\n';
              }
            }
            else
            {
              failz[i] = j;
              break;
            }
        }
        else
        {
          for (int j = failz[ref[i]] - failz[ref[i]] % i; j <= n; j += i)
          {
            if (!j)
              j += i;
            if (!(s[j] & 1))
            {
              if (!ref[j])
              {
                res += i, ref[j] = i;
                // cout << i << ' ' << j << '\n';
              }
            }
            else
            {
              failz[i] = j;
              break;
            }
          }
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}