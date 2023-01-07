#pragma GCC optimize(2)

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 510;

int dxy[4][2] = {
    // UDLR
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};
char ch[5] = "UDLR";
char g[N][N];
bool vis[N][N];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++)
    cin >> g[i];
  queue<PII> q;
  q.push({0, 0});
  while (q.size()) // +1
  {
    auto t = q.front();
    q.pop();
    vis[t.first][t.second] = true;
    int op;
    for (op = 0; op < 4; op++)
      if (ch[op] == g[t.first][t.second])
        break;
    int a = t.first + dxy[op][0], b = t.second + dxy[op][1];
    if (a < 0 || b < 0 || a >= h || b >= w)
    {
      cout << t.first + 1 << ' ' << t.second + 1 << '\n';
      return 0;
    }
    if (vis[a][b])
    {
      cout << -1 << endl;
      return 0;
    }
    q.push({a, b});
  }

  return 0;
}