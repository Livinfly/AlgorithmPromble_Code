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
  vector<int> a(n), b(n);
  int sum1 = 0, sum2 = 0;
  for (auto &x : a) {
    cin >> x;
    sum1 += x;
  }
  for (auto &x : b) {
    cin >> x;
    sum2 += x;
  }
  int res2 = 0;
  for (int i = 0; i < n; i++)
    if (a[i] != b[i]) res2++;
  cout << min(abs(sum1 - sum2) + 1, res2) << '\n';
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