#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

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
    int n;
    cin >> n;
    int rec;
    for (int i = 9; i > 0; i--)
      if (n > i)
        n -= i;
      else
      {
        rec = i + 1;
        break;
      }

    cout << n;
    for (int i = rec; i <= 9; i++)
      cout << i;
    cout << endl;
  }
  return 0;
}