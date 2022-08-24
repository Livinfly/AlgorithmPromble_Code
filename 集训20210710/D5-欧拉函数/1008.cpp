#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

LL n, m;
LL phi(LL x)
{
	LL res = x;
	for(int i = 2; i * i <= x; i ++)
	{
		if(x % i == 0) // forget
		{
			res = res / i * (i - 1);
			while(x % i == 0) x /= i; 
		}
	}
	if(x > 1) res = res / x * (x - 1);
	return res;
}

int main()
{
	int T; cin >> T;
	while(T --)
	{
		cin >> n >> m;
		LL res = 0;
		for(int i = 1; i * i <= n; i ++)
		{
			if(n % i == 0)
			{
				if(i >= m) res += phi(n / i);
				if(i * i != n && n / i >= m) res += phi(i); // i * i != n 防止重复计算 
			}
		}
		cout << res << endl;
	}
	
	return 0;
}
/*
枚举 d = g(x, n);
一定存在a * d = x, b * d = n
a = x / d, b = n / d

枚举b求a gcd(a, b) == 1 

*/
