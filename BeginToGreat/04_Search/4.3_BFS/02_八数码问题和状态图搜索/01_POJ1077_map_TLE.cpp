#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

struct Node
{
  string st, path;
};

string str;
queue<Node> q;
map<string, int> strInt;

void bfs()
{
  q.push((Node){str, ""});
  strInt[str] = 0;
  while (q.size())
  {
    Node t = q.front(), tmp;
    q.pop();
    if (t.st == "12345678x")
    {
      cout << t.path << '\n';
      return;
    }
    int pos;
    for (int i = 0; i < 9; i++)
      if (t.st[i] == 'x')
        pos = i;
    tmp = t;
    if (pos >= 3) // up
    {
      swap(tmp.st[pos], tmp.st[pos - 3]);
      if (strInt.count(tmp.st) == 0)
      {
        tmp.path += 'u';
        strInt[tmp.st] = strInt[t.st] + 1;
        q.push(tmp);
      }
    }
    tmp = t;
    if (pos < 6) // down
    {
      swap(tmp.st[pos], tmp.st[pos + 3]);
      if (strInt.count(tmp.st) == 0)
      {
        tmp.path += 'd';
        strInt[tmp.st] = strInt[t.st] + 1;
        q.push(tmp);
      }
    }
    tmp = t;
    if (pos % 3 != 0) // left
    {
      swap(tmp.st[pos], tmp.st[pos - 1]);
      if (strInt.count(tmp.st) == 0)
      {
        tmp.path += 'l';
        strInt[tmp.st] = strInt[t.st] + 1;
        q.push(tmp);
      }
    }
    tmp = t;
    if (pos % 3 != 2) // right
    {
      swap(tmp.st[pos], tmp.st[pos + 1]);
      if (strInt.count(tmp.st) == 0)
      {
        tmp.path += 'r';
        strInt[tmp.st] = strInt[t.st] + 1;
        q.push(tmp);
      }
    }
  }
  cout << "unsolvable" << '\n';
  return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  for (int i = 0; i < 9; i++)
  {
    char ch;
    cin >> ch;
    str += ch;
  }
  bfs();
  return 0;
}
// map TLE 怀疑是常数比较大
// unordered_map POJ不支持，acwing是过了，且先上下快点