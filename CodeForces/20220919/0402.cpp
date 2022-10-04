#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 5010;

LL n, x, y;
string a, b;
LL f[N][N];
vector<int> pos;

LL get(LL l, LL r)
{
  if (l + 1 == r)
    return min(x, y * 2);
  else
    return min(y, x * (r - l));
}
LL dfs(int l, int r)
{
  if (l >= r)
    return 0;
  if (f[l][r] != -1)
    return f[l][r];
  LL res = min({dfs(l, r - 2) + get(pos[r - 1], pos[r]),
                dfs(l + 1, r - 1) + get(pos[l], pos[r]),
                dfs(l + 2, r) + get(pos[l], pos[l + 1])});
  return f[l][r] = res;
}
void solve()
{
  cin >> n >> x >> y;
  cin >> a >> b;
  a = " " + a, b = " " + b;
  pos.clear();
  for (int i = 1; i <= n; i++)
    if (a[i] != b[i])
      pos.emplace_back(i);
  if (pos.size() & 1)
  {
    cout << -1 << '\n';
    return;
  }
  if (pos.size() == 2)
  {
    cout << get(pos[0], pos[1]) << '\n';
    return;
  }
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= n + 1; j++)
      f[i][j] = -1;
  // 两个相邻 但分别和别的匹配小的情况
  if (y <= x)
    cout << pos.size() / 2 * y << '\n';
  else
    cout << dfs(0, pos.size() - 1) << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  cin >> T; // scanf("%d", &T);
  while (T--)
    solve();
  return 0;
}