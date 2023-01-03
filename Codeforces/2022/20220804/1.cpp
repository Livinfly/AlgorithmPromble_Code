#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n;

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
    cin >> n;
    if (n % 3 == 0)
      cout << n / 3 << endl;
    else if (n % 3 == 2)
      cout << n / 3 + 1 << endl;
    else
    {
      if (n == 1)
        cout << 2 << endl;
      else
        cout << (n - 4) / 3 + 2 << endl;
    }
  }
  return 0;
}