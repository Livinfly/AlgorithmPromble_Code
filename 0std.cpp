#include <iostream>
#include <cstring>
using namespace std;
#define MAX 10000
int a[MAX * 4];
void fun(int n)
{
  int i, j, temp;
  a[1] = 1;
  a[0] = 1;
  for (i = 2; i <= n; i++)
  {
    temp = 0;
    for (j = 1; j <= a[0]; j++)
    {
      a[j] *= i;
      a[j] += temp;
      temp = a[j] / 10;
      a[j] %= 10;
    }
    a[0] = j - 1;
    while (temp)
    {
      a[j] = temp % 10;
      temp /= 10;
      a[0] = j;
      j++;
    }
  }
}
int main()
{
  int n, i;
  while (cin >> n)
  {
    memset(a, 0, sizeof(a));
    fun(n);
    if (n == 1)
    {
      cout << 1 << endl;
      continue;
    }
    for (i = a[0]; i >= 1; i--)
      cout << a[i];
    cout << endl;
  }
}