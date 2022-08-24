#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e6+10;

int n, m;
bool f[N];

int main()
{
//   ios::sync_with_stdio(0);
//   cin.tie(0);
  while(~scanf("%d%d", &n, &m))
  {
    memset(f, 0, sizeof f);
    // cin >> n >> m;
    for(int i = 0; i < n; i ++)
    {
      int a;
    //   cin >> a;
      scanf("%d", &a);
    //   cout << a << endl;
      f[a+500000] = 1;
    }
    for(int i = (int)1e6; i>=0&&m; i --)
    {
      if(f[i]) 
      {
        // cout << i-5e5;
        printf("%d", i-500000);
        m --;
        if(m) putchar(' ');
      }
    }
    // cout << endl;
    puts("");
  }
  
  return 0;
}