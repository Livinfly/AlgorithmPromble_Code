#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int P = 998244353;

int n, k;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    cout << get_cnt(i);
    if (i == n)
      cout << endl;
    else
      cout << ' ';
  }

  return 0;
}