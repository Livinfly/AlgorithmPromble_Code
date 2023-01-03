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
    string str;
    cin >> str;
    LL tres = 0;
    for (int i = 0; i < n; i++)
    {
      if (str[i] == 'L')
        tres += i;
      else
        tres += n - i - 1;
    }
    vector<LL> ans;
    LL l = 0, r = n - 1, mid = n / 2;
    while (ans.size() < n && (l < mid || r > mid - (n % 2 == 0)))
    {
      while (l < mid && str[l] == 'R')
        l++;
      while (r > mid - (n % 2 == 0) && str[r] == 'L')
        r--;
      int dl = l, dr = n - r - 1;
      if (l < mid && dl <= dr && str[l] != 'R')
      {
        str[l] = 'R';
        tres -= l, tres += n - l - 1;
      }
      else if (r > mid - (n % 2 == 0) && str[r] != 'L')
      {
        str[r] = 'L';
        tres -= n - r - 1, tres += r;
      }
      ans.emplace_back(tres);
    }
    for (LL &x : ans)
      cout << x << ' ';
    for (int i = 0; i < n - ans.size(); i++)
      cout << tres << ' ';
    cout << '\n';
  }
  return 0;
}