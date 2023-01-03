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
    string s;
    cin >> s;
    vector<LL> ans(n + 1), dx(n);
    for (int i = 0; i < n; i++)
    {
      if (s[i] == 'L')
        ans[0] += i, dx[i] = (n - i - 1) - i;
      else
        ans[0] += n - i - 1, dx[i] = i - (n - i - 1);
    }
    sort(all(dx), greater<int>());
    for (int i = 1; i <= n; i++)
      ans[i] = ans[i - 1] + max(dx[i - 1], 0LL);
    for (int i = 1; i <= n; i++)
      cout << ans[i] << " \n"[i == n];
  }
  return 0;
}