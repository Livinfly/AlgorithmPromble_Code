#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 110;
const double eps = 1e-6;

int L, n, power_s, power_time;
int rb_v, tor_v1, tor_v2;
int p[N];
double r_time;
double f[N], d_time[N][N];

void init()
{
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	
	for(int i = 0; i <= n; i ++)
		 for(int j = i + 1; j <= n; j ++)
		{
			int dist = p[j] - p[i];
			if(dist <= power_s) 
				d_time[i][j] = 1.0 * dist / tor_v1;
			else 
				d_time[i][j] = 1.0 * power_s / tor_v1 + 1.0 * (dist - power_s) / tor_v2;
		}
} 

int main()
{
	while(scanf("%d", &L) == 1)
	{
		scanf("%d%d%d", &n, &power_s, &power_time);
		scanf("%d%d%d", &rb_v, &tor_v1, &tor_v2);
		for(int i = 1; i <= n; i ++) scanf("%d", &p[i]);
		p[0] = 0, p[++ n] = L;
		r_time = 1.0 * L / rb_v;
		
		init();
		
		for(int i = 1; i <= n; i ++)
		{
			f[i] = d_time[0][i];
			for(int j = 1; j < i; j ++)
				f[i] = min(f[i], f[j] + d_time[j][i] + 1.0 * power_time);
		}
		
		if(f[n] + eps < r_time) puts("What a pity rabbit!");
		else puts("Good job,rabbit!");
	}
	
	
	return 0;
}
