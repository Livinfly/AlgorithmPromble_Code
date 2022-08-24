#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  cin >> T; // scanf("%d", &T);
  while (T--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a.begin(), a.end());
    cout << a[n - 1] + a[n - 2] - a[0] - a[1] << '\n';
  }
  return 0;
}