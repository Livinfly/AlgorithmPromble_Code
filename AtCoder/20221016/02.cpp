#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int P = 998244353;

LL qpm(LL a, LL b) {
  LL ans = 1, t = a % P;
  while (b) {
    if (b & 1) ans = (ans * t) % P;
    t = (t * t) % P;
    b >>= 1;
  }
  return ans;
}
void solve() {
  LL n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  LL res = qpm(m, n);
  for (int i = 1; i <= n / 2; i++) res = ((res -) % P + P) % P;
  cout << res << '\n';
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