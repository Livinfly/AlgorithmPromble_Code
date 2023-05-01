#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

typedef long long LL;

int n;
queue<LL> q;

LL bfs()
{
  if (n == 1)
    return 1;
  while (q.size())
    q.pop();
  q.push(1);
  while (q.size())
  {
    LL t = q.front();
    q.pop();
    t *= 10;
    if (t % n == 0)
      return t;
    q.push(t);
    t++;
    if (t % n == 0)
      return t;
    q.push(t);
  }
  return -1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  while (cin >> n, n)
    cout << bfs() << '\n';
  return 0;
}
// string TLE我不理解