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
  int n, k, q;
  cin >> n >> k >> q;
  int ans;
  k %= n+n;
  if(q&1) {
    if(q+k<=n) {
      ans = q+k;
    }
    else if(k+q-n <= n){
      ans = n-(q+k-n)+1;
    }
    else {
      ans = k+q-n-n;
    }
  }
  else {
    if(q-k >= 1) {
      ans = q-k;
    }
    else if(k-q+1 <= n) {
      ans = k-q+1;
    }
    else {
      ans = n-(k-q+1-n)+1;
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
  int T;
  cin >> T;  // scanf("%d", &T);
  while (T--) solve();
  return 0;
}
/*
找规律，耐心分类
*/