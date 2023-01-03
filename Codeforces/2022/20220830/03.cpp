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
    int n;
    cin >> n;
    set<string> S[3];
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < n; j++)
      {
        string x;
        cin >> x;
        S[i].insert(x);
      }
    vector<int> ans(3);
    for (int i = 0; i < 3; i++)
      for (auto x : S[i])
      {
        int d1 = (i + 1) % 3, d2 = (i + 2) % 3;
        bool f1 = S[d1].find(x) != S[d1].end(), f2 = S[d2].find(x) != S[d2].end();
        if (!f1 && !f2)
          ans[i] += 3;
        else if (!f1 && f2 || f1 && !f2)
          ans[i]++;
      }
    for (int i = 0; i < 3; i++)
      cout << ans[i] << " \n"[i == 2];
  }
  return 0;
}