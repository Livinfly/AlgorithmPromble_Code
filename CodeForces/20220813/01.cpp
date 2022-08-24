#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 110;

int n, k;
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
    int res = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if (i < k && a[i] > k)
        res++;
    }

    cout << res << '\n';
  }
  return 0;
}