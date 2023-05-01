#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int P = 1e9 + 7;

LL n, k, m;
LL res;
LL qpm(LL a, LL b)
{
	LL ans = 1;
	while(b)
	{
		if(b & 1) ans = ans * a % P;
		a = a * a % P;
		b >>= 1;
	}
	return ans;
}


int main()
{
	freopen("wsxtql.in", "r", stdin);
	freopen("wsxtql.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &k, &m);
	LL sum = qpm(n, k);
	if(m == 0)
	{
		printf("lld\n", sum);
	}
	else
	{
		LL t2;
		t2 = (n - k) / k;
		if(m <= t2 / 2) res = sum - m * t2 * k;
		printf("%lld\n", res);
	}
	
	
	return 0;
}
