#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  LL res = 0;
  for (auto &x : a) cin >> x, res += x;
  if (res % 3) {
    cout << "0\n";
    return;
  }
  res /= 3;
  LL ss = 0;
  vector<int> cnt(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    ss += a[i];
    if (ss == res) {
      cnt[i] = 1;
    }
  }
  for (int i = n - 2; i >= 0; i--) cnt[i] += cnt[i + 1];
  ss = 0;
  LL ans = 0;
  for (int i = 0; i < n - 2; i++) {
    ss += a[i];
    if (ss == res) {
      ans += cnt[i + 2];
    }
  }
  cout << ans << '\n';
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