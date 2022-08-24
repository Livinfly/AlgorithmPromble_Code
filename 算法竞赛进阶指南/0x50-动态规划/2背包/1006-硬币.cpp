#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110, M = 1e5 + 10;

int n, m;
int c[N], s[N], f[M], used[M];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(cin >> n >> m, n || m)
  {
    memset(f, 0, sizeof f);
    f[0] = true;
    for(int i = 1; i <= n; i ++) cin >> c[i];
    for(int i = 1; i <= n; i ++) cin >> s[i];
    for(int i = 1; i <= n; i ++)
    {
      memset(used, 0, sizeof used);
      for(int j = c[i]; j <= m; j ++)
        if(!f[j] && f[j-c[i]] && used[j-c[i]] < s[i])
          f[j] = true, used[j] = used[j-c[i]]+1;
    }
    int res = 0;
    for(int i = 1; i <= m; i ++)
      if(f[i]) res ++;
    cout << res << endl;
  }
  return 0;
}
/*
https://www.acwing.com/activity/content/code/content/1715600/
*/