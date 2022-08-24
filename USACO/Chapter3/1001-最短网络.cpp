#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110;

int n;
int g[N][N], dist[N]; // dist - gather i cost
bool st[N];

int prim()
{
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	dist[1] = 0;
	for(int i = 0; i < n - 1; i ++)
	{
		int t = -1;
		for(int j = 1; j <= n; j ++)
			if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
		st[t] = true;
		for(int j = 1; j <= n; j ++)
			if(!st[j]) dist[j] = min(dist[j], g[t][j]);
	}
	
	int res = 0;
	for(int i = 1; i <= n; i ++) res += dist[i];
	return res;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++) 
		for(int j = 1; j <= n; j ++)
			cin >> g[i][j];
	cout << prim() << endl;
	return 0;
}
