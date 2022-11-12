#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const LL P = 998244353;

LL qpm(LL a, LL b) {
  LL ans = 1;
  a %= P;
  while (b) {
    if (b & 1) ans = ans * a % P;
    a = a * a % P;
    b >>= 1;
  }
  return ans;
}
void solve() {
  LL n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  int cnt0 = count(all(a), 0);
  int cnt = count(a.begin(), a.begin() + cnt0, 1);
  LL tot = n * (n - 1) / 2 % P, ans = 0;
  for (LL i = cnt; i >= 1; i--) ans = (ans + tot * qpm(i * i, P - 2) % P) % P;
  cout << ans << '\n';
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