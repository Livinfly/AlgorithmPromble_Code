#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1250, INF = 0x3f3f3f3f;

int cnt;
int f[10010], primes[N];
bool vis[10010];
queue<int> q;

bool is_prime(int x)
{
  if (x < 2)
    return false;
  if (x == 2)
    return true;
  for (int i = 2; i <= x / i; i++)
    if (x % i == 0)
      return false;
  return true;
}
void prev_calc()
{
  for (int i = 2; i <= 9999; i++)
    if (is_prime(i))
    {
      primes[cnt++] = i;
      vis[i] = true;
    }
  // cout << cnt << '\n';
}
int bfs(int st, int ed)
{
  memset(f, 0x3f, sizeof f);
  while (q.size())
    q.pop();
  q.push(st);
  f[st] = 0;
  while (q.size())
  {
    int t = q.front();
    q.pop();
    for (int i = 0; i < 10; i++)
    {
      int a[4];
      a[0] = t / 10 * 10 + i, a[1] = t / 100 * 100 + i * 10 + t % 10;
      a[2] = t / 1000 * 1000 + i * 100 + t % 100, a[3] = i * 1000 + t % 1000;
      for (int j = 0; j < 4; j++)
        if (a[j] >= 1000 && vis[a[j]] && f[a[j]] == INF)
        {
          q.push(a[j]);
          f[a[j]] = f[t] + 1;
        }
    }
  }
  return f[ed];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  prev_calc();
  int T;
  cin >> T;
  while (T--)
  {
    int st, ed;
    cin >> st >> ed;
    cout << bfs(st, ed) << '\n';
  }
  return 0;
}