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
  int n, cnt0 = 0, cnt1 = 0, res0 = 0, res1 = 0;  // 不包含
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      cnt0 = 0;
      cnt1++;
    } else if (s[i] == '1') {
      cnt1 = 0;
      cnt0++;
    } else {
      cnt0++, cnt1++;
    }
    res0 = max(res0, cnt0);
    res1 = max(res1, cnt1);
  }
  cout << max(res0, res1) << '\n';
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