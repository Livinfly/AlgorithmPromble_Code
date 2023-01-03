#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int n;
int fa[N], siz[N];
int stk[N], top;

int lowbit(int x)
{
  return x & -x;
}
int get_fa(int x)
{
  if (fa[x] == x)
    return x;
  return fa[x] = get_fa(fa[x]);
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
  {
    cin >> n;
    for (int i = 1; i <= n * 2; i++)
      fa[i] = i, siz[i] = 1;
    string s;
    cin >> s;
    int res = 0;
    top = 0;
    int last = -3;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == ')' && top && s[stk[top--]] == '(')
      {
        int fx = get_fa(i + 1), fy = get_fa(stk[top + 1] + 1);
        if (fx != fy)
        {
          fa[fy] = fx;
          siz[fx] += siz[fy];
        }
        if (last + 1 == stk[top + 1])
        {
          fy = get_fa(last + 1);
          if (fx != fy)
          {
            fa[fy] = fx;
            siz[fx] += siz[fy];
          }
        }
        if (!top)
          last = i;
      }
      else if (s[i] == '(')
        stk[++top] = i;
      else
        last = -3;
    }
    for (int i = 1; i <= n * 2; i++)
    {
      // cout << i << ' ' << fa[i] << ' ' << siz[i] << '\n';
      if (fa[i] == i && siz[i] > 1)
        res++;
    }

    cout << res << '\n';
  }
  return 0;
}