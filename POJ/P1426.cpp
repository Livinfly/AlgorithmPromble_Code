#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef unsigned long long ULL;

int n;
bool ok;

void dfs(ULL x, int len)
{
	if(ok || len == 19) return;
	if(x % n == 0) 
	{
		ok = true;
		printf("%lld\n", x);
		return;
	}
	dfs(x * 10, len + 1);
	dfs(x * 10 + 1, len + 1);
}

int main()
{
    while(scanf("%d", &n) == 1, n)
    {
    	ok = false;
    	dfs(1ULL, 0);
	}
    
    return 0;
}
