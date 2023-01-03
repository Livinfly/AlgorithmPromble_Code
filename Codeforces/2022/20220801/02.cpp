#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;

int a[N];
bool vis[N];

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
    bool flag = false;
    memset(vis, 0, sizeof vis);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = n - 1; i >= 0; i--)
    {
      if (vis[a[i]])
      {
        cout << i + 1 << endl;
        flag = true;
        break;
      }
      else
        vis[a[i]] = true;
    }
    if (!flag)
      cout << 0 << endl;
  }
  return 0;
}