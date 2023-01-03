#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  map<int, int> mp;
  for (int i = 0; i < 26; i++) mp[i] = 0;
  for (auto x : str) mp[(int)x - 'a']++;
  int nums = n / k;
  for (int i = 0; i < k; i++) {
    int cnt = 0;
    bool flag = false;
    for (auto &x : mp) {
      // cout << x.first << ' ' << x.second << '\n';
      if (x.second > 0)
        x.second--, cnt++;
      else if (!x.second && !flag) {
        cout << (char)(x.first + 'a');
        flag = true;
      }
      if (cnt == nums) break;
    }
    if (!flag) cout << (char)(nums + 'a');
  }
  cout << '\n';
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