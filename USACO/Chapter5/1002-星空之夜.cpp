#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second

using namespace std;

typedef pair<int, int> PII;

const int N = 110;
const double eps = 1e-6;

int n, m, id;
double hx[30];
char g[N][N];
vector<PII> p;

inline void dfs(int x, int y)
{
  g[x][y] = '0'; // forget!!!
  p.push_back(mkp(x, y));
  for(int i = -1; i <= 1; i ++)
    for(int j = -1; j <= 1; j ++)
    {
      if(!i && !j) continue;
      int a = x+i, b = y+j;
      if(a < 0 || a >= n || b < 0 || b >= m) continue;
      if(g[a][b] == '1') dfs(a, b);
    }
}
inline double get_dist(PII a, PII b)
{
  int dx = a.fi - b.fi, dy = a.se - b.se;
  return sqrt(dx*dx+dy*dy);
}
inline double H(vector<PII> p)
{
  double res = 0;
  for(int i = 0; i < p.size(); i ++)
    for(int j = i+1; j < p.size(); j ++)
      res += get_dist(p[i], p[j]);
  return res;
}
inline char get_id(double val)
{
  for(int i = 1; i <= id; i ++)
    if(fabs(hx[i]-val) < eps) return (char)(i-1+'a'); // id -> i TnT
  hx[++ id] = val;
  return (char)(id-1+'a');
}

int main()
{
	ios::sync_with_stdio(0);
  cin.tie(0);
	cin >> m >> n;
  for(int i = 0; i < n; i ++) cin >> g[i];
	for(int i = 0; i < n; i ++)
    for(int j = 0; j < m; j ++)
      if(g[i][j] == '1')
      {
        p.clear();
        dfs(i, j);
        char ch = get_id(H(p));
        for(int i = 0; i < p.size(); i ++)
          g[p[i].fi][p[i].se] = ch;
      }
	for(int i = 0; i < n; i ++)
    cout << g[i] << endl;
	return 0;
}