#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 30;

int n, m;
int ind[N];
char str[N][N];
bool g[N][N], st[N];
string path;

inline void work(int x1, int y1, int x2, int y2, char c)
{
  for(int i = x1; i <= x2; i ++)
    for(int j = y1; j <= y2; j ++)
      if(str[i][j] != c)
      {
        int a = c-'A', b = str[i][j]-'A';
        if(!g[a][b])
        {
          g[a][b] = true;
          ind[b] ++;
        }
      }
}
inline void dfs(string s)
{
  if(s.empty())
  {
    cout << path << endl;
    return;
  }
  sort(s.begin(), s.end());
  for(int i = 0; i < s.size(); i ++)
  {
    char c = s[i];
    path += c;
    string t = s.substr(0, i) + s.substr(i+1);
    for(int j = 0; j < 26; j ++)
      if(g[c-'A'][j] && -- ind[j] == 0) t += j+'A'; 
    dfs(t);
    path.erase(path.end()-1);
    for(int j = 0; j < 26; j ++)
      if(g[c-'A'][j]) ind[j] ++;
  }
}
inline void toposort()
{
  string s = "";
  for(int i = 0; i < 26; i ++)
    if(st[i] && !ind[i]) s += i+'A';
  dfs(s);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i ++) cin >> str[i];
	for(char c = 'A'; c <= 'Z'; c ++)
	{
	  int x1 = N, y1 = N, x2 = -1, y2 = -1;
  	for(int i = 0; i < n; i ++)
  	  for(int j = 0; j < m; j ++)
  	    if(str[i][j] == c)
  	    {
  	      x1 = min(x1, i), x2 = max(x2, i);
  	      y1 = min(y1, j), y2 = max(y2, j);
  	    }
    if(x1 == N) continue;
    work(x1, y1, x1, y2, c);
    work(x1, y2, x2, y2, c);
    work(x2, y1, x2, y2, c);
    work(x1, y1, x2, y1, c);
    st[c-'A'] = true;
	}
	toposort();
	return 0;
}