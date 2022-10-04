#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int stk[N], top;

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
    top = 0;
    string s;
    cin >> s;
    map<int, int> mp;
    for (auto x : s)
    {
      int t = x - '0';
      while (top && stk[top] > t)
        mp[stk[top--]]++;
      bool flag = false;
      for (auto x : mp)
        if (x.first + 1 < t)
        {
          flag = true;
          break;
        }
      if (flag)
        mp[t]++;
      else
        stk[++top] = t;
    }
    int i = 1;
    auto iter = mp.begin();
    while (i <= top || iter != mp.end())
    {
      if (iter == mp.end() || i <= top && stk[i] < iter->first)
        cout << stk[i++];
      else if (iter != mp.end())
      {
        for (int j = 0; j < iter->second; j++)
          cout << min(iter->first + 1, 9);
        iter++;
      }
    }
    cout << '\n';
  }
  return 0;
}