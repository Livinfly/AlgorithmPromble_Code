#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 5e5 + 10;

int cnt[N];

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int &x : a) cin >> x, cnt[x]++;
  for (int i = 1; i < x; i++) {
    if (cnt[i] % (i + 1)) {
      cout << "No\n";
      return;
    }
    cnt[i + 1] += cnt[i] / (i + 1);
  }
  if (cnt[x])
    cout << "Yes\n";
  else
    cout << "No\n";
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