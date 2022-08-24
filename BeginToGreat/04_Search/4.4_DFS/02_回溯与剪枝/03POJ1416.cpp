#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

int a, b, res;
bool flag[8], ans_flag[8], rejected;
vector<int> num;

void init()
{
  rejected = false;
  res = -1;
  num.clear();
  while (a > 0)
  {
    num.push_back(a % 10), a /= 10;
  }
  reverse(num.begin(), num.end());
}
void dfs(int u)
{
  if (u == num.size())
  {
    int t = 0, tres = 0;
    for (int i = 0; i < num.size(); i++)
    {
      t = t * 10 + num[i];
      if (flag[i])
      {
        tres += t;
        t = 0;
      }
    }
    if (tres <= b)
    {
      if (tres == res)
        rejected = true;
      else if (res == -1 || tres > res)
      {
        memcpy(ans_flag, flag, sizeof flag);
        res = tres;
        rejected = false;
      }
    }
    return;
  }
  if (u != num.size() - 1)
    dfs(u + 1);
  flag[u] = true;
  dfs(u + 1);
  flag[u] = false;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  while (cin >> b >> a, a && b) // a -> b
  {
    init();
    dfs(0);
    if (res == -1)
      cout << "error" << endl;
    else if (rejected)
      cout << "rejected" << endl;
    else
    {
      cout << res << ' ';
      int t = 0;
      for (int i = 0; i < num.size(); i++)
      {
        t = t * 10 + num[i];
        if (ans_flag[i] || i == num.size() - 1)
        {
          cout << t << ' ';
          t = 0;
        }
      }
      cout << endl;
    }
  }
  return 0;
}