#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 15;

int time0[N];

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
    int n, H, M;
    cin >> n >> H >> M;
    int Time = H * 60 + M;
    for (int i = 0; i < n; i++)
    {
      int a, b;
      cin >> a >> b;
      time0[i] = a * 60 + b;
    }
    int res = 1e9;
    for (int i = 0; i < n; i++)
      res = min(res, (time0[i] - Time + 24 * 60) % (24 * 60));
    cout << res / 60 << ' ' << res % 60 << endl;
  }
  return 0;
}