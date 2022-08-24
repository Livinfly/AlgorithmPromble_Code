#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 25;

int n, res, t1, t2;
int g[N][N], q1[N], q2[N];

void dfs(int u)
{
  if (u == n)
  {
    int t = 0;
    for (int i = 0; i < t1; i++)
      for (int j = 0; j < t2; j++)
        t += g[q1[i]][q2[j]];
    res = max(res, t);
    return;
  }
  q1[t1++] = u;
  dfs(u + 1);
  t1--;

  q2[t2++] = u;
  dfs(u + 1);
  t2--;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  while (cin >> n)
  {
    res = -1, t1 = t2 = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> g[i][j];
    dfs(0);
    cout << res << endl;
  }
  return 0;
}