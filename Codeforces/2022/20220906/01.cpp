#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2010;

int n;
int a[N];

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
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int mx = a[n - 1] - a[0];
    for (int i = 0; i < n - 1; i++)
      mx = max(mx, a[i] - a[i + 1]);
    int t = a[1];
    for (int i = 2; i < n; i++)
      t = max(t, a[i]);
    mx = max(mx, t - a[0]);
    t = a[0];
    for (int i = 1; i < n - 1; i++)
      t = min(t, a[i]);
    mx = max(mx, a[n - 1] - t);
    cout << mx << '\n';
  }
  return 0;
}

/*
why??
*/