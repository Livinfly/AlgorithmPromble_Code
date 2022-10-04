#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> d1, d2;

bool work(int pDist) {
  int p1 = 0, p2 = pDist;
  multiset<int> s1, s2;
  for (auto x : d1) s1.insert(x);
  for (auto x : d2) s2.insert(x);
  vector<int> ans;
  auto getMaxS = [](multiset<int> &s) { return s.empty() ? -1 : *s.rbegin(); };
  int max1 = getMaxS(s1), max2 = getMaxS(s2);
  while (max(max1, max2) > pDist) {
    bool is_s1 = max1 > max2;
    auto &s_far = is_s1 ? s1 : s2;
    auto &s_near = is_s1 ? s2 : s1;
    int t1 = *s_far.rbegin(), t2 = t1 - pDist;
    if (s_near.find(t2) == s_near.end()) return false;
    s_far.erase(s_far.find(t1));
    s_near.erase(s_near.find(t2));
    if (is_s1)
      ans.push_back(p1 + t1);
    else
      ans.push_back(p2 - t1);
    max1 = getMaxS(s1), max2 = getMaxS(s2);
  }
  auto iter1 = s1.begin();
  auto iter2 = s2.rbegin();
  for (; iter1 != s1.end(); iter1++, iter2++)
    if (*iter1 + *iter2 != pDist) return false;
  for (auto x : s1) ans.push_back(x);
  sort(all(ans));
  int dx = min(ans[0], 0);
  cout << "YES\n";
  for (auto x : ans) cout << x - dx << ' ';
  cout << '\n';
  cout << p1 - dx << ' ' << p2 - dx << '\n';
  return true;
}
void solve() {
  cin >> n;
  d1.resize(n);
  d2.resize(n);
  for (auto &x : d1) cin >> x;
  for (auto &x : d2) cin >> x;
  int x = d1[0];
  for (auto y : d2)
    if (work(x + y) || work(abs(x - y))) return;
  cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(20);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  cin >> T;  // scanf("%d", &T);
  while (T--) solve();
  return 0;
}