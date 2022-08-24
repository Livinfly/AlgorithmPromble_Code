#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10, P = 1e9 + 7;

LL n, m, res;
LL inv[N];

void get_inv()
{
	inv[1] = 1;
	for(int i = 2; i < N; i ++)
		inv[i] = (P - P / i) * inv[P % i] % P;
}
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
	get_inv();
//	for(int i = 1; i < 10; i ++)
//		printf("%lld ", inv[i]);
//	cout << endl;
	while(scanf("%lld%lld", &n, &m) == 2)
	{
		res = m % P;
		for(int i = 2; i <= n; i ++)
		{
			res = (res - i * ((1 - qpm(i, m)) % P) % P * inv[i - 1] % P) % P;
//			res = (res + i * ((1 - qpm(i, m)) % P) % P * qpm(1 - i, P - 2) % P) % P;
		}
		cout << (res + P) % P << endl;
	}
	
	return 0;
}
