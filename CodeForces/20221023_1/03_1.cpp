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
  int sum = 0;
  for (int &x : a) cin >> x;
  if (n & 1) {
    cout << "-1\n";
    return;
  }
  int res = 0;
  for (int i = 0; i < n; i += 2) {
    if (a[i] == a[i + 1])
      res++;
    else
      res += 2;
  }
  cout << res << '\n';
  for (int i = 0; i < n; i += 2) {
    if (a[i] == a[i + 1])
      cout << i + 1 << ' ' << i + 2 << '\n';
    else
      cout << i + 1 << ' ' << i + 1 << '\n' << i + 2 << ' ' << i + 2 << '\n';
  }
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