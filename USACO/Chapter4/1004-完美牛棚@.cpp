#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 210, M = N * N;

int idx, h[N], ne[M], ver[M];
int n, m;
int match[N];
bool st[N];

inline void add(int a, int b)
{
  ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
inline bool find(int u)
{
  for(int i = h[u]; ~i; i = ne[i])
  {
    int v = ver[i];
    if(!st[v])
    {
      st[v] = true;
      int t = match[v];
      if(!t || find(t)) 
      {
        match[v] = u;
        return true;
      }
    }
  }
  return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
      int s;
	    cin >> s;
	    while(s --)
	    {
	      int a;
	      cin >> a;
	      add(i, a);
	    }
    }
    int res = 0;
  for(int i = 1; i <= n; i ++)
  {
    memset(st, 0, sizeof st);
    if(find(i)) res ++;
  }
  cout << res << endl;
  return 0;
}
