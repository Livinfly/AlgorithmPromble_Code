#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

LL n;
LL res;


int main()
{
	freopen("wsxkp.in", "r", stdin);
	freopen("wsxkp.out", "w", stdout);
	scanf("%lld", &n);
	n --;
	
	while(n > 0) res ++, n /= 3;
	
	printf("%lld\n", max(res * 2 - 1, 0LL));
	
	return 0;
}
