#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 25;

int n, res;
int f[N];
bool row[N], lu[N], ru[N];

void dfs(int id, int n)
{
  if (id == n)
  {
    res++;
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if (row[i] || lu[i - id + n] || ru[i + id])
      continue;
    row[i] = lu[i - id + n] = ru[i + id] = true;
    dfs(id + 1, n);
    row[i] = lu[i - id + n] = ru[i + id] = false;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  for (int i = 1; i <= 10; i++)
  {
    res = 0;
    dfs(0, i);
    f[i] = res;
  }

  while (cin >> n, n)
    cout << f[n] << endl;
  return 0;
}