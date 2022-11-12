#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

void solve() {
  set<LL> st;
  map<LL, LL> mp;
  int q;
  cin >> q;
  while (q--) {
    char op[2];
    LL x;
    cin >> op >> x;
    if (*op == '+')
      st.insert(x);
    else {
      while (st.count(mp[x] + x)) mp[x] += x;
      cout << mp[x] + x << '\n';
    }
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