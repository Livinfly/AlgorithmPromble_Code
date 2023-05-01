#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = N << 1;

int idx, h[N], ne[M], ver[M], e[M];
int n, m;
int maxn, cnt, tmp;

void add(int a, int b, int c)
{
	ver[idx] = b, e[idx] = c, ne[idx] = h[a], h[a] = idx;
}



int main()
{
	memset(h, -1, sizeof h);
	scanf("%d%d", &n, &m);
	while(m --)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c), add(b, a, c);
	}
	
	
	return 0;
}
