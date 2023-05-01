#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 55;

int n;
bool g[N][N], st1[N], st2[N];
vector<int> res1, res2;

inline void dfs(int u, int p, bool st[])
{
  st[u] = true;
  for(int i = 0; i <= n; i ++)
    if(g[u][i] && !st[i] && i != p) dfs(i, p, st);
}

int main()
{
	int b;
  while(cin >> b, b != -1)
  {
    if(b != -2) g[n][b] = true;
    else n ++;
  }
	n --;
	for(int i = 1; i <= n-1; i ++)
  {
    memset(st1, 0, sizeof st1);
    memset(st2, 0, sizeof st2);
    dfs(0, i, st1);
    if(!st1[n])
    {
      res1.push_back(i);
      dfs(i, -1, st2);
      bool flag = true;
      for(int j = 0; j <= n; j ++)
        if(i != j && st1[j] && st2[j])
        {
          flag = false;
          break;
        }
      if(flag) res2.push_back(i);
    }
  }
	cout << res1.size();
  for(int i = 0; i < res1.size(); i ++)
    cout << ' ' << res1[i];
  cout << endl << res2.size();
  for(int i = 0; i < res2.size(); i ++)
    cout << ' ' << res2[i];
  cout << endl;
	return 0;
}