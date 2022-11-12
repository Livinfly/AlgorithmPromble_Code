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
  string s;
  cin >> n >> s;
  int cnt = 0;
  for (auto x : s) {
    if (x == 'Q')
      cnt++;
    else
      cnt = max(0, cnt - 1);
  }
  if (cnt)
    cout << "No\n";
  else
    cout << "Yes\n";
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