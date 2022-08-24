#include <bits/stdc++.h>
#include <ctime>

using namespace std;

typedef long long LL;

int random(int x)
{ // 获取 0~x-1 中间的一个随机数
  if (!x)
    return 0;
  return (LL)rand() * rand() % x;
}

int main()
{
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  srand(time(0));
  puts("3");
  for (int T = 0; T < 3; T++)
  {
    int n = random((int)10 - 1) + 2, q = random((int)10) + 1;
    printf("%d %d\n", n, q);
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
    {
      int x = random(n) + 1;
      if (!vis[x - 1])
      {
        vis[x - 1] = true;
        printf("%d ", x);
      }
      else
      {
        while (vis[x - 1])
        {
          x++;
          if (x == n + 1)
            x = 1;
        }
        vis[x - 1] = true;
        printf("%d ", x);
      }
    }
    puts("");
    while (q--)
    {
      printf("%d %d\n", random(n) + 1, random((int)20) + 1);
    }
  }
  return 0;
}