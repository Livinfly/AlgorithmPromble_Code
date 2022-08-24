#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int n, m;
map<string, int> shops;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  while (cin >> n)
  {
    shops.clear();

    for (int i = 0; i < n; i++)
    {
      string s1;
      cin >> s1;
    }
    cin >> m;
    while (m--)
    {
      for (int i = 0; i < n; i++)
      {
        int x;
        string s1;
        cin >> x >> s1;
        shops[s1] += x;
      }
      int res = 1;
      for (auto x : shops)
      {
        if (x.second > shops["memory"])
          res++;
      }
      cout << res << endl;
    }
  }

  return 0;
}