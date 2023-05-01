#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;

int Case, n;
int ne[N];
char str[N];

inline void get_next()
{
  ne[1] = 0;
  for(int i = 2, j = 0; i <= n; i ++)
  {
    while(j && str[j+1] != str[i]) j = ne[j];
    if(str[j+1] == str[i]) j ++;
    ne[i] = j;
  }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n, n)
    {
      cout << "Test case #" << ++ Case << endl;
      cin >> str + 1;
      get_next();
      for(int i = 2; i <= n; i ++)
        if(ne[i] && i%(i-ne[i]) == 0) 
        cout << i << ' ' << i/(i-ne[i]) << endl;
      cout << endl;
    }

    return 0;
}

作者：ioj
链接：https://www.acwing.com/activity/content/code/content/1624895/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。