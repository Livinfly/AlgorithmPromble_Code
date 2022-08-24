#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e4 + 10;

int n;
int a[N];

int main()
{
  ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
  while(T --)
  {
    cin >> n;
    n ++;
    int p1 = 0;
    for(int i = 1; i <= n-1; i ++) 
    {
      cin >> a[i];
      if(!p1 && a[i]) p1 = i;
    }
    if(!p1)
    {
      for(int i = 1; i <= n; i ++)
        cout << i << ' ';
      cout << endl;
    }
    else
    {
      if(p1 == 1)
      {
        cout << n << ' ';
        for(int i = 1; i <= n-1; i ++)
          cout << i << ' ';
        cout << endl;
      }
      else
      {
        for(int i = 1; i <= p1-1; i ++)
          cout << i << ' ';
        cout << n << ' ';
        for(int i = p1; i <= n-1; i ++)
          cout << i << ' ';
        cout << endl;
      }
    }
  }
  
  return 0;
}
