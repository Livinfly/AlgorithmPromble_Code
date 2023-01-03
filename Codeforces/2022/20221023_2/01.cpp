#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  int d = a[0];
  for (int i = 1; i < n; i++) d = __gcd(d, a[i]);
  if (d == 1)
    cout << 0 << '\n';
  else if (__gcd(n, d) == 1)
    cout << 1 << '\n';
  else if (__gcd(n - 1, d) == 1)
    cout << 2 << '\n';
  else
    cout << 3 << '\n';
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