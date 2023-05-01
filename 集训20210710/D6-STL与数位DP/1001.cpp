#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e4 + 10;

int n, m;
int a[N * 2];

int main()
{
//	freopen("data1.in", "r", stdin);
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(int i = 1; i <= n + m; i ++) scanf("%d", &a[i]);
		sort(a + 1, a + n + m + 1);
		n = unique(a + 1, a + n + m + 1) - (a + 1);
		printf("%d", a[1]); // PE
		for(int i = 2; i <= n; i ++)
			printf(" %d", a[i]);
		puts("");
	}
	
	return 0;
}
