#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

void solve() {
  LL n, m;
  cin >> n >> m;
  if (!m) {
    int t = n - 2, res = 0;
    if ((t + 1) % 4 == 0)
      res += (t + 1) % 2;
    else if (t % 4 == 0)
      res++;
    else if ((t + 2) % 4 == 0)
      res++;
    if (res)
      cout << "Aoki\n";
    else
      cout << "Takahashi\n";
    return;
  }
  vector<PLL> a(m);
  for (auto &x : a) cin >> x.fi >> x.se;
  sort(all(a));
  int res = 0;
  if (a[0].fi) res++;
  if (a[m - 1].fi != min(n, (LL)2e5)) res++;
  for (int i = 0; i < m - 1; i++)
    if (a[i].se == a[i + 1].se) {
      int t = a[i + 1].fi - a[i].fi - 1;
      if ((t + 1) % 4 == 0)
        res += (t + 1) % 2;
      else if (t % 4 == 0)
        res++;
      else if ((t + 2) % 4 == 0)
        res++;
    }
  if (res & 1)
    cout << "Aoki\n";
  else
    cout << "Takahashi\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed;  // << setprecision(20); // double
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  solve();
  return 0;
}