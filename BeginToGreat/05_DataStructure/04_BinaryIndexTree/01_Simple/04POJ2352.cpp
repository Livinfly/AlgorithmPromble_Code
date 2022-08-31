#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1.5e4 + 5, M = 3.2e4 + 5;

int n;
int ans[N];
PII p[N];
int tr[M];

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

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    PII &x = p[i];
    cin >> x.first >> x.second;
  }
  sort(p, p + n);
  for (int i = 0; i < n; i++)
  {
    int t = p[i].second + 1;
    ans[sum(t)]++;
    add(t, 1);
  }
  for (int i = 0; i < n; i++)
    cout << ans[i] << '\n';
  return 0;
}
// 不知道为什么是wa的。