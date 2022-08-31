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
  string sss = "Timur";
  int T;
  cin >> T; // scanf("%d", &T);
  while (T--)
  {
    int n;
    cin >> n;
    string str;
    cin >> str;
    if (n != 5)
    {
      cout << "NO\n";
      continue;
    }
    set<char> s;
    for (auto x : str)
      s.insert(x);
    bool flag = false;
    for (auto x : sss)
      if (s.find(x) == s.end())
      {
        flag = true;
        break;
      }
    if (flag)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}