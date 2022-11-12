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

int n, k, q;
int a[N], tr[N], refid[N];
LL s[N];
PII b[N];

int lowbit(int x) { return x & -x; }
void add(int x, int c) {
  for (; x <= n; x += lowbit(x)) tr[x] += c;
}
LL sum(int x) {
  LL ans = 0;
  for (; x; x -= lowbit(x)) ans += tr[x];
  return ans;
}
void solve() {
  cin >> n >> k;
  LL osum = 0;
  for (int i = 1; i <= n; i++) cin >> a[i], osum += a[i];
  for (int i = 1; i <= n; i++) cin >> b[i].fi, b[i].fi -= a[i], b[i].se = i;

  sort(b + 1, b + n + 1, greater<PII>());
  for (int i = 1; i <= n; i++) {
    refid[b[i].se] = i;
  }
  for (int i = 1; i <= n; i++) {
    add(i, 1);
    s[i] = s[i - 1] + b[i].fi;
  }
  cin >> q;
  while (q--) {
    int m;
    cin >> m;
    vector<int> id(m);
    for (int &x : id) cin >> x, add(refid[x], -1);
    int l = 1, r = n;
    while (l < r) {
      int mid = l + r >> 1;
      if (sum(mid) < k)
        l = mid + 1;
      else
        r = mid;
    }
    LL res = osum + s[r];
    for (int x : id) {
      if (refid[x] <= r) res -= b[refid[x]].fi;
      add(refid[x], 1);
    }
    cout << res << '\n';
  }
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