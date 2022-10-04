#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 3e5 + 10;

int n, m, a, b;
int water[N];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  cin >> n >> m >> a >> b;
  int water_cnt = 0;
  set<int> S;
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    if (y)
    {
      water_cnt++, water[x]++;
      if (water_cnt >= a)
        S.insert(x);
      if (water[x] >= b)
        S.insert(x);
    }
    else
      water_cnt = water[x] = 0;
  }
  cout << S.size() << '\n';
  for (auto x : S)
    cout << x << ' ';
  cout << '\n';
  return 0;
}