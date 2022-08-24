#pragma GCC optimize(2)

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

int n, m;
int a[N];
vector<PII> s[N];
bool flag[N];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  cin >> n >> m;
  while (m--)
  {
    int i, j, x;
    cin >> i >> j >> x;
    s[j].push_back({i, x});
    s[i].push_back({j, x});
  }
  for (int i = 1; i <= n; i++)
  {
    if (s[i].size())
    {
      a[i] = (1 << 30) - 1;
      for (auto x : s[i])
        a[i] &= x.second;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 30; j++)
      if (a[i] >> j & 1)
      {
        bool flag = false;
        for (auto x : s[i])
          if (!(a[x.first] >> j & 1) || x.first == i)
          {
            flag = true;
            break;
          }
        if (!flag)
          a[i] -= (1 << j);
      }
  for (int i = 1; i <= n; i++)
    cout << a[i] << " \n"[i == n];
  return 0;
}
/*
没有想着一位一位处理
*/