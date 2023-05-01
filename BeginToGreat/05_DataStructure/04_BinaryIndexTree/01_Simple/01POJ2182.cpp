#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 8010;

int n;
int tr[N], pre[N];

int lowbit(int x)
{
  return x & -x;
}
void add(int x, int c)
{
  for (; x <= n; x += lowbit(x))
    tr[x] += c;
}
int sum(int x)
{
  int res = 0;
  for (; x; x -= lowbit(x))
    res += tr[x];
  return res;
}
int get_pos(int x)
{
  int l = 1, r = n;
  while (l < r)
  {
    int mid = l + r >> 1;
    if (sum(mid) < x)
      l = mid + 1;
    else
      r = mid;
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  cin >> n;
  for (int i = 2; i <= n; i++)
    cin >> pre[i];
  for (int i = 1; i <= n; i++)
    tr[i] = lowbit(i);
  vector<int> res;
  for (int i = n; i >= 2; i--)
  {
    int t = get_pos(pre[i] + 1);
    add(t, -1);
    res.push_back(t);
  }
  res.push_back(get_pos(1));
  for (int i = n - 1; i >= 0; i--)
    cout << res[i] << '\n';
  return 0;
}