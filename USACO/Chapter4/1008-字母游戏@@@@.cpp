#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

const int N = 5110;

int score[30] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
int n, res;
int cnt[30];
string str, s[N];

inline int get_score(string s)
{
  int res = 0;
  for(int i = 0; i < s.size(); i ++)
    res += score[s[i]-'a'];
  return res;
}
inline bool check(string s1, string s2)
{
  bool flag = true;
  for(int i = 0; i < s1.size(); i ++)
    if(-- cnt[s1[i]-'a'] < 0) flag = false;
  for(int i = 0; i < s2.size(); i ++)
    if(-- cnt[s2[i]-'a'] < 0) flag = false;
  for(int i = 0; i < s1.size(); i ++) cnt[s1[i]-'a'] ++;
  for(int i = 0; i < s2.size(); i ++) cnt[s2[i]-'a'] ++;
  return flag;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;
	for(int i = 0; i < str.size(); i ++) cnt[str[i]-'a'] ++;
  while(cin >> s[n], s[n] != ".")
  {
    bool flag = true;
    for(int i = 0; i < s[n].size(); i ++)
      if(-- cnt[str[i]-'a'] < 0) flag = false;
    for(int i = 0; i < s[n].size(); i ++)
      cnt[str[i]-'a'] ++;
    if(flag) n ++;
  }
	for(int i = 0; i < n; i ++)
  {
    int t = get_score(s[i]);
    res = max(res, t);
    for(int j = i+1; j < n; j ++)
      if(check(s[i], s[j]))
        res = max(res, t+get_score(s[j]));
  }
	cout << res << endl;
  for(int i = 0; i < n; i ++)
  {
    int t = get_score(s[i]);
    if(res == t)
    {
      cout << s[i] << endl;
      continue;
    }
    for(int j = i+1; j < n; j ++)
      if(check(s[i], s[j]) && res == t+get_score(s[j]))
      {
        cout << s[i] << ' ' << s[j] << endl;
      }
  }
	return 0;
}