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
  for (int &x : a) cin >> x, sum += abs(x);
  if (sum & 1) {
    cout << "-1\n";
    return;
  }
  int res = 0, cnt0 = 0, last = 0, lastp = 0;
  for (int i = 0; i < n; i++) {
    if (!a[i])
      cnt0++;
    else {
      if (!last) {
        last = a[i];
        lastp = i;
        if (i) res++;
        cnt0 = 0;
        continue;
      }
      if (cnt0 % 2 == 0 && a[i] == last || cnt0 % 2 && a[i] != last)
        res++;
      else
        res += 2;
      cnt0 = 0;
      last = a[i + 1];
      lastp = i + 1;
      i++;
    }
  }
  if (!a[n - 1]) res++;
  cout << res << '\n';
  cnt0 = last = lastp = 0;
  for (int i = 0; i < n; i++) {
    if (!a[i])
      cnt0++;
    else {
      if (!last) {
        if (i) cout << lastp + 1 << ' ' << i << '\n';
        last = a[i];
        lastp = i;
        cnt0 = 0;
        continue;
      }
      if (cnt0 % 2 == 0 && a[i] == last || cnt0 % 2 && a[i] != last)
        cout << lastp + 1 << ' ' << i + 1 << '\n';
      else {
        cout << lastp + 1 << ' ' << lastp + 1 << '\n'
             << lastp + 2 << ' ' << i + 1 << '\n';
      }
      cnt0 = 0;
      last = a[i + 1];
      lastp = i + 1;
      i++;
    }
  }
  if (!a[n - 1]) cout << lastp + 1 << ' ' << n << '\n';
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