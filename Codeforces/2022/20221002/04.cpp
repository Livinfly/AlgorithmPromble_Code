#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e3 + 10;

int n, k;
int a[N][25], cnt[N];
set<string> S;
map<string, int> mp;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    string t = "";
    for (int j = 0; j < k; j++)
    {
      cin >> a[i][j];
      t += a[i][j] + '0';
    }
    mp[t] = i;
  }
  LL res = 0;
  for (int i = 0; i < n - 2; i++)
    for (int j = i + 1; j < n - 1; j++)
    {
      string t = "";
      for (int u = 0; u < k; u++)
      {
        if (a[i][u] == a[j][u])
          t += a[i][u] + '0';
        else
          t += (3 - a[i][u] - a[j][u]) + '0';
      }
      int z = mp[t];
      if (z > j)
        cnt[i]++, cnt[j]++, cnt[z]++;
    }
  for (int i = 0; i < n; i++)
    if (cnt[i] >= 2)
      res += cnt[i] * (cnt[i] - 1) / 2;
  cout << res << '\n';
  return 0;
}
/*
分析出特殊性质
1. 2个可用确定第三个
2. meta-set 由不同的 主导，一定不同，因为主导者为公共的，就是不一样
*/