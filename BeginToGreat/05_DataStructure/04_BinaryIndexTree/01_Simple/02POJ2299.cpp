#pragma GCC optimize(2)

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 5e5 + 10;

int n;
int tr[N];

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
  while (cin >> n, n)
  {
    memset(tr, 0, sizeof tr);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector<int> num = a;
    sort(all(num));
    LL res = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      int id = lower_bound(num.begin(), num.end(), a[i]) - num.begin() + 1;
      res += sum(id);
      add(id, 1);
    }
    cout << res << '\n';
  }
  return 0;
}