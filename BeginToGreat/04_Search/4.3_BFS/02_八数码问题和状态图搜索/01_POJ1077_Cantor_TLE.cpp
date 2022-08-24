#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int N = 362880;
const int factory[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

struct Node
{
  string st, path;
};
bool vis[N];
string str;
queue<Node> q;

bool Cantor(string str, int n = 9)
{
  int CantorIdx = 0;
  for (int i = 0; i < n; i++)
  {
    int cnt = 0;
    for (int j = i + 1; j < n; j++)
      if (str[i] > str[j])
        cnt++;
    CantorIdx += cnt * factory[n - i - 1];
  }
  if (!vis[CantorIdx])
  {
    vis[CantorIdx] = true;
    return false;
  }
  return true;
}
void bfs()
{
  q.push((Node){str, ""});
  Cantor(str);
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
      if (!Cantor(tmp.st))
      {
        tmp.path += 'u';
        q.push(tmp);
      }
    }
    tmp = t;
    if (pos < 6) // down
    {
      swap(tmp.st[pos], tmp.st[pos + 3]);
      if (!Cantor(tmp.st))
      {
        tmp.path += 'd';
        q.push(tmp);
      }
    }
    tmp = t;
    if (pos % 3 != 0) // left
    {
      swap(tmp.st[pos], tmp.st[pos - 1]);
      if (!Cantor(tmp.st))
      {
        tmp.path += 'l';
        q.push(tmp);
      }
    }
    tmp = t;
    if (pos % 3 != 2) // right
    {
      swap(tmp.st[pos], tmp.st[pos + 1]);
      if (!Cantor(tmp.st))
      {
        tmp.path += 'r';
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