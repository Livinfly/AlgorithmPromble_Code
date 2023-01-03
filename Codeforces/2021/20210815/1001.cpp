#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n, res;

int main()
{
  ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
  while(T --)
  {
    cin >> n;
    res = -1;
    for(int i = 1; i <= n; i ++)
    {
      int a;
      cin >> a;
      res &= a;
    }
    cout << res << endl;
  }
  
    return 0;
}
