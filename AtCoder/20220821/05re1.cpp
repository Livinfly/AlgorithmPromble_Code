#pragma GCC optimize(2)

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int P = 998244353;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<PII> dxy(3);
  for (int i = 0; i < 3; i++)
    cin >> dxy[i].first >> dxy[i].second;
  set<PII> S;
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    S.insert({x, y});
  }
  map<PII, int> f;
  f[{0, 0}] = 1;
  for (int i = 0; i < n; i++)
  {
    map<PII, int> nf;
    for (auto [xy, val] : f)
    {
      auto [x, y] = xy;
      for (auto [dx, dy] : dxy)
        if (S.find({x + dx, y + dy}) == S.end())
          nf[{x + dx, y + dy}] = (nf[{x + dx, y + dy}] + val) % P;
    }
    swap(f, nf);
  }
  int res = 0;
  for (auto [key, val] : f)
    res = (res + val) % P;
  cout << res << '\n';
  return 0;
}