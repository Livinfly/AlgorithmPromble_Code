#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

struct Node
{
  int id;
  int l, r;
  bool operator<(const Node &o) const
  {
    return l < o.l || l == o.l && r > o.r;
  }
};

string s[15];
Node seg[1010], ans[1010]; // MAX 1000

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  cin >> T;
  while (T--)
  {
    string str;
    cin >> str;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> s[i];
    int idx = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j + s[i].size() - 1 < str.size(); j++)
        if (str.substr(j, s[i].size()) == s[i])
          seg[idx++] = (Node){i, j, j + int(s[i].size()) - 1};
    sort(seg, seg + idx);
    // for (int i = 0; i < idx; i++)
    //   cout << seg[i].id << ' ' << seg[i].l << ' ' << seg[i].r << endl;
    int ans_idx = 0, L_R = 0, max_R = -1;
    bool flag = true;
    for (int i = 0; i < idx; i++)
    {
      if (seg[i].l <= L_R)
      {
        if (max_R < seg[i].r)
        {
          max_R = seg[i].r;
          ans[ans_idx] = seg[i];
        }
      }
      else if (seg[i].l <= max_R + 1)
      {
        L_R = max_R + 1;
        ans_idx++;
        i--;
      }
      else
      {
        flag = false;
        break;
      }
      if (max_R == str.size() - 1)
        break;
    }
    if (max_R != str.size() - 1 && seg[idx - 1].l <= L_R)
    {
      if (max_R < seg[idx - 1].r)
      {
        max_R = seg[idx - 1].r;
        ans[ans_idx] = seg[idx - 1];
      }
    }

    if (!flag || max_R != str.size() - 1)
    {
      // cout << -1 << ' ' << flag << ' ' << L_R << ' ' << max_R << ' ' << ans_idx + 1 << endl;
      cout << -1 << endl;
      continue;
    }
    cout << ans_idx + 1 << endl;
    for (int i = 0; i <= ans_idx; i++)
      cout << ans[i].id + 1 << ' ' << ans[i].l + 1 << endl;
  }
  return 0;
}