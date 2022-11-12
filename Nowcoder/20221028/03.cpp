#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const __int128_t P = (1LL << 63) - 1LL;

void solve() {
  LL l, r, k;
  cin >> l >> r >> k;
  __int128_t t = 1;
  bool flag = false;
  while (t <= r) {
    if (t >= l) {
      cout << (LL)t << ' ';
      flag = true;
    }
    t = t * (__int128_t)k;
    if (t >= P) break;
  }
  if (!flag) {
    cout << "None.";
  }
  cout << '\n';
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