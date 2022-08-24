#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n;
LL r[N], m[N];

LL mod(LL a, LL b)
{
  return (a%b+b)%b;
}
LL qmul(LL a, LL b, LL P)
{
	LL ans = 0;
	while(b)
	{
		if(b & 1) ans = (ans + a) % P;
		a = a * 2 % P;
		b >>= 1;
	}
	return ans;
}
LL ex_gcd(LL a, LL b, LL &x, LL &y)
{
	if(!b)
	{
		x = 1, y = 0;
		return a;
	}
	LL d = ex_gcd(b, a % b, x, y);
	LL t = x;
	x = y, y = t - a / b * y;
	return d;
}
LL ex_crt()
{
	LL A, B, C, d, x, y, R, M; // R - 余数，答案, M - lcm(m1 ... mn)
	M = m[1], R = r[1];
	for(int i = 2; i <= n; i ++)
	{
		A = M, B = m[i], C = (r[i] - R % B + B) % B; // 防溢出
		d = ex_gcd(A, B, x, y); // 求出 == d时的x
		if(C % d != 0) return -1; // 无解
		
		x = mod(qmul(x, C/d, B/d), B/d); // 更新为 == C的x答案同时保证最小非负整数(其实可以不用, 只要取mod变小就好了)
		// x = x * C/d % (B/d); // 更新为 == C的x答案
    // x = mod(x*C/d, B/d); 保证最小非负整数(其实可以不用, 只要取mod变小就好了)
		R += x * M; // 更新R
		M *= B/d; // 更新M, 乘倍数即可 
		R = (R % M + M) % M;
	}
	return (R % M + M) % M;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%lld%lld", &m[i], &r[i]);
	
	printf("%lld\n", ex_crt());
	
	return 0;
}
/*
x = R(mod M)
x = ri(mod mi)
*/