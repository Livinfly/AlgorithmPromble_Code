#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 35;

int idx, h[N], ne[N], ver[N];
bool st[N];

void add(int a, int b)
{
  ver[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool dfs(int u, int aim)
{
  st[u] = true;
  for (int i = h[u]; ~i; i = ne[i])
  {
    int v = ver[i];
    if (st[v])
      continue;
    if (v == aim)
    {
      st[u] = false;
      return true;
    }
    if (dfs(v, aim))
    {
      st[u] = false;
      return true;
    }
  }
  st[u] = false;
  return false;
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
    idx = 0;
    memset(h, -1, sizeof h);
    int n;
    string s;
    cin >> n >> s;
    set<char> used;
    map<char, char> mp;
    for (auto x : s)
    {
      if (mp.find(x) == mp.end())
      {
        for (int i = 'a'; i <= 'z'; i++)
        {
          if ((char)i == x)
            continue;
          if (used.find((char)i) == used.end() && (!dfs(i - 'a', x - 'a') || used.size() == 25))
          {
            mp[x] = (char)i;
            used.insert((char)i);
            add(x - 'a', i - 'a');
            break;
          }
        }
      }
    }
    for (auto &x : s)
      x = mp[x];
    cout << s << '\n';
  }
  return 0;
}