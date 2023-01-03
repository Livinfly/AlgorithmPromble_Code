#pragma GCC optimize(2)

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

LL n, m;
LL a[N];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  cin >> n >> m;
  LL res = n * (n + 1) / 2;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i < n; i++)
    res += (LL)(a[i] != a[i + 1]) * i * (n - i);
  while (m--)
  {
    LL id, c;
    cin >> id >> c;
    res -= (a[id] != a[id - 1]) * (id - 1) * (n - id + 1);
    res -= (a[id] != a[id + 1]) * id * (n - id);
    a[id] = c;
    res += (a[id] != a[id - 1]) * (id - 1) * (n - id + 1);
    res += (a[id] != a[id + 1]) * id * (n - id);
    cout << res << '\n';
  }
  return 0;
}