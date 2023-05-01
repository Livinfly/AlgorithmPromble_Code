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
  int val;
  string st, path;

  bool operator<(const Node &o) const
  {
    return val > o.val;
  }
};
bool vis[N];
string str;
priority_queue<Node> heap;

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
int f(string str, int n = 9)
{
  int res = 0;
  for (int i = 0; i < n; i++)
    if (str[i] != 'x')
    {
      int t = str[i] - '1';
      int oa = t / 3, ob = t % 3;
      int na = i / 3, nb = i % 3;
      res += abs(oa - na) + abs(ob - nb);
    }
  return res;
}
void bfs()
{
  heap.push((Node){f(str), str, ""});
  Cantor(str);
  while (heap.size())
  {
    Node t = heap.top(), tmp;
    heap.pop();
    // cout << t.val << " " << t.st << " " << t.path << endl;
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
        tmp.val = f(tmp.st) + tmp.path.size();
        heap.push(tmp);
      }
    }
    tmp = t;
    if (pos < 6) // down
    {
      swap(tmp.st[pos], tmp.st[pos + 3]);
      if (!Cantor(tmp.st))
      {
        tmp.path += 'd';
        tmp.val = f(tmp.st) + tmp.path.size();
        heap.push(tmp);
      }
    }
    tmp = t;
    if (pos % 3 != 0) // left
    {
      swap(tmp.st[pos], tmp.st[pos - 1]);
      if (!Cantor(tmp.st))
      {
        tmp.path += 'l';
        tmp.val = f(tmp.st) + tmp.path.size();
        heap.push(tmp);
      }
    }
    tmp = t;
    if (pos % 3 != 2) // right
    {
      swap(tmp.st[pos], tmp.st[pos + 1]);
      if (!Cantor(tmp.st))
      {
        tmp.path += 'r';
        tmp.val = f(tmp.st) + tmp.path.size();
        heap.push(tmp);
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
  // spj 无解
  int cnt = 0;
  for (int i = 0; i < str.size(); i++)
    for (int j = i + 1; j < str.size(); j++)
      if (str[i] > str[j] && str[i] != 'x' && str[j] != 'x')
        cnt++;
  if (cnt & 1)
    cout << "unsolvable" << '\n';
  else
    bfs();
  return 0;
}
/*
不加逆序对特判无解 2552ms
加了76ms
*/