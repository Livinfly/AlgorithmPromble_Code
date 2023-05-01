#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 24;

int h, w;
int dxy[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};
char g[N][N];
PII pos;

int bfs()
{
  int res = 0;
  queue<PII> q;
  q.push(pos);
  g[pos.x][pos.y] = '#';
  while (q.size())
  {
    auto t = q.front();
    q.pop();
    res++;
    for (int i = 0; i < 4; i++)
    {
      int a = t.x + dxy[i][0], b = t.y + dxy[i][1];
      if (a < 0 || a >= h || b < 0 || b >= w || g[a][b] == '#')
        continue;
      q.push({a, b});
      g[a][b] = '#';
    }
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  while (cin >> w >> h, h || w)
  {
    memset(g, 0, sizeof g);
    for (int i = 0; i < h; i++)
      cin >> g[i];
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        if (g[i][j] == '@')
          pos.x = i, pos.y = j;
    cout << bfs() << endl;
  }
  return 0;
}