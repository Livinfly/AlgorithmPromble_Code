#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
  LL l, r;
  cin >> l >> r;
  LL sq1 = (LL)sqrt(l), sq2 = (LL)sqrt(r);
  LL ll = sq1 * sq1, rr = sq2 * sq2;
  LL res = (sq2 - sq1) * 3 + 1 - (LL)(l - ll - 1) / sq1 + (LL)(r - rr) / sq2;
  if (l != ll) res--;
  if (l == 1) res--;
  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed;  // << setprecision(20); // double
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  cin >> T;  // scanf("%d", &T);
  while (T--) solve();
  return 0;
}