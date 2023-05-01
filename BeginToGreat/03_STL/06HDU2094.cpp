#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

int n;
set<string> all, loss;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  while (cin >> n, n)
  {
    all.clear();
    loss.clear();
    for (int i = 0; i < n; i++)
    {
      string a, b;
      cin >> a >> b;
      all.insert(a);
      all.insert(b);
      loss.insert(b);
    }
    if (all.size() == loss.size() + 1)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}