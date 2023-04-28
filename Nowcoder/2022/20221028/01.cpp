#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

char g[7][7];

void solve() {
  for (int i = 0; i < 4; i++) cin >> g[i];

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (g[i][j] == g[i][j + 1] && g[i][j] == g[i + 1][j] &&
          g[i][j] == g[i + 1][j + 1]) {
        cout << "Yes\n";
        return;
      }
  cout << "No\n";
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