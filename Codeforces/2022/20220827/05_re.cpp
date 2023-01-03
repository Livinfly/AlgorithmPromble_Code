#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 20;

int ne[N], ch[N][26];
char str[N];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  cin >> str + 1;
  int slen = strlen(str + 1);
  ne[1] = 0, ch[0][str[1] - 'a'] = 1;
  for (int i = 2; i <= slen; i++)
  {
    ne[i] = ch[ne[i - 1]][str[i] - 'a'];
    ch[i - 1][str[i] - 'a'] = i;
    for (int j = 'a'; j <= 'z'; j++)
    {
      if (j == str[i])
        continue;
      ch[i - 1][j - 'a'] = ch[ne[i - 1]][j - 'a'];
    }
  }
  int q;
  cin >> q;
  while (q--)
  {
    cin >> str + slen + 1;
    int tlen = strlen(str + slen + 1);
    for (int i = slen + 1; i <= slen + tlen; i++)
    {
      ne[i] = ch[ne[i - 1]][str[i] - 'a'];
      ch[i - 1][str[i] - 'a'] = i;
      for (int j = 'a'; j <= 'z'; j++)
      {
        if (j == str[i])
          continue;
        ch[i - 1][j - 'a'] = ch[ne[i - 1]][j - 'a'];
      }
    }
    for (int i = slen + 1, j = slen - 1; i <= slen + tlen; i++)
      cout << ne[i] << " \n"[i == slen + tlen];
  }
  return 0;
}
/*
  kmp优化
*/