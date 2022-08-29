#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

vector<int> ga[N], gb[N];

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
    vector<int> a(n), b(n);
    ga[0].clear(), gb[0].clear();
    for (int &x : a)
      cin >> x, ga[0].emplace_back(x);
    for (int &x : b)
      cin >> x, gb[0].emplace_back(x);
    int res = 0, g_cnt = 1;
    for (int i = 29; i >= 0; i--) // bit
    {
      bool is_legal = true;
      for (int j = 0; j < g_cnt; j++)
      {
        int a0 = 0, b1 = 0;
        for (int &x : ga[j])
          if (!(x >> i & 1))
            a0++;
        for (int &x : gb[j])
          if (x >> i & 1)
            b1++;
        if (a0 != b1)
        {
          is_legal = false;
          break;
        }
      }
      if (!is_legal)
        continue;
      // update answer
      res += 1 << i;
      // divide into new group
      int ng_cnt = g_cnt;
      for (int j = 0; j < g_cnt; j++)
      {
        int a0 = 0, a1 = 0;
        for (int &x : ga[j])
          if (x >> i & 1)
            a1++;
          else
            a0++;
        if (!a0 || !a1) // no need for divide
          continue;
        vector<int> t_ga = ga[j], t_gb = gb[j];
        ga[j].clear(), gb[j].clear(), ga[ng_cnt].clear(), gb[ng_cnt].clear();
        for (int &x : t_ga)
          if (x >> i & 1)
            ga[j].emplace_back(x);
          else
            ga[ng_cnt].emplace_back(x);
        for (int &x : t_gb)
          if (x >> i & 1)
            gb[ng_cnt].emplace_back(x);
          else
            gb[j].emplace_back(x);
        ng_cnt++;
      }
      g_cnt = ng_cnt;
    }
    cout << res << '\n';
  }
  return 0;
}
/*
  观看wangxueyi的题解
  思路很像
  死于代码实现（（
*/