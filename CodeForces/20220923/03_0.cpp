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
    vector<LL> num;
    for (int i = 1; i <= n; i++)
      if (!(s[i] & 1))
      {
        num.emplace_back(i);
        for (LL x : num)
        {
          if (!(s[x] & 1) && i % x == 0)
          {
            // cout << x << ' ';
            res += x;
            break;
          }
        }
      }
      else
      {
        for (int j = 0; j < num.size(); j++)
        {
          if (!(s[num[j]] & 1) && i % num[j] == 0)
          {
            s[num[j]] ^= 1;
            // num.erase(num.begin() + j);
            // j--;
          }
        }
      }
    cout << res << '\n';
  }
  return 0;
}