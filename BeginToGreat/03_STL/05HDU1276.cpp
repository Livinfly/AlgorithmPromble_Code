#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <list>

using namespace std;

list<int> li;
list<int>::iterator iter;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T; cin >> T;
  while(T --)
  {
    int n;
    cin >> n;
    li.clear();
    for(int i = 1; i <= n; i ++) 
      li.push_back(i);
    int k = 2;
    while(li.size() > 3)
    {
      int t = 1;
      for(iter = li.begin(); iter != li.end();)
      {
        if(t ++ % k == 0)
          iter = li.erase(iter);
        else 
          iter ++;
      }
      k == 2 ? k = 3 : k = 2;
    }
    for(auto x = li.begin(); x != li.end(); x ++)
    {
      if(x != li.begin()) cout << ' ';
      cout << *x;
    }
    cout << endl;
  }
  return 0;
}