#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 210, M = 25;

int n, m;
int p[N], d[N], f[M][810];
bool choose[N][M][810];

inline void SchPrint(int i, int j, int k)
{
  if(!j) return;
  if(choose[i][j][k+400])
  {
    SchPrint(i-1, j-1, k-(d[i]-p[i]));
    printf(" %d", i);
  }
  else
  {
    SchPrint(i-1, j, k);
  }
}

int main()
{
	int Case = 0;
	while(scanf("%d%d", &n, &m) == 2, n || m)
	{
	  memset(f, 0xcf, sizeof f);
	  f[0][0+400] = 0;
	  for(int i = 1; i <= n; i ++) scanf("%d %d", &p[i], &d[i]);
	  for(int i = 1; i <= n; i ++)
	    for(int j = m; j; j --)
	      for(int k = -20*m; k <= 20*m; k ++)
	      {
	        choose[i][j][k+400] = false;
	        if(k-(d[i]-p[i]) < -20*m || k-(d[i]-p[i]) > 20*m) continue; // (防越界!)
	        if(f[j][k+400] < f[j-1][k-(d[i]-p[i])+400]+d[i]+p[i])
	        {
	          f[j][k+400] = f[j-1][k-(d[i]-p[i])+400]+d[i]+p[i];
	          choose[i][j][k+400] = true;
	        }
	      }
	  
	  int abs_delta = 1<<30, raw_delta, sum = 0, p, d;
	  for(int k = -20*m; k <= 20*m; k ++)
	    if(f[m][k+400]>=0 && abs(k)<abs_delta || abs(k)==abs_delta && f[m][k+400]>sum)
	      abs_delta = abs(k), raw_delta = k, sum = f[m][k+400];
	  // sum = p + d, raw_delta = d - p
	  p = sum-raw_delta>>1, d = sum+raw_delta>>1;
	  printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n", ++ Case, p, d);
    SchPrint(n, m, raw_delta);
    puts("\n");
	}
	return 0;
}
/*
https://www.acwing.com/activity/content/code/content/1715214/
*/