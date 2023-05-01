#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int N = 12;

int n, stx, sty, stz, edx, edy, edz;
int f[N][N][N];
int dzxy[6][3] = {
    {-1, 0, 0},
    {1, 0, 0},
    {0, -1, 0},
    {0, 1, 0},
    {0, 0, -1},
    {0, 0, 1},
};
char ch[N][N][N]; // slice row line
string str;

struct Node
{
  int z, x, y;
};
queue<Node> q;

int bfs()
{
  while (q.size())
    q.pop();
  memset(f, 0xff, sizeof f);
  q.push({stz, stx, sty});
  f[stz][stx][sty] = 0;
  while (q.size())
  {
    auto t = q.front();
    q.pop();
    if (t.z == edz && t.x == edx && t.y == edy)
      break;
    for (int i = 0; i < 6; i++)
    {
      int c = t.z + dzxy[i][0], a = t.x + dzxy[i][1], b = t.y + dzxy[i][2];
      if (c < 0 || c >= n || a < 0 || a >= n || b < 0 || b >= n)
        continue;
      // cout << a << ' ' << b << ' ' << c << '\n'
      //      << f[c][a][b] << ' ' << ch[c][a][b] << '\n';
      if (f[c][a][b] != -1 || ch[c][a][b] == 'X')
        continue;
      // cout << a << ' ' << b << ' ' << c << '\n';
      q.push({c, a, b});
      f[c][a][b] = f[t.z][t.x][t.y] + 1;
    }
  }
  return f[edz][edx][edy];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  while (cin >> str >> n)
  {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> ch[i][j];
    cin >> stx >> sty >> stz;
    cin >> edx >> edy >> edz;
    cin >> str;
    int t = bfs();
    if (t != -1)
      cout << n << ' ' << t << '\n';
    else
      cout << "NO ROUTE" << '\n';
  }
  return 0;
}