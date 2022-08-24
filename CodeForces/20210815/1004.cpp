#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

int n, m1, m2, cnt;
int fa[N][2];
vector<PII> ans;

inline int get_fa(int x, int type)
{
  if(x == fa[x][type]) return x;
  return fa[x][type] = get_fa(fa[x][type], type);
}

int main()
{
  ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m1 >> m2;
	for(int i = 1; i <= n; i ++)
	  for(int j = 0; j < 2; j ++)
	    fa[i][j] = i;
  while(m1 --)
  {
    int a, b;
    cin >> a >> b;
    int x = get_fa(a, 0), y = get_fa(b, 0);
    fa[x][0] = y;
  }
  while(m2 --)
  {
    int a, b;
    cin >> a >> b;
    int x = get_fa(a, 1), y = get_fa(b, 1);
    fa[x][1] = y;
  }
  for(int i = 1; i <= n; i ++)
    for(int j = i+1; j <= n; j ++)
    {
      int a1 = get_fa(i, 0), b1 = get_fa(j, 0);
      int a2 = get_fa(i, 1), b2 = get_fa(j, 1);
      if(a1 == b1 || a2 == b2) continue;
      fa[a1][0] = b1, fa[a2][1] = b2;
      ans.push_back(mkp(i, j));
      cnt ++;
    }
  cout << cnt << endl;
  for(int i = 0; i < ans.size(); i ++)
    cout << ans[i].fi << ' ' << ans[i].se << endl;
  return 0;
}
