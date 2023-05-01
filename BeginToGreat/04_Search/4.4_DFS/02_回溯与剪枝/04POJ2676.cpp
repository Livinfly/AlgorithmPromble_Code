#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 12;

int done_cnt;
int line[N], row[N], col[3][3]; // 二进制记录使用状态 - 1为可用，0为占用
char g[N][N];

void init()
{
  done_cnt = 0;
  for (int i = 0; i < 9; i++)
    line[i] = row[i] = 511;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      col[i][j] = 511;
}

int lowbit(int x)
{
  return x & -x;
}
int count_one(int x)
{
  int res = 0;
  for (; x; x -= lowbit(x))
    res++;
  return res;
}
bool get_nstatus(int &xx, int &yy)
{
  int maxn = 1e9;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (g[i][j] == '0' && (line[i] & row[j] & col[i / 3][j / 3]))
      {
        int ones = count_one(line[i] & row[j] & col[i / 3][j / 3]);
        if (ones < maxn)
        {
          maxn = ones;
          xx = i, yy = j;
        }
      }
  return maxn != 1e9;
}
bool dfs(int tdone_cnt)
{
  if (tdone_cnt == 81)
    return true;
  // cout << tdone_cnt << endl;
  int x, y;
  if (!get_nstatus(x, y))
    return false; // 优化搜索顺序 - 先找到可能填空最小的
  // cout << x << ' ' << y << endl;
  int t = line[x] & row[y] & col[x / 3][y / 3];
  for (int i = 0; i < 9; i++)
    if (t >> i & 1)
    {
      g[x][y] = '0' + i + 1;
      line[x] -= 1 << i;
      row[y] -= 1 << i;
      col[x / 3][y / 3] -= 1 << i;
      if (dfs(tdone_cnt + 1))
        return true;
      g[x][y] = '0';
      line[x] += 1 << i;
      row[y] += 1 << i;
      col[x / 3][y / 3] += 1 << i;
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
    init();
    for (int i = 0; i < 9; i++)
      cin >> g[i];
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
        if (g[i][j] != '0')
        {
          int t = g[i][j] - '0' - 1; // 0-8
          line[i] -= 1 << t;
          row[j] -= 1 << t;
          col[i / 3][j / 3] -= 1 << t;
          done_cnt++;
        }
    dfs(done_cnt);
    for (int i = 0; i < 9; i++)
      cout << g[i] << endl;
  }
  return 0;
}
