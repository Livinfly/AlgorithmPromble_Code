#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <unordered_map>

using namespace std;

string ans, sss = "lurdluurddruulddrulldrru";
char ch[5] = "dlru";
queue<string> q[2];
unordered_map<string, string> mp[2];

void init()
{
  for (int i = 0; i < 2; i++)
  {
    mp[i].clear();
    while (q[i].size())
      q[i].pop();
  }
  ans = "n";
}
string get_nstatus(string str, int pos, int type)
{
  switch (type)
  {
  // down
  case 0:
    if (pos < 6)
      swap(str[pos], str[pos + 3]);
    else
      str = "n";
    break;
  // left
  case 1:
    if (pos % 3 != 0)
      swap(str[pos], str[pos - 1]);
    else
      str = "n";
    break;
  // right
  case 2:
    if (pos % 3 != 2)
      swap(str[pos], str[pos + 1]);
    else
      str = "n";
    break;
  // up
  case 3:
    if (pos >= 3)
      swap(str[pos], str[pos - 3]);
    else
      str = "n";
    break;
  }
  return str;
}
void update_nstatus(queue<string> &q, unordered_map<string, string> &mp1, unordered_map<string, string> &mp2, string t, int pos, int i, bool is_ordered)
{
  string nt = get_nstatus(t, pos, i);
  if (nt != "n" && (!mp1.count(nt) || mp1[t].size() + 1 <= mp1[nt].size())) // 是小于等于啊，等于可以带来字典序的优化！！！！
  {
    if (is_ordered && (!mp1.count(nt) || mp1[t] + ch[i] < mp1[nt])) // 要判断没有 或者 字典序更小
    {
      mp1[nt] = mp1[t] + ch[i];
      if (mp2.count(nt))
      {
        string res = mp1[nt] + mp2[nt];
        //         if (res == sss)
        //         {
        //           cout << "sss" << endl;
        //           cout << mp[0][nt].size() << ' ' << mp[1][nt].size() << endl;
        //         }
        if (ans == "n" || (res.size() == ans.size() && res < ans))
          ans = res;
      }
    }
    else if (!is_ordered && (!mp1.count(nt) || ch[3 - i] + mp1[t] < mp1[nt]))
    {
      mp1[nt] = ch[3 - i] + mp1[t];
      if (mp2.count(nt))
      {
        string res = mp2[nt] + mp1[nt];
        //         if (res == sss)
        //         {
        //           cout << "sss" << endl;
        //           cout << mp[0][nt].size() << ' ' << mp[1][nt].size() << endl;
        //         }
        if (ans == "n" || (res.size() == ans.size() && res < ans))
          ans = res;
      }
    }
    if (ans != "n" && mp1[nt].size() * 2 > ans.size())
      return;
    q.push(nt);
  }
}
void expand(queue<string> &q, unordered_map<string, string> &mp1, unordered_map<string, string> &mp2, bool is_ordered)
{
  string t = q.front();
  q.pop();
  int pos;
  for (int i = 0; i < 9; i++)
    if (t[i] == 'X')
    {
      pos = i;
      break;
    }
  // dlru
  for (int i = 3; i >= 0; i--)
    update_nstatus(q, mp1, mp2, t, pos, i, is_ordered);
  // urld 倒着接，所以是前一个尽可能小。
}
void dbfs(string A, string Z)
{
  mp[0][A] = "", mp[1][Z] = "";
  q[0].push(A), q[1].push(Z);
  while (q[0].size() && q[1].size())
  {
    if (q[0].size() < q[1].size())
      expand(q[0], mp[0], mp[1], true);
    else
      expand(q[1], mp[1], mp[0], false);
  }
  //	for(auto x: mp[0])
  //		cout << x.second.size() << endl;
  for (int i = 0; i < 2; i++)
  {
    while (q[i].size())
      expand(q[i], mp[i], mp[1 - i], !i);
  }
}

int main()
{
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  //    freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int Case0 = 1; Case0 <= T; Case0++)
  {
    init();
    string A, Z;
    cin >> A >> Z;
    dbfs(A, Z);
    printf("Case %d: %d\n", Case0, ans.size());
    cout << ans << '\n';
  }
  return 0;
}
