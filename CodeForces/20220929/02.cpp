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
    vector<int> a(n);
    for (int &x : a)
      cin >> x;
    int sum = 0;
    for (auto x : a)
    {
      if (x && x <= sum)
      {
        sum = -1;
        break;
      }
      sum += x;
    }
    if (sum == -1)
    {
      cout << -1 << '\n';
      continue;
    }
    sum = 0;
    for (auto x : a)
    {
      sum += x;
      cout << sum << ' ';
    }
    cout << '\n';
  }
  return 0;
}