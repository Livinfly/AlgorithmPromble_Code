#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

LL a, b;

LL ex_gcd(LL a, LL b, LL &x, LL &y)
{
	if(!b)
	{
		x = 1, y = 0;
		return a;
	}
	int d = ex_gcd(b, a % b, x, y);
	LL t = x;
	x = y, y = t - a / b * y;
	return d;
}


int main()
{
	while(scanf("%lld%lld", &a, &b) == 2)
	{
		LL x, y;
		LL d = ex_gcd(a, b, x, y);
		if(d != 1) puts("sorry");
		else 
		{
			x = (x % b + b) % b;
			y = (1 - x * a) / b;
			cout << x << ' ' << y << endl; // 非负整数 
		}
	}
	return 0;
}
