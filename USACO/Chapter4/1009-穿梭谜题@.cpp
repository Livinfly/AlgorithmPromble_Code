#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

int n;
string str, aim;
map<string, vector<int> >  mp;

inline bool dfs(string s, int p)
{
  if(s == aim)
  {
    vector<int> res = mp[aim];
    for(int i = 0; i < res.size(); i ++)
    {
      cout << res[i] << ' ';
      if(i && (i+1) % 20 == 0) cout << endl;
    }
    return true;
  }
  int cnt = 0, pos[5];
  string m[5];
  if(p-2 >= 1 && s[p-2] == 'W' && s[p-1] == 'B')
  {
    m[cnt] = s;
    swap(m[cnt][p-2], m[cnt][p]);
    pos[cnt] = p-2;
    cnt ++;
  }
  if(p-1 >= 1 && s[p-1] == 'W') 
  {
    m[cnt] = s;
    swap(m[cnt][p-1], m[cnt][p]);
    pos[cnt] = p-1;
    cnt ++;
  }
  if(p+1 <= n && s[p+1] == 'B')
  {
    m[cnt] = s;
    swap(m[cnt][p+1], m[cnt][p]);
    pos[cnt] = p+1;
    cnt ++;
  }
  if(p+2 <= n && s[p+2] == 'B' && s[p+1] == 'W')
  {
    m[cnt] = s;
    swap(m[cnt][p+2], m[cnt][p]);
    pos[cnt] = p+2;
    cnt ++;
  }
  for(int i = 0; i < cnt; i ++)
    if(!mp.count(m[i]))
    {
      mp[m[i]] = mp[s];
      mp[m[i]].push_back(pos[i]);
      if(dfs(m[i], pos[i])) return true;
    }
  return false;
}

int main()
{
	ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  str = aim = " ";
  for(int i = 1; i <= n; i ++) str += 'W', aim += 'B';
  str += ' ', aim += ' ';
  for(int i = 1; i <= n; i ++) str += 'B', aim += 'W';
  mp[str];
  n = n<<1|1;
	dfs(str, n/2+1);
	return 0;
}
