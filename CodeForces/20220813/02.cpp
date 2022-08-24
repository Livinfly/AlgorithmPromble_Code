#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n;
int a[N];

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
    cin >> n;
    for (int i = 1; i <= n; i++)
      a[i] = i;
    for (int i = n; i >= 2; i -= 2)
      swap(a[i], a[i - 1]);
    for (int i = 1; i <= n; i++)
      cout << a[i] << " \n"[i == n];
  }
  return 0;
}