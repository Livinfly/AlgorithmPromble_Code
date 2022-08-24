#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

typedef long long LL;
struct Node
{
  char str[12];
  int pos, hx, step;
  LL path; // 0123 - dlru
  int is_ordered;
};
const int factory[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int ans_step;
LL ans;
LL power4[40]; // 35
char ans_path[40], dir[5] = "dlru";
int d[2][362890];
LL road[2][362890];
queue<Node> q;
void prev_calc()
{
  LL t = 1; // LL!
  for (int i = 0; i < 35; i++, t *= 4)
    power4[i] = t;
}
void init()
{
  while (q.size())
    q.pop();
  memset(d, -1, sizeof d);
  memset(road, 0, sizeof road);
  ans_step = ans = -1;
  return;
}
int cantor(char ch[], int n = 9)
{
  int Idx = 0, cnt;
  for (int i = 0; i < n; i++)
  {
    cnt = 0;
    for (int j = i + 1; j < n; j++)
      if (ch[i] > ch[j])
        cnt++;
    Idx += cnt * factory[n - i - 1];
  }
  return Idx;
}
Node mk_Node(char ch[], int pos, int step, LL path, int is_ordered)
{
  if (pos == -1)
  {
    for (int i = 0; i < 9; i++)
      if (ch[i] == 'X')
      {
        pos = i;
        break;
      }
  }

  Node t = (Node){{}, pos, cantor(ch), step, path, is_ordered};
  memcpy(t.str, ch, 9);
  return t;
}
void trans_path();
void check_nstatus(Node t, Node &nt, int type)
{
  if (d[nt.is_ordered][nt.hx] == -1) // 未访问过
  {
    d[nt.is_ordered][nt.hx] = t.step + 1;
    if (nt.is_ordered)
      nt.path = nt.path * 4 + type;
    else
      nt.path = (3 - type) * power4[nt.step - 1] + nt.path;
    road[nt.is_ordered][nt.hx] = nt.path;
    if (ans == -1 || nt.step * 2 <= ans_step)
      q.push(nt);
  }
  else // 访问过 - 更新字典序
  {
    if (t.step + 1 > d[nt.is_ordered][nt.hx])
      return;
    else
      d[nt.is_ordered][nt.hx] = t.step + 1;
    if (nt.is_ordered)
      nt.path = nt.path * 4 + type;
    else
      nt.path = (3 - type) * power4[nt.step - 1] + nt.path;
    if (road[nt.is_ordered][nt.hx] > nt.path)
    {
      road[nt.is_ordered][nt.hx] = nt.path;
      if (ans == -1 || nt.step * 2 <= ans_step)
        q.push(nt);
    }
  }
  // 相遇
  if (d[nt.is_ordered ^ 1][nt.hx] != -1 && (ans == -1 || ans_step == nt.step + d[nt.is_ordered ^ 1][nt.hx]))
  {
    ans_step = nt.step + d[nt.is_ordered ^ 1][nt.hx];
    LL tans;
    if (nt.is_ordered)
      tans = nt.path * power4[d[0][nt.hx]] + road[0][nt.hx];
    else
      tans = road[1][nt.hx] * power4[d[0][nt.hx]] + nt.path;
    if (ans == -1 || tans < ans)
      ans = tans;
  }
}
void update_nstatus(Node t, int type)
{
  // dlru
  Node nt = t;
  switch (type)
  {
  case 0:
    if (nt.pos < 6)
    {
      swap(nt.str[nt.pos], nt.str[nt.pos + 3]);
      nt.pos += 3;
      nt.step++;
      nt.hx = cantor(nt.str);
      check_nstatus(t, nt, type);
    }
    break;
  case 1:
    if (nt.pos % 3)
    {
      swap(nt.str[nt.pos], nt.str[nt.pos - 1]);
      nt.pos--;
      nt.step++;
      nt.hx = cantor(nt.str);
      check_nstatus(t, nt, type);
    }
    break;
  case 2:
    if (nt.pos % 3 != 2)
    {
      swap(nt.str[nt.pos], nt.str[nt.pos + 1]);
      nt.pos++;
      nt.step++;
      nt.hx = cantor(nt.str);
      check_nstatus(t, nt, type);
    }
    break;
  case 3:
    if (nt.pos >= 3)
    {
      swap(nt.str[nt.pos], nt.str[nt.pos - 3]);
      nt.pos -= 3;
      nt.step++;
      nt.hx = cantor(nt.str);
      check_nstatus(t, nt, type);
    }
    break;
  }
}
void dbfs(char A[], char Z[])
{
  Node a = mk_Node(A, -1, 0, 0, 1), b = mk_Node(Z, -1, 0, 0, 0);
  q.push(a), q.push(b);
  d[1][a.hx] = d[0][b.hx] = 0;
  road[1][a.hx] = road[0][b.hx] = 0;
  if (a.hx == b.hx)
  {
    ans_step = 0;
    ans = 0;
    return;
  }

  while (q.size())
  {
    Node t = q.front();
    q.pop();
    for (int i = 0; i < 4; i++)
      update_nstatus(t, i);
  }
}
void trans_path()
{
  for (int i = ans_step - 1; i >= 0; i--)
    ans_path[ans_step - 1 - i] = dir[(ans / power4[i]) % 4LL];
  ans_path[ans_step] = '\0'; // 重置
}

main()
{
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  prev_calc();
  int T;
  scanf("%d", &T);
  for (int C = 1; C <= T; C++)
  {
    init();
    char A[12], Z[12];
    scanf("%s\n%s", A, Z);
    dbfs(A, Z);
    trans_path(); // 数字路径转化为字符路径
    printf("Case %d: %d\n%s\n", C, ans_step, ans_path);
  }
  return 0;
}
