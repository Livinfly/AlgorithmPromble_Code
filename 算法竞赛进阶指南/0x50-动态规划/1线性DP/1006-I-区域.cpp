#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)

using namespace std;

typedef pair<int, int> PII;

const int N = 16;

int n, m, k;
int s[N][N], g[N][N], f[N][N*N][N][N][2][2]; // i, j, l, r, l_up?, r_up?
vector<PII> ans;
struct S{
    int i, j, l, r, z1, z2;
} pre[N][N*N][N][N][2][2];

inline void Schprint(S t)
{
  int i,j,l,r,z1,z2;
  i = t.i, j = t.j, l = t.l, r = t.r, z1 = t.z1, z2 = t.z2;
  while(j) //应当是看上一个的j的个数还有没有
  {
    for(int p = r; p >= l; p --)
      ans.push_back(mkp(i, p));
    t = pre[i][j][l][r][z1][z2];
    i = t.i, j = t.j, l = t.l, r = t.r, z1 = t.z1, z2 = t.z2;
  }
  reverse(ans.begin(), ans.end());
  for(int p = 0; p < ans.size(); p ++)
    cout << ans[p].fi << ' ' << ans[p].se << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i ++)
	  for(int j = 1; j <= m; j ++)
	  {
	    cin >> g[i][j];
	    s[i][j] = s[i][j-1] + g[i][j];
	  }
	memset(f, -0x3f, sizeof f);
	for(int i = 0; i <= n; i ++)
    for(int l = 1; l <= m; l ++)
      for(int r = l; r <= m; r ++)
        f[i][0][l][r][1][1] = 0;
	int res = 0;
	S A ={0};
	for(int i = 1; i <= n; i ++)
	  for(int j = 0; j <= k; j ++)
	    for(int l = 1; l <= m; l ++)
	      for(int r = l; r <= m; r ++)
	        if(r-l+1 <= j)
	        {
	          int cost = r-l+1, val = s[i][r] - s[i][l-1];
	          // lu, ru
	          int &t4 = f[i][j][l][r][1][1];
	          for(int l1 = l; l1 <= r; l1 ++) // m->r
              for(int r1 = l1; r1 <= r; r1 ++)
                if(r1 >= l1)
                  if(t4 < f[i-1][j-cost][l1][r1][1][1] + val)
                  {
                    t4 = f[i-1][j-cost][l1][r1][1][1] + val;
                    pre[i][j][l][r][1][1] = (S){i-1,j-cost,l1,r1,1,1};
                  }
  	         // lu, rd
  	         int &t3 = f[i][j][l][r][1][0];
  	         for(int l1 = l; l1 <= r; l1 ++) // m->r
	            for(int r1 = r; r1 <= m; r1 ++)
	              if(r1 >= l1)
	                for(int z2 = 0; z2 < 2; z2 ++)
                    if(t3 < f[i-1][j-cost][l1][r1][1][z2] + val)
                    {
                      t3 = f[i-1][j-cost][l1][r1][1][z2] + val;
                      pre[i][j][l][r][1][0] = (S){i-1,j-cost,l1,r1,1,z2};
                    }
            // ld, ru
  	        int &t2 = f[i][j][l][r][0][1];
  	        for(int l1 = 1; l1 <= l; l1 ++)
	            for(int r1 = l; r1 <= r; r1 ++) //l1->l
	              if(r1 >= l1)
  	              for(int z1 = 0; z1 < 2; z1 ++)
                    if(t2 < f[i-1][j-cost][l1][r1][z1][1] + val)
                    {
                      t2 = f[i-1][j-cost][l1][r1][z1][1] + val;
                      pre[i][j][l][r][0][1] = (S){i-1,j-cost,l1,r1,z1,1};
                    }
	          // ld, rd
	          int &t1 = f[i][j][l][r][0][0];
	          for(int l1 = 1; l1 <= l; l1 ++)
	            for(int r1 = r; r1 <= m; r1 ++)
	              if(r1 >= l1)
  	              for(int z1 = 0; z1 < 2; z1 ++)
  	                for(int z2 = 0; z2 < 2; z2 ++)
  	                   if(t1 < f[i-1][j-cost][l1][r1][z1][z2] + val)
  	                   {
  	                     t1 = f[i-1][j-cost][l1][r1][z1][z2] + val;
  	                     pre[i][j][l][r][0][0] = (S){i-1,j-cost,l1,r1,z1,z2};
  	                   }
  	        if(j == k)
  	        {
    	        for(int z1 = 0; z1 < 2; z1 ++)
          	    for(int z2 = 0; z2 < 2; z2 ++)
          	      if(res < f[i][j][l][r][z1][z2])
          	      {
        	          res = f[i][j][l][r][z1][z2];
        	          A = (S){i,j,l,r,z1,z2};
          	      }
  	        }
	        }
	cout << "Oil : " << res << endl;
	Schprint(A);
	return 0;
}
/*
https://www.acwing.com/activity/content/code/content/1673314/
*/