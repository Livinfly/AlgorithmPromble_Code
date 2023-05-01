#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int n, k;
int f[N];

queue<int> q;
bool check(int x)
{
  if (x < 0 || x > int(1e5) || f[x] != -1)
    return false;
  return true;
}
void solve(int a, int t)
{
  if (check(a))
  {
    q.push(a);
    f[a] = f[t] + 1;
  }
}
int bfs()
{
  while (q.size())
    q.pop();
  q.push(n);
  f[n] = 0;
  while (q.size())
  {
    int t = q.front();
    q.pop();
    if (t == k)
      break;
    int a = t * 2;
    solve(a, t);
    a = t + 1;
    solve(a, t);
    a = t - 1;
    solve(a, t);
  }
  return f[k];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  while (cin >> n >> k)
  {
    memset(f, 0xff, sizeof f);
    cout << bfs() << endl;
  }
  return 0;
}