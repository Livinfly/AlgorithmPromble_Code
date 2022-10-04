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
  puts("50");
  for (int T = 0; T < 50; T++)
  {
    int n = random(20) + 1;
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
      printf("%d", random(2));
    puts("");
  }

  return 0;
}