#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, PII> PIIII;

int n, m;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  cin >> n >> m;
  vector<PIIII> a(m);
  for (auto &v : a)
  {
    int l, r, x, y;
    cin >> l >> r >> x >> y;
    v = make_pair(make_pair(l, r - l + 1 - y), make_pair(-r, x));
  }
  sort(all(a));
  int L = 1;
  bool flag = true;
  vector<PII> ans;
  for (int i = 0; i < m; i++)
  {
    int l = a[i].first.first, r = -a[i].second.first, x = a[i].second.second, y = r - l + 1 - a[i].first.second;
    if (r - L + 1 < y || r - l + 1 < y)
    {
      flag = false;
      break;
    }
    if (l > L)
      ans.emplace_back(make_pair(1, l - L));
    L = max(L, l);
    ans.emplace_back(make_pair(x, y));
    L += y;
  }
  if (n >= L)
    ans.emplace_back(make_pair(1, n - L + 1));
  if (flag)
  {
    for (PII x : ans)
      for (int i = 0; i < x.second; i++)
        cout << x.first << ' ';
    cout << '\n';
  }
  else
    cout << "qcjjddw\n";
  return 0;
}