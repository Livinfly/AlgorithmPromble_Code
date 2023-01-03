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
    map<string, int> mp;
    vector<string> s[3];
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < n; j++)
      {
        string x;
        cin >> x;
        s[i].emplace_back(x);
        mp[x]++;
      }
    for (int i = 0; i < 3; i++)
    {
      int res = 0;
      for (auto &x : s[i])
        if (mp[x] == 1)
          res += 3;
        else if (mp[x] == 2)
          res += 1;
      cout << res << " \n"[i == 2];
    }
  }
  return 0;
}