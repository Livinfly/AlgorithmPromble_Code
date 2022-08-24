#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e4 + 10;

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
      a[i] = i + 1;
    for (int i = n - 1; i >= 1; i -= 2)
      swap(a[i], a[i - 1]);
    for (auto x : a)
      cout << x << ' ';
    cout << endl;
  }
  return 0;
}