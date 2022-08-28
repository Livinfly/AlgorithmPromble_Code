#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 200;

bool vis[N];

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
    memset(vis, 0, sizeof vis);
    int cnt = 0;
    char ch[3];
    cin >> ch;
    for (int i = 0; i < 2; i++)
      if (!vis[ch[i]])
      {
        vis[ch[i]] = true;
        cnt++;
      }
    cin >> ch;
    for (int i = 0; i < 2; i++)
      if (!vis[ch[i]])
      {
        vis[ch[i]] = true;
        cnt++;
      }
    cout << cnt - 1 << '\n';
  }
  return 0;
}