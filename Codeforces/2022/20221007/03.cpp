#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
  int n;
  cin >> n;
  vector<PII> p(3);
  set<PII> S;
  int x1 = 1e9, y1 = 1e9, x2 = -1e9, y2 = -1e9;
  int cnt = 0;
  for (auto &x : p) {
    cin >> x.first >> x.second;
    S.insert(x);
    if (x.first == 1 || x.first == n || x.second == 1 || x.second == n) cnt++;
    x1 = min(x1, x.first);
    y1 = min(y1, x.second);
    x2 = max(x2, x.first);
    y2 = max(y2, x.second);
  }
  int px, py, tx, ty;
  for (int x : {x1, x2})
    for (int y : {y1, y2})
      if (S.find(make_pair(x, y)) == S.end()) px = x, py = y;
  for (int x : {x1, x2})
    for (int y : {y1, y2})
      if (x != px && y != py) tx = x, ty = y;
  // cout << px << ' ' << py << '\n';
  int x, y;
  cin >> x >> y;
  if (cnt == 3) {
    if (x == tx || y == ty)
      cout << "YES\n";
    else
      cout << "NO\n";
    return;
  }
  if ((px - x) % 2 == 0 && (py - y) % 2 == 0)
    cout << "NO\n";
  else
    cout << "YES\n";
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