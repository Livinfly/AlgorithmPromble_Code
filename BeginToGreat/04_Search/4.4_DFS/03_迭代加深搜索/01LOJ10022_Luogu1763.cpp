#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100010;

struct Node
{
  int up, down;
} a;

int path[N], ans_path[N];
bool flag;

LL gcd(LL a, LL b)
{
  return b ? gcd(b, a % b) : a;
}
Node Node_sub(Node a, Node b) // a-b
{
  LL tx, ty, d;
  ty = (LL)a.down * b.down;
  tx = (LL)a.up * b.down - (LL)b.up * a.down;
  if (!tx)
    return (Node){0, 1};
  d = gcd(tx, ty);
  if (d)
    tx /= d, ty /= d;
  if (!d || ty > (int)1e7 || tx < 0)
    tx = -1;
  if (tx == 0)
    ty = 1;
  return (Node){(int)tx, (int)ty};
}
void dfs(int u, int id, Node remain, int depth)
{
  if (u == depth && remain.up == 0)
  {
    if (!flag || path[u - 1] < ans_path[u - 1])
    {
      memcpy(ans_path, path, sizeof path);
      flag = true;
    }
    return;
  }
  int l = max(id, remain.down / remain.up), r = min(remain.down * (depth - u) / remain.up, (int)1e7); // 强力剪枝 - 缩小范围
  for (int i = l; i <= r; i++)
  {
    Node t = Node_sub(remain, (Node){1, i});
    if (t.up == -1)
      continue;
    path[u] = i;
    dfs(u + 1, i + 1, t, depth);
    path[u] = 0;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  //   freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  cin >> a.up >> a.down;
  int depth = 1;
  while (true)
  {
    dfs(0, 2, a, depth);
    if (flag)
      break;
    depth++;
  }
  for (int i = 0; i < depth; i++)
    cout << ans_path[i] << ' ';
  cout << '\n';
  return 0;
}
