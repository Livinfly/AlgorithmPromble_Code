#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

int n, depth;
int len[12], idx[12];
char DNA[5] = "ACGT";
char s[12][50];

bool dfs(int u)
{
  if (u == depth)
  {
    for (int i = 1; i <= n; i++)
      if (len[i] != idx[i])
        return false;
    // cout << s[0] << endl;
    return true;
  }
  for (int i = 1; i <= n; i++)
    if (len[i] - idx[i] > depth - u)
      return false;
  // cout << s[0] << endl;
  // for (int i = 1; i <= n; i++)
  //   cout << idx[i] << ' ' << len[i] << endl;
  // cout << endl;
  for (int i = 0; i < 4; i++)
  {
    int rec[12], rec_idx = 0; // 为局部变量，变成全局，导致数据混乱
    s[0][len[0]++] = DNA[i];
    for (int j = 1; j <= n; j++)
    {
      if (idx[j] < len[j] && s[j][idx[j]] == s[0][len[0] - 1])
      {
        rec[rec_idx++] = j;
        idx[j]++;
      }
    }
    if (dfs(u + 1))
      return true;
    for (int j = 0; j < rec_idx; j++)
      idx[rec[j]]--;
    len[0]--;
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  cin >> T;
  while (T--)
  {
    depth = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      cin >> s[i];
      len[i] = strlen(s[i]);
      depth = max(depth, len[i]);
    }
    // 回来一遍缺少初始化，且在里面不需要，因为dfs会还原
    memset(idx, 0, sizeof idx);
    s[0][0] = '\0';
    len[0] = 0;
    while (!dfs(0))
      depth++;

    cout << depth << endl;
  }
  return 0;
}
