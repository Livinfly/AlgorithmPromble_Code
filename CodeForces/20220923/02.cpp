#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

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
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= i; j++)
        cout << (!j || j == i) << " \n"[j == i];
  }
  return 0;
}