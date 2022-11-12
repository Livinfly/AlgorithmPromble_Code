#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int N = 2e5+10;

int n;
LL a[N], s[N];

void solve() {
  cin >> n;
  map<LL, int> cnt;
  int p0 = 0;
  for(int i = 1; i <= n; i ++) {
    cin >> a[i];
    s[i] = s[i-1]+a[i];
    if(!a[i] && !p0) p0 = i;
  }
  int maxv = 0, last0 = p0, res = 0;
  for(int i = 1; i < p0; i ++) 
    if(!s[i]) res ++;
  for(int i = max(1, last0); i <= n; i ++) {
    if(!a[i]) {
      if(!last0) last0 = i;
      else {
        maxv = 0;
        for(auto x: cnt) 
          maxv = max(maxv, x.se);
        // cout << last0 << ' ' << i << ' ' << maxv << '\n';
        res += maxv;
        last0 = i;
        cnt.clear();
      }
    }
    cnt[s[i]] ++;
  }
  maxv = 0;
  for(auto x: cnt) 
    maxv = max(maxv, x.se);
  if(last0) res += maxv;
  else {
    res += cnt[0];
  }
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