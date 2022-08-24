#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int N = 110;

struct Node
{
  int a, b;
  // 1,2->FILL,3,4->DROP,5,6->POUR
  string op;
};
int a, b, c;
bool vis[N][N];
queue<Node> q;

void pot_fill(Node &tNode, int obj)
{
  if (obj == 1)
    tNode.a = a;
  else
    tNode.b = b;
}
void pot_drop(Node &tNode, int obj)
{
  if (obj == 1)
    tNode.a = 0;
  else
    tNode.b = 0;
}
void pot_pour(Node &tNode, int obj)
{
  if (obj == 1) // 1->2
  {
    if (tNode.b + tNode.a > b)
    {
      tNode.a = tNode.b + tNode.a - b;
      tNode.b = b;
    }
    else
    {
      tNode.b = tNode.b + tNode.a;
      tNode.a = 0;
    }
  }
  else // 2->1
  {
    if (tNode.a + tNode.b > a)
    {
      tNode.b = tNode.a + tNode.b - a;
      tNode.a = a;
    }
    else
    {
      tNode.a = tNode.a + tNode.b;
      tNode.b = 0;
    }
  }
}
void op_print(string op)
{
  for (int i = 0; i < op.size(); i++)
  {
    if (op[i] == '1' || op[i] == '2')
      cout << "FILL(" << op[i] << ")" << '\n';
    else if (op[i] == '3' || op[i] == '4')
    {
      cout << "DROP(";
      if (op[i] == '3')
        cout << "1";
      else
        cout << "2";
      cout << ")" << '\n';
    }
    else
    {
      cout << "POUR(";
      if (op[i] == '5')
        cout << "1,2";
      else
        cout << "2,1";
      cout << ")" << '\n';
    }
  }
}
void bfs(int a, int b, int c)
{
  memset(vis, 0, sizeof vis);
  while (q.size())
    q.pop();
  q.push((Node){0, 0, ""});
  vis[0][0] = true;
  if (0 == c)
  {
    cout << 0 << '\n';
    return;
  }
  while (q.size())
  {
    Node t = q.front();
    q.pop();
    // cout << t.a << ' ' << t.b << endl;
    if (t.a == c || t.b == c)
    {
      cout << t.op.size() << '\n';
      op_print(t.op);
      return;
    }
    Node tmp;
    string str;
    // fill
    tmp = t;
    str = t.op + "1";
    pot_fill(tmp, 1);
    tmp.op = str;
    if (!vis[tmp.a][tmp.b])
    {
      q.push(tmp);
      vis[tmp.a][tmp.b] = true;
    }
    tmp = t;
    str = t.op + "2";
    pot_fill(tmp, 2);
    tmp.op = str;
    if (!vis[tmp.a][tmp.b])
    {
      q.push(tmp);
      vis[tmp.a][tmp.b] = true;
    }
    // drop
    tmp = t;
    str = t.op + "3";
    pot_drop(tmp, 1);
    tmp.op = str;
    if (!vis[tmp.a][tmp.b])
    {
      q.push(tmp);
      vis[tmp.a][tmp.b] = true;
    }
    tmp = t;
    str = t.op + "4";
    pot_drop(tmp, 2);
    tmp.op = str;
    if (!vis[tmp.a][tmp.b])
    {
      q.push(tmp);
      vis[tmp.a][tmp.b] = true;
    }
    // pour
    tmp = t;
    str = t.op + "5";
    pot_pour(tmp, 1);
    tmp.op = str;
    if (!vis[tmp.a][tmp.b])
    {
      q.push(tmp);
      vis[tmp.a][tmp.b] = true;
    }
    tmp = t;
    str = t.op + "6";
    pot_pour(tmp, 2);
    tmp.op = str;
    if (!vis[tmp.a][tmp.b])
    {
      q.push(tmp);
      vis[tmp.a][tmp.b] = true;
    }
  }
  cout << "impossible" << '\n';
  return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  while (cin >> a >> b >> c)
  {
    bfs(a, b, c);
  }

  return 0;
}