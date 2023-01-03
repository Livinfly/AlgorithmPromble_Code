#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5+10;

LL n, res;
char s[N];
int cnt[12];

void work(LL x) {
  int diff = 0, maxv = 0;;
  for(int i = 0; i < 10; i ++) cnt[i] = 0;
  for(int j = x; j <= min(n, x+100); j ++) {
    int t = s[j]-'0';
    if(!cnt[t]) {
      diff ++;
    }
    cnt[t] ++;
    maxv = max(maxv, cnt[t]);
    if(maxv > diff) continue;
    res ++;
    // cout << x << ' ' << j << '\n';
  }
}
void solve() {
  res = 0;
  cin >> n >> s+1;
  for(int i = 1; i <= n; i ++) 
    work(i);
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