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
  LL l,r,k;
  cin >> l >> r >> k;
  l --;
  LL cnt = 0;
  for(LL i=1, j; i <= r; i = j+1) {
    j = min(r/(r/i), i<=l ? l/(l/i) : r);
    if(r/j - l/j >= k) {
      cnt += j-i+1;
    }
  }
  cout << cnt << '\n';
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