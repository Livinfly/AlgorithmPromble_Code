#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int l1, r1, l2, r2;

inline void work()
{
  for(int i = l1; i <= r1; i ++)
    for(int j = l2; j <= r2; j ++)
      if(i != j) 
      {
        cout << i << ' ' << j << endl;
        return;
      }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while(T --)
	{
	  
	  cin >> l1 >> r1 >> l2 >> r2;
	  work();
	}
	
	return 0;
}