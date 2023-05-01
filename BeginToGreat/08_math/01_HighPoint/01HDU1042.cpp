#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 10010;

struct HP
{
  int num[N];
  int len;
} tmp;

inline HP mulHL(const HP &a, const int &b)
{
  memset(&tmp, 0, sizeof(HP));
  int t = 0;
  for (int i = 0; i < a.len || t; i++)
  {
    if (i < a.len)
      t += a.num[i] * b;
    tmp.num[tmp.len++] = t % 10000;
    t /= 10000;
  }
  while (tmp.len > 1 && tmp.num[tmp.len - 1] == 0)
    tmp.len--;
  return tmp;
}
inline void Hprint(const HP &a)
{
  printf("%d", a.num[a.len - 1]);
  for (int i = a.len - 2; i >= 0; i--)
    printf("%04d", a.num[i]);
  cout << '\n';
}

int main()
{
  int n;
  HP x;
  while (scanf("%d", &n) == 1)
  {
    if (!n)
    {
      puts("1");
      continue;
    }
    memset(&x, 0, sizeof(HP));
    x.num[0] = 1, x.len = 1;
    for (int i = 2; i <= n; i++)
      x = mulHL(x, i);
    Hprint(x);
  }

  return 0;
}