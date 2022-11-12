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
  string s;
  cin >> s;
  int res = 0;
  int p0 = -1;
  for (int i = 0; i < n; i++)
    if (s[i] != '0') {
      p0 = i - 1;
      break;
    }
  for (int i = n - 1; i > p0 + 1; i--)
    if (s[i] != s[i - 1]) res++;
  cout << res << '\n';
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