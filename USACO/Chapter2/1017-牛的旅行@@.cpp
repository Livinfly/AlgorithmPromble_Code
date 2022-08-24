#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 155, INF = 1e18;

int n;
double d[N][N], dmax[N];
char g[N][N];
PII p[N];

inline double get_dist(PII a, PII b)
{
    int dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> p[i].x >> p[i].y;
	for(int i = 0; i < n; i ++) cin >> g[i];
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			if(g[i][j] == '1') d[i][j] = get_dist(p[i], p[j]);
			else if(i == j) d[i][j] = 0;
			else d[i][j] = INF;
	for(int k = 0; k < n; k ++)
    	for(int i = 0; i < n; i ++)
    		for(int j = 0; j < n; j ++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			if(d[i][j] != INF) dmax[i] = max(dmax[i], d[i][j]);
	
	double ans1, ans2;
	ans1 = 0, ans2 = INF;
	for(int i = 0; i < n; i ++) ans1 = max(ans1, dmax[i]);
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			if(d[i][j] == INF) 
			    ans2 = min(ans2, dmax[i] + dmax[j] + get_dist(p[i], p[j]));
	
	printf("%.6lf\n", max(ans1, ans2));
	
	return 0;
}
