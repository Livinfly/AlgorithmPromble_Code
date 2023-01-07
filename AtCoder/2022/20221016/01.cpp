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
  string s1, s2;
  int cnt1, cnt2;
  cnt1 = cnt2 = 0;
  cin >> s1 >> s2;
  vector<int> res(n), num1, num2;
  for (int i = 0; i < n; i++) {
    if (s1[i] == '0' && s2[i] == '1')
      cnt1++, num1.push_back(i);
    else if (s1[i] == '1' && s2[i] == '0')
      cnt2++, num2.push_back(i);
  }
  int cnt = abs(cnt1 - cnt2) / 2;
  if ((cnt1 - cnt2) % 2 || (cnt1 < cnt2 && num2.size() < cnt) ||
      (cnt1 > cnt2 && num1.size() < cnt)) {
    cout << -1 << '\n';
    return;
  }
  if (cnt1 < cnt2) {
    for (int i = num2.size() - 1, j = 0; j < cnt; i--, j++) res[num2[i]] = 1;
  } else {
    for (int i = num1.size() - 1, j = 0; j < cnt; i--, j++) res[num1[i]] = 1;
  }
  for (auto x : res) {
    cout << x;
  }
  cout << '\n';
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