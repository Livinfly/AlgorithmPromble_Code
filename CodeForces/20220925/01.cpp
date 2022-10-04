#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  cin >> T; // scanf("%d", &T);
  while (T--)
  {
    int n, c;
    cin >> n >> c;
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      cnt[x]++;
    }
    LL res = 0;
    for (auto x : cnt)
    {
      res += min(x.second, c);
    }
    cout << res << '\n';
  }
  return 0;
}