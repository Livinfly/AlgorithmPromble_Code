#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

LL n, q;
LL a[N], s[N], xs[N];
set<LL> S;

void work(int L, int R) {
  LL res = s[R] - s[L - 1] - (xs[R] ^ xs[L - 1]), ll = L, rr = R;
  // cout << res << '\n';
  auto il = S.lower_bound(L), ir = S.upper_bound(R), ir2 = ir;
  if (il == S.end() || *il > R) {
    cout << L << ' ' << L << '\n';
    return;
  }
  ir--;
  for (int i = 0; i < 31; i++) {
    if (il == S.end() || *il > R) break;
    ir2 = ir;
    for (int j = 0; j < 31; j++) {
      if (*ir2 < L) break;
      LL tl = *il, tr = *ir2;
      if (tl > tr) break;
      if (s[tr] - s[tl - 1] - (xs[tr] ^ xs[tl - 1]) == res) {
        if (tr - tl < rr - ll) {
          rr = tr, ll = tl;
        }
      }
      if (ir2 == S.begin()) break;
      ir2--;
    }
    il++;
  }
  cout << ll << ' ' << rr << '\n';
}
void solve() {
  S.clear();
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
    xs[i] = xs[i - 1] ^ a[i];
    if (a[i]) S.insert(i);
  }
  while (q--) {
    int L, R;
    cin >> L >> R;
    work(L, R);
  }
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
左端点的缩进影响右端点，需要依次枚举
set清空
*/